#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "graphutils.h"



long long findMSTWeight(const EdgeList& edges)
{
	long long totalW{0};
	for(const auto& e : edges)
	{
		totalW += std::get<2>(e);
	}
	return totalW;
}

EdgeList randomGraph(long long ne, int nv, long long& runtime, int MAX_WEIGHT)
{
	if (ne < static_cast<long long>(nv) - 1 || ne > static_cast<long long>(nv) * (static_cast<long long>(nv) - 1) / 2) // Min # of edges is # of vertices - 1 (tree). Max is nv(nv-1)/2
	{
		throw std::runtime_error("Impossible number of edges/vertices.");
	}
	const auto start = std::chrono::high_resolution_clock::now();

	EdgeList treeEdges;

	std::vector adjMat(nv+1, std::vector(nv+1, 0));

	std::vector<int> used_v;

	std::random_device rd;
	std::seed_seq sd{ rd(), rd(), rd(), rd() };
	std::mt19937 gen(sd);
	std::uniform_int_distribution<> distrib(1, MAX_WEIGHT);
	std::vector<int> unused_v;
	for (int i = 1; i <= nv; i++) unused_v.push_back(i);
	std::shuffle(unused_v.begin(), unused_v.end(), gen);

	used_v.push_back(unused_v.back());
	unused_v.pop_back();

	while (treeEdges.size() < nv - 1)
	{
		int u = used_v[gen() % used_v.size()];
		int v = unused_v.back();
		unused_v.pop_back();
		used_v.push_back(v);
		treeEdges.push_back({ u, v, distrib(gen)});
		adjMat[u][v] = adjMat[v][u] = 1;
	}

	while(treeEdges.size() < ne)
	{
		int u = gen() % nv + 1;
		int v = gen() % nv + 1;
		while (u == v)
			v = gen() % nv + 1;
		if (adjMat[u][v] == 0 && adjMat[v][u] == 0) {
			treeEdges.push_back({ u, v, distrib(gen)});
			adjMat[u][v] = adjMat[v][u] = 1;
		}
	}
	const auto stop = std::chrono::high_resolution_clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	runtime = duration.count();
	return treeEdges;
}
