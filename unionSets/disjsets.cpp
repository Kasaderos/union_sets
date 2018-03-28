#include "DisjSets.h"

Disj::Disj(int n) : p(n), rank(n) {
	for (int i = 0; i < p.size(); i++) {
		p[i] = i;
		rank[i] = 0;
	}
}

void Disj::make_set(int x) {
	p[x] = x;
}

void Disj::unite(int x, int y) { // в случае если ранг(x) >= ранг(y) -> y предок
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rank[x] < rank[y])
		p[x] = y;
	else
	{
		p[y] = x;
		if (rank[x] == rank[y])
			++rank[x];
	}
}

int Disj::find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}