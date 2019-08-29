#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, R, C, L;
int map[51][51];
int visted[51][51];

struct pos {
	int y, x, dir;
	pos(int a, int b, int c) : y(a), x(b), dir(c) {}
};
//북,동,남,서
int d[][4] = { {0,0,0,0}, { 1,1,1,1 }, { 1,0,1,0 } , { 0,1,0,1 }, { 1,1,0,0 }, { 0,1,1,0 }, { 0,0,1,1,}, { 1,0,0,1 } };

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> R >> C >> L;
		queue<pos> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int i = 1; i <= 7; i++) {
			if (map[R][C] == i) {
				for (int j = 0; j < 4; j++) {
					q.push(pos(R, C, j));
				}
			}
		}
		
	}

	return 0;
}
