#include "DisjSets.h"
#include <iostream>
using namespace std;

Disj::Disj(int n) : size(n), p(n*n), rank(n*n) {
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

//void Disj::dfs(int s, int visit[][size]);
void Disj::print() {
	//int visit[size][size];
	//for (int i = 0; i < SIZE; i++) {
		//dfs(i, visit);
	//}
	/*for (int num = 1; num < p.size(); num++) {
		//if (num - N >= 0) {
		//}	0
		if (num % N < N - 1) { 
			if (find(num - 1) == find(num))
				;
		}
		if (num + N < SIZE) {		
		}
		//if (num % N > 0) {
		//} 3
	}*/
}