#include <iostream>
#include "disjsets.h"
#include <ctime>
#include <cassert>
#include <cstdlib>
using namespace std;

const int WIDTH = 5;
const int HEIGHT = 5;
const int SIZE = WIDTH*HEIGHT;

/*
	|0 |1 |2 |3 |4 |
	|5 |6 |7 |8 |9 |
	|  |  |  |  |  |
	|  |  |  |  |  |
	|  |  |  |  |24|

	walls
	   0
	 3   1
	   2
*/
struct wall {
	bool deleted;
	int pos;
	int x;
	int y;
	wall() : deleted(false) {}
};

wall deleted[40];
void print();
bool is_deleted(int x, int y, int pos);
bool check(Disj & lab);
void unite(Disj & lab, int x, int y, int pos, int grap[][WIDTH]);
int main(int argc, char **argv) {
	srand((unsigned)time(NULL));// randomize
	Disj lab(SIZE); 
	int grap[HEIGHT][WIDTH];
	int visited[HEIGHT][WIDTH];
	int p = 0;
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++) {
			grap[i][j] = p;
			visited[i][j] = 0;
			p++;
		}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << grap[i][j] << " ";
		}
		cout << endl;
	}
	int i = 0;
	while (1) {
		if (check(lab)) {
			//print();
			cout << "success" << endl;
			break;
		}
		int m = rand() % HEIGHT;
		int n = rand() % WIDTH;
		int pos = rand() % 4;
		if (is_deleted(m, n, pos)) {
			continue;
		}
		else {
			deleted[i].x = m;
			deleted[i].y = n;
			deleted[i].deleted = true;
			i++;
			visited[m][n]++;/*
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					cout << visited[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;*/
			//cout << "find : " << lab.find(0) << endl;
		}
		//выбрали стену
		//приступаем к уничтожении т.е слияния ячеек
		unite(lab, m, n, pos, grap);
	}
	getchar();
	return 0;
}

bool check(Disj & lab) {
	if (lab.find(0) == lab.find(24))
		return true;
	return false;
}

void unite(Disj & lab, int x, int y, int pos, int grap[][WIDTH]) {
	
	switch (pos) {
	case 0:
		if (x - 1 >= 0) {
			//cout << "unite : " << grap[x - 1][y] << " " << grap[x][y] << endl;
			lab.unite(grap[x - 1][y], grap[x][y]);
		}
		break;
	case 1:
		if (y + 1 < WIDTH) {
			//cout << "unite : " << grap[x][y+1] << " " << grap[x][y] << endl;
			lab.unite(grap[x][y + 1], grap[x][y]);
		}
		break;
	case 2:
		if (x + 1 < HEIGHT) {
			//cout << "unite : " << grap[x + 1][y] << " " << grap[x][y] << endl;
			lab.unite(grap[x + 1][y], grap[x][y]);
		}
		break;
	case 3:
		if (y - 1 >= 0) {
			//cout << "unite : " << grap[x][y - 1] << " " << grap[x][y] << endl;
			lab.unite(grap[x][y - 1], grap[x][y]);
		}
		break;
	}
}

bool is_deleted(int x, int y, int pos) {
	for (int i = 0; i < 40; i++)
		if (deleted[i].x == x && deleted[i].y == y && deleted[i].deleted)
			return true;
	return false;
}
/*for(int i = 0; i < HEIGHT; i++)
		for(int j = 0; j < WIDTH; j++)
			if (grap[i][j] == x) {
				x = i;
				y = j;
				break;
				}
				*/