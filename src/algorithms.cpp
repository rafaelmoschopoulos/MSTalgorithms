#include <queue>
#include <vector>
#include <tuple>
#include <chrono>
#include <random>
#include <algorithm>
#include "unionfind.h"
#include "algorithms.h"

EdgeList kruskals(EdgeList& edges, int nNodes, long long& runtime)
{
	const auto start = std::chrono::high_resolution_clock::now();
	UnionFind uf(nNodes);
	std::sort(edges.begin(), edges.end(),
		[](auto x, auto y) {return std::get<2>(x) < std::get<2>(y); });
	EdgeList mst_edges;
	for(const auto& e : edges)
	{
		int a, b, w;
		std::tie(a, b, w) = e;
		if (!uf.same(a, b)) {
			uf.unite(a, b);
			mst_edges.emplace_back(a, b, w);
		}
	}
	const auto stop = std::chrono::high_resolution_clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	runtime = duration.count();
	return mst_edges;
}


EdgeList prims_bin(EdgeList& edges, int nNodes, long long& runtime) {
	AdjList adjList(nNodes+1);
	EdgeList mst_edges(nNodes-1);
	size_t mst_edges_idx = 0;

	for (const auto& e : edges)
	{
		adjList[std::get<0>(e)].emplace_back(std::get<1>(e), std::get<2>(e));
		adjList[std::get<1>(e)].emplace_back(std::get<0>(e), std::get<2>(e));
	}
	const auto start = std::chrono::high_resolution_clock::now();
	std::vector<bool> visited(nNodes+1, false);
	std::vector<int> key(nNodes+1, std::numeric_limits<int>::max());
	std::vector<int> parent(nNodes+1);

	std::priority_queue<std::pair<int, int>> q;
	q.push({ 0, 1 });

	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();
		if(visited[a]) continue;
		visited[a] = true;
		for (const auto& u : adjList[a])
		{
			int b = u.first, w = u.second;
			if (!visited[b]  && key[b] > w)
			{
				key[b] = w;
				parent[b] = a;
				q.push({ -w, b });
			}
		}
	}


	for (int i = 2; i <= nNodes; i++)
	{
		mst_edges[mst_edges_idx++]={parent[i], i, key[i]};
	}

	const auto stop = std::chrono::high_resolution_clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	runtime = duration.count();
	return mst_edges;
}

EdgeList boruvkas(EdgeList& edges, int nNodes, long long& runtime)
{
	UnionFind uf(nNodes);
	EdgeList cheapest(nNodes+1, {-1, -1, std::numeric_limits<int>::max()}); // cheapest[i] is the edge with the least weight that goes out of component i
	EdgeList mst_edges(nNodes-1);
	size_t mst_edges_idx = 0;
	int compCount = nNodes;
	int totalW = 0;
	const auto start = std::chrono::high_resolution_clock::now();
	while (compCount > 1)
	{
		for(const auto& e : edges) // For each edge, check if it is the lightest one that can expand any of the components
		{
			int u, v, w;
			std::tie(u, v, w) = e;
			auto set1 = uf.find(u);
			auto set2 = uf.find(v);
			if (set1 == set2) continue; // If the vertices of the current edge belong to the same component, we don't care
			if(std::get<2>(cheapest[set1]) > w) // If the weight of the current edge is less than the weight of cheapest[set], replace the edge with the current edge
			{
				cheapest[set1] = { u, v, w };
			}
			if(std::get<2>(cheapest[set2]) > w)
			{
				cheapest[set2] = { u, v, w };
			}
		}
		for(int i = 1; i <= nNodes; i++) {
			auto& e = cheapest[i];
			if (std::get<2>(e) != std::numeric_limits<int>::max()) // If it corresponds to any set
			{
				int u, v, w;
				std::tie(u, v, w) = e;
				auto set1 = uf.find(u); // Find whether its two vertices belong to different components
				auto set2 = uf.find(v);
				if (set1 != set2)
				{
					totalW += w; // If yes, add the edge to the MST
					uf.unite(set1, set2);
					mst_edges[mst_edges_idx++] = e;
					compCount--;
				}
			}
		}
		std::fill(cheapest.begin(), cheapest.end(), std::make_tuple(-1, -1, std::numeric_limits<int>::max() ));
	}
	const auto stop = std::chrono::high_resolution_clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	runtime = duration.count();

	return mst_edges;
}
