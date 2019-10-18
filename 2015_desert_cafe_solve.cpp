#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[21][21];
int visited[21][21];
int N;
int sx, sy;
int maxV = 0;
int desert[101];
int dir[4];

int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,-1,1 };

void dfs(int y, int x, int dir_cnt, int cur_dir, int cnt) {
	/*if (dir_cnt <= 4 && y == sy && x == sx && cnt > 2) {
		maxV = max(maxV, cnt);
		return;
	}*/

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		//여기서 조건 걸어서 탈출할수 있게 만듦
		if (dir_cnt <= 4 && ny == sy && nx == sx && cnt > 3) {
			maxV = max(maxV, cnt);
			return;
		}
		if (visited[ny][nx] == 1)
			continue;
		if (desert[map[ny][nx]] == 1)
			continue;
		if (i == cur_dir) {
			visited[ny][nx] = 1;
			desert[map[ny][nx]] = 1;
			dfs(ny, nx, dir_cnt, i, cnt + 1);
			desert[map[ny][nx]] = 0;
			visited[ny][nx] = 0;
		}
		if (i != cur_dir) {
			if (dir[i] == 0) {
				dir[i] = 1;
				visited[ny][nx] = 1;
				desert[map[ny][nx]] = 1;
				dfs(ny, nx, dir_cnt + 1, i, cnt + 1);
				desert[map[ny][nx]] = 0;
				visited[ny][nx] = 0;
				dir[i] = 0;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		memset(desert, 0, sizeof(desert));

		maxV = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 1;
				desert[map[i][j]] = 1;
				sx = j;
				sy = i;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N)
						continue;
					dir[k] = 1;
					dfs(i, j, 1, k, 1);
					dir[k] = 0;
				}
				visited[i][j] = 0;
				desert[map[i][j]] = 0;
			}
		}
		if (maxV == 0) {
			cout << "#" << tc << " " << -1 << endl;
		}
		else {
			cout << "#" << tc << " " << maxV << endl;
		}

	}

}
