#ifndef _DISJSETS_H
#define _DISJSETS_H

#include <vector>
using namespace std;

class Disj {
public:
	explicit Disj(int size);
	int find(int x);
	void print();
	//void dfs(int s, int visit[][]);
	void unite(int x, int y);
	void make_set(int x);
private:
	int size;
	vector<int> p;
	vector<int> rank;
};

#endif