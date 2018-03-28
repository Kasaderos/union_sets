#ifndef _DISJSETS_H
#define _DISJSETS_H

#include <vector>
using namespace std;

class Disj {
public:
	explicit Disj(int n);
	int find(int x);
	void unite(int x, int y);
	void make_set(int x);
private:
	vector<int> p;
	vector<int> rank;
};

#endif