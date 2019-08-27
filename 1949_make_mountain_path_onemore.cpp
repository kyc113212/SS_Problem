#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int y, x;
	int cnt;
	int cut;
	pos(int a, int b, int c, int d) : y(a), x(b), cnt(c), cut(d) {}
};

int N, K;
int map[8][8];
int visited[8][8];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;
vector<pos> v;



void copy_map(int map[9][9], int temp_map[9][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
}

void solve(int cy, int cx, int cnt, int cut, int cut_height) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1)
			continue;

		if (map[ny][nx] >= map[cy][cx]) {	//이동하는 곳이 높은경우
			if (cut == 0) {	//그리고 한번도 안자른 경우
				if (map[ny][nx] - cut_height < map[cy][cx]) {
					visited[ny][nx] = 1;
					map[ny][nx] = map[ny][nx] - cut_height;
					solve(ny, nx, cnt + 1, cut + 1, cut_height);
					map[ny][nx] = map[ny][nx] + cut_height;
					visited[ny][nx] = 0;
				}
			}
		}
		else {
			visited[ny][nx] = 1;
			solve(ny, nx, cnt + 1, cut, cut_height);
			visited[ny][nx] = 0;
		}

	}
}

//void difs


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> N >> K;
		memset(map, 0, sizeof(map));
		int top = 0;
		ans = 0;
		v.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				top = max(top, map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == top) {
					v.push_back(pos(i, j, 0, 1));
				}
			}
		}

		int origin_K = K;
		for (int i = 0; i < v.size(); i++) {
			for (int j = origin_K; j > 0; j--) {
				memset(visited, 0, sizeof(visited));
				visited[v[i].y][v[i].x] = 1;
				solve(v[i].y, v[i].x, 1, 0, j);
				//visited[v[i].y][v[i].x] = 0;
			}
		}


		cout << "#" << tc << " " << ans << endl;

	}


	return 0;
}
