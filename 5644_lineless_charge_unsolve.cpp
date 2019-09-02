#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { 0,0,1,0,-1 };
int dy[] = { 0,-1,0,1,0 };

int visited[8][11][11];
int sum_visited[11][11];
int map[8][11][11];
int path_A[101];
int path_B[101];
int sumA[101];
int sumB[101];

struct pos {
	int x, y,round, C;
	pos(int a, int b, int d, int c) : x(a), y(b), round(d), C(c) {}
};

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(map, 0, sizeof(map));
		memset(path_A, 0, sizeof(path_A));
		memset(path_B, 0, sizeof(path_B));
		memset(sumA, 0, sizeof(sumA));
		memset(sumB, 0, sizeof(sumB));
		memset(sum_visited, 0, sizeof(sum_visited));
		memset(visited, 0, sizeof(visited));
		int M, A;
		vector<pos> v;

		cin >> M >> A;
		
		for (int i = 0; i < M; i++) {
			cin >> path_A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> path_B[i];
		}

		for (int i = 0; i < A; i++) {
			int x, y, round, C;
			cin >> x >> y >> round >> C;
			v.push_back(pos(x - 1, y - 1, round, C));
		}

		
		for (int i = 0; i < A; i++) {
			queue <pos> q;
			int temp_round = v[i].round;
			q.push(pos(v[i].x, v[i].y, 0 ,v[i].C));
			visited[i][v[i].y][v[i].x] = 1;
			map[i][v[i].y][v[i].x] = v[i].C;
			while (!q.empty()) {
				int cx = q.front().x;
				int cy = q.front().y;
				int cC = q.front().C;
				int c_around = q.front().round;
				q.pop();
				if (c_around >= temp_round)
					break;
				for (int j = 1; j < 5; j++) {
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10)
						continue;
					if (visited[i][ny][nx] == 0) {
						visited[i][ny][nx] = 1;
						map[i][ny][nx] = cC;
						q.push(pos(nx, ny, c_around + 1, cC));
					}
				}
			}
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					sum_visited[j][k] += visited[i][j][k];
				}
			}
		}
		int ax = 0;
		int ay = 0;
		int bx = 9;
		int by = 9;
		int sumA = 0;
		int sumB = 0;
		int va[101] = { 0, };
		int vb[101] = { 0, };
		for (int i = 0; i < A; i++) {
			if (visited[i][ay][ax]) {
				sumA = max(sumA, map[i][ay][ax]);
			}
			if (visited[i][by][bx]) {
				sumB = max(sumA, map[i][by][bx]);
			}
		}
		va[0] = sumA;
		vb[0] = sumB;
		for (int m = 0; m < M; m++) {
			ax += dx[path_A[m]];
			ay += dy[path_A[m]];
			bx += dx[path_B[m]];
			by += dy[path_B[m]];
			int tempA = 0;
			int Aidx = 0;
			int tempB = 0;
			int Bidx = 0;
			/*for (int i = 0; i < A; i++) {
				if (tempA < map[i][ay][ax]) {
					tempA = map[i][ay][ax];
					Aidx = i;
				}
				if (tempB < map[i][by][bx]) {
					tempB = map[i][by][bx];
					Bidx = i;
				}
			}*/

			int temp_sum = 0;
			for (int u = 0; u < A; u++) {
				for (int w = 0; w < A; w++) {
					if (temp_sum < map[u][ay][ax] + map[w][by][bx]) {
						if (u != w) {
							temp_sum = map[u][ay][ax] + map[w][by][bx];
							Aidx = u;
							Bidx = w;
							tempA = map[u][ay][ax];
							tempB = map[w][by][bx];
						}
					}
				}
			}


			if (Aidx == Bidx && tempB != 0 && tempA != 0) {
				if (sum_visited[by][bx] > 1 || sum_visited[ay][ax] > 1) {
					if (sum_visited[by][bx] > 1) {
						tempB = 0;
						for (int j = 0; j < A; j++) {
							if (j == Bidx)
								continue;
							tempB = max(tempB, map[j][by][bx]);
						}
					}
					else if (sum_visited[ay][ax] > 1) {
						tempA = 0;
						for (int j = 0; j < A; j++) {
							if (j == Aidx)
								continue;
							tempA = max(tempA, map[j][ay][ax]);
						}
					}						//같은 구역에 있지만 겹쳐있는경우
				}
				else if (sum_visited[by][bx] == 1 || sum_visited[ay][ax] == 1) {
					tempA = tempA / 2;
					tempB = tempB / 2;
				}
			}


			va[m + 1] = tempA;
			vb[m + 1] = tempB;

			sumA += tempA;
			sumB += tempB;
		}

		cout << "#" << tc << " " << sumA + sumB << endl;

	}

	return 0;
}
