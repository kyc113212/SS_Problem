#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[25][25];
int visited[25][25];
int desert[101];
int N;
int sx, sy;
int maxV = 0;
int temp = 0;

int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,-1,1 };

void dfs(int y, int x, int cnt, int cur_dir, int dir_cnt) {

	if (dir_cnt > 4)
		return;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny == sy && nx == sx && cnt >= 3 && dir_cnt >= 3) {
			maxV = max(maxV, cnt);
			return;
		}
		if (ny >= N || nx >= N || ny < 0 || nx < 0)
			continue;
		if (visited[ny][nx])
			continue;
		if (desert[map[ny][nx]])
			continue;
		
		desert[map[ny][nx]] = 1;
		visited[ny][nx] = 1;
		if (i == cur_dir) {
			dfs(ny, nx, cnt + 1, i, dir_cnt);
		}
		else {
			dfs(ny, nx, cnt + 1, i, dir_cnt + 1);
		}
		desert[map[ny][nx]] = 0;
		visited[ny][nx] = 0;
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> N;
		maxV = 0;
		temp = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sx = j;
				sy = i;
				temp = 0;
				visited[i][j] = 1;
				desert[map[i][j]] = 1;
				dfs(i, j, 1, -1, 0);
				visited[i][j] = 0;
				desert[map[i][j]] = 0;

			}
		}

		if (maxV == 0) {
			cout << "#" << tc << " " << -1 << endl;
		}
		else
			cout << "#" << tc << " " << maxV << endl;

	}

	

	return 0;
}
