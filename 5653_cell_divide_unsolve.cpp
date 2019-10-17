#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define VALUE 400
#define HALF_VALUE 150

int N, M, K;
int map[VALUE][VALUE];
int temp_map[VALUE][VALUE];
int remain_time[VALUE][VALUE];
int last_remain_time[VALUE][VALUE];
int inactive[VALUE][VALUE];
int active[VALUE][VALUE];
int visited[VALUE][VALUE];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct pos {
	int y, x, time;
	pos(int a, int b, int c) : y(a), x(b), time(c) {}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		memset(map, 0, sizeof(map));
		memset(remain_time, 0, sizeof(remain_time));
		memset(inactive, 0, sizeof(inactive));
		memset(active, 0, sizeof(active));
		memset(temp_map, 0, sizeof(temp_map));
		for (int i = HALF_VALUE; i < N + HALF_VALUE; i++) {
			for (int j = HALF_VALUE; j < M + HALF_VALUE; j++) {
				cin >> map[i][j];
				remain_time[i][j] = map[i][j];
				temp_map[i][j] = map[i][j];
			}
		}

		int time = 0;

		queue<pos> q;
		queue<pos> temp_q;
		while (time<=K) {			

			memset(visited, 0, sizeof(visited));
			while (!q.empty()) {
				int cx = q.front().x;
				int cy = q.front().y;
				int ctime = q.front().time;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx < 0 || ny < 0 || nx >= VALUE || ny >= VALUE)
						continue;
					if (map[ny][nx] == 0) {
						visited[ny][nx] = 1;
						map[ny][nx] = ctime;
						remain_time[ny][nx] = ctime;
						temp_map[ny][nx] = ctime;
					}
					if (visited[ny][nx] == 1 && map[ny][nx] < ctime && map[ny][nx] != 0) {
						map[ny][nx] = ctime;
						remain_time[ny][nx] = ctime;
						temp_map[ny][nx] = ctime;
					}
				}
			}
			

			int temp_q_size = temp_q.size();
			for (int i = 0; i < temp_q_size; i++) {
				int cx = temp_q.front().x;
				int cy = temp_q.front().y;
				int c_time = temp_q.front().time;
				temp_q.pop();
				c_time--;
				if (c_time == 0) {
					temp_map[cy][cx] = 0;
				}
				else if (c_time > 0) {
					temp_q.push(pos(cy, cx, c_time));
				}
			}
				
			for (int i = 0; i < VALUE; i++) {
				for (int j = 0; j < VALUE; j++) {
					if (active[i][j] == 1 && inactive[i][j] == 0) {
						q.push(pos(i, j, map[i][j]));
						temp_q.push(pos(i, j, map[i][j]));
						inactive[i][j] = 1;
						active[i][j] = 0;
					}
				}
			}


			for (int i = 0; i < VALUE; i++) {
				for (int j = 0; j < VALUE; j++) {
					if (remain_time[i][j] > 0) {
						remain_time[i][j]--;
						if (remain_time[i][j] == 0) {
							active[i][j] = 1;
						}
					}
				}
			}
			time++;

		}

		int ans = 0;
		for (int i = 0; i < VALUE; i++) {
			for (int j = 0; j < VALUE; j++) {
				if (temp_map[i][j] != 0 )
					ans++;
			}
		}

		cout << "#" << tc << " " << ans << endl;

	}

	return 0;
}
