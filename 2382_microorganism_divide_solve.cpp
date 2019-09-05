#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

int N, M, K;
int map_origin[101][101];
int map_dir[101][101];
int map_sum[101][101];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };

struct value {
	int cnt;
	int dir;
	value(int c, int d) : cnt(c), dir(d) {}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> N >> M >> K;
		memset(map_origin, 0, sizeof(map_origin));
		memset(map_dir, 0, sizeof(map_dir));
		memset(map_sum, 0, sizeof(map_sum));
		vector<value> vector_map[101];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				vector_map[i].push_back(value(0, 0));
			}
		}

		for (int i = 0; i < K; i++) {
			int r, c, n, d;
			cin >> r >> c >> n >> d;
			vector_map[r][c].cnt = n;
			vector_map[r][c].dir = d;
		}

		for (int i = 0; i < M; i++) {
			memset(map_dir, 0, sizeof(map_dir));
			memset(map_sum, 0, sizeof(map_sum));
			memset(map_origin, 0, sizeof(map_origin));
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (vector_map[j][k].cnt != 0) {
						int c_y = j;
						int c_x = k;
						int c_cnt = vector_map[j][k].cnt;
						int c_dir = vector_map[j][k].dir;

						int ny = c_y + dy[c_dir];
						int nx = c_x + dx[c_dir];

						if (ny == N - 1 || nx == N - 1 || ny == 0 || nx == 0) {
							if (c_dir == 1)
								c_dir = 2;
							else if (c_dir == 2)
								c_dir = 1;
							else if (c_dir == 3)
								c_dir = 4;
							else if (c_dir == 4)
								c_dir = 3;
							c_cnt = c_cnt / 2;
						}

						if (map_origin[ny][nx] == 0) {
							map_origin[ny][nx] = c_cnt;
							map_sum[ny][nx] = c_cnt;
							map_dir[ny][nx] = c_dir;
						}
						else if (map_origin[ny][nx] != 0) {	//이동한것이 겹치는 경우
							if (c_cnt < map_origin[ny][nx]) {	//이동한것에 값이 더 큰경우
								map_sum[ny][nx] += c_cnt;
							}
							else if (c_cnt > map_origin[ny][nx]) {
								map_origin[ny][nx] = c_cnt;
								map_dir[ny][nx] = c_dir;
								map_sum[ny][nx] += c_cnt;
							}
						}

												

					}
				}		

			}

			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					vector_map[j][k].cnt = 0;
					vector_map[j][k].dir = 0;
				}
			}

			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (map_sum[j][k] != 0) {
						vector_map[j][k].cnt = map_sum[j][k];
						vector_map[j][k].dir = map_dir[j][k];
					}
				}
			}


		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (vector_map[i][j].cnt != 0) {
					ans += vector_map[i][j].cnt;
				}
			}
		}

		cout << "#" << tc << " " << ans << endl;
			
	}



	return 0;
}
