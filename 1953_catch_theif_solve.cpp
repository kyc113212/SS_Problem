#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, R, C, L;
int map[51][51];
int visited[51][51];

struct pos {
	int y, x, dir;
	int cnt;
	pos(int a, int b, int c, int d) : y(a), x(b), dir(c), cnt(d) {}
};
//북,동,남,서
int d[][4] = { {0,0,0,0}, { 1,1,1,1 }, { 1,0,1,0 } , { 0,1,0,1 }, { 1,1,0,0 }, { 0,1,1,0 }, { 0,0,1,1,}, { 1,0,0,1 } };

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> R >> C >> L;
		queue<pos> q;
		int ans = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}

		/*for (int i = 1; i <= 7; i++) {
			if (map[R][C] == i) {
				q.push(pos(R, C, map));
				visited[R][C] = 1;
				/*for (int j = 0; j < 4; j++) {
					if (d[map[R][C]][j] == 1) {
						q.push(pos(R, C, j));
						visited[R][C] = 1;
					}
				}
			}
		}*/

		q.push(pos(R, C, map[R][C],1));
		visited[R][C] = 1;

		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int c_dir = q.front().dir;
			int c_cnt = q.front().cnt;
			q.pop();

			if (c_cnt >= L)
				break;

			int nx = 0;// cx + dx[c_dir];
			int ny = 0;// cy + dx[c_dir];
			
			for (int i = 0; i < 4; i++) {
				if (d[c_dir][i] == 1) {	//현재 방향을 가지고 있는것
					if (i == 0) {
						nx = cx + dx[i];
						ny = cy + dy[i];
						if (ny < 0 || nx < 0 || nx >= M || ny >= N)
							continue;
						if (visited[ny][nx] == 1)
							continue;
						if (d[map[ny][nx]][2] == 1) {
							visited[ny][nx] = 1;
							q.push(pos(ny, nx, map[ny][nx],c_cnt+1));
						}
					}
					if (i == 1) {
						nx = cx + dx[i];
						ny = cy + dy[i];
						if (ny < 0 || nx < 0 || nx >= M || ny >= N)
							continue;
						if (visited[ny][nx] == 1)
							continue;
						if (d[map[ny][nx]][3] == 1) {
							visited[ny][nx] = 1;
							q.push(pos(ny, nx, map[ny][nx], c_cnt + 1));
						}
					}
					if (i == 2) {
						nx = cx + dx[i];
						ny = cy + dy[i];
						if (ny < 0 || nx < 0 || nx >= M || ny >= N)
							continue;
						if (visited[ny][nx] == 1)
							continue;
						if (d[map[ny][nx]][0] == 1) {
							visited[ny][nx] = 1;
							q.push(pos(ny, nx, map[ny][nx], c_cnt + 1));
						}
					}
					if (i == 3) {
						nx = cx + dx[i];
						ny = cy + dy[i];
						if (ny < 0 || nx < 0 || nx >= M || ny >= N)
							continue;
						if (visited[ny][nx] == 1)
							continue;
						if (d[map[ny][nx]][1] == 1) {
							visited[ny][nx] = 1;
							q.push(pos(ny, nx, map[ny][nx], c_cnt + 1));
						}
					}
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 1)
					ans++;
			}
		}

		cout << "#" << tc << " " << ans << endl;


	}


	return 0;
}
