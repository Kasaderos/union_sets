#include "DisjSets.h"
#include <iostream>
using namespace std;

Disj::Disj(int n) : size(n), p(n), rank(n) {
	for (unsigned i = 0; i < p.size(); i++) {
		p[i] = i;
		rank[i] = 0;
	}
	visit = new int[n];
}
Disj::~Disj() {
	delete[] visit;
}


void Disj::make_set(int x) {
	p[x] = x;
}

void Disj::unite(int x, int y) { // в случае если ранг(x) >= ранг(y) -> y предок
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	else if (rank[x] < rank[y])
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

bool Disj::find2(int x) {
	if (x == 0) return true;
	if (p[x] == x && x != 0)
		return false;
	return find2(p[x]);
}
void Disj::dfs(int v, int s) {
	for (int i = v; i < size; i++) {
		if (!visit[i] && find(i) == find(v))
			visit[i] = s;
	}
}
void Disj::print() {
	for (int i = 0; i < size; i++)
		visit[i] = 0;
	int s = 1;
	for (int i = 0; i < size; i++) {
		dfs(i, s);
		s++;
	}
	int n = (int)sqrt(size);
	for (int i = 0; i < size; i++) {
		if (i % n == 0)
			cout << endl;
		cout << " " << visit[i];
	}
}