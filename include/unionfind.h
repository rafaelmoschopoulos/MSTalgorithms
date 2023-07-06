#pragma once
class UnionFind
{
public:
	UnionFind();
	UnionFind(int nElements);

	bool same(int a, int b);
	void unite(int a, int b);
	int find(int x) const;

private:
	int* link;
	int* size;
};

