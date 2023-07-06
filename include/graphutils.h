#pragma once
using Edge = std::tuple<int, int, int>;
using EdgeList = std::vector<Edge>;

long long findMSTWeight(const EdgeList& edges);
EdgeList randomGraph(long long ne, int nv, long long& runtime, int MAX_WEIGHT);
