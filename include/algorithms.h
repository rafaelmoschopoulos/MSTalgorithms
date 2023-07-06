#pragma once
#include <vector>
using Edge = std::tuple<int, int, int>;
using EdgeList = std::vector<Edge>;
using AdjList = std::vector<std::vector<std::pair<int, int>>>;


EdgeList kruskals(EdgeList& edges, int nNodes, long long& runtime);
EdgeList prims_bin(EdgeList& edges, int nNodes, long long& runtime);
EdgeList boruvkas(EdgeList& edges, int nNodes, long long& runtime);
