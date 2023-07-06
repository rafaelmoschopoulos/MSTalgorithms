#include "unionfind.h"
#include <algorithm>

UnionFind::UnionFind() = default;
UnionFind::UnionFind(int nElements)
{
    link = new int[nElements+1];
    size = new int[nElements+1];
    for (int i = 1; i <= nElements; i++) link[i] = i;
    for (int i = 1; i <= nElements; i++) size[i] = 1;
}
bool UnionFind::same(int a, int b)
{
    return find(a) == find(b);
}
void UnionFind::unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) std::swap(a, b); // Union by rank
    size[a] += size[b];
    link[b] = a;
}
int UnionFind::find(int x) const
{
    int u = x;
    while (u != link[u]) u = link[u];
    link[x] = u; // Path compression
    return u;
}