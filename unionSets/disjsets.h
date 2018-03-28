#ifndef _DISJSETS_H
#define _DISJSETS_H

#include <vector>
using namespace std;

class Disj {
public:
	explicit Disj(int size);
	int find(int x);
	void print();
	void dfs(int v, int s);
	bool find2(int x);
	void unite(int x, int y);
	void make_set(int x);
	~Disj();
private:
	int size;
	vector<int> p;
	int *visit;
	vector<int> rank;
};

#endif