#include <iostream>
#include "disjsets.h"
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 8;
const int SIZE = N * N;
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

bool check(Disj & lab);
void unite(Disj & lab, int num, int pos);
int main(int argc, char **argv) {
	srand((unsigned)time(NULL));// randomize
	Disj lab(SIZE);
	vector <int> v;
	int p = 0;
	for (int i = 0; i < SIZE; i++)
		v.push_back(i);
	random_shuffle(v.begin(), v.end());//генерация случайных чисел завершено
	int i = 0;
	while (1) {
		if (check(lab)) {
			cout << "success" << endl;
			break;
		}
		if (i == SIZE) i = 0;
		int pos = rand() % 4; //генерация позиции стены 
							  //выбрали стену
							  //приступаем к уничтожении
		cout << "wall pos : " << pos << " ";
		unite(lab, v[i], pos);
		i++;
	}
	lab.print();
	getchar();
	return 0;
}

bool check(Disj & lab) {
	return (lab.find(0) == lab.find(SIZE - 1));
}

void unite(Disj & lab, int num, int pos) {
	switch (pos) {
	case 0:
		if (num - N >= 0) {
			cout << "unite : " << num - N << " " << num << endl;
			lab.unite(num - N, num);
		}
		break;
	case 1:
		if (num % N < N - 1) {
			cout << "unite : " << num + 1 << " " << num << endl;
			lab.unite(num + 1, num);
		}
		break;
	case 2:
		if (num + N < SIZE) {
			cout << "unite : " << num + N << " " << num << endl;
			lab.unite(num + N, num);
		}
		break;
	case 3:
		if (num % N > 0) {
			cout << "unite : " << num - 1 << " " << num << endl;
			lab.unite(num - 1, num);
		}
		break;
	}
}