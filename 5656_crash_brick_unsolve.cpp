#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, W, H;
int map[15][12];
int minV = 9999;
int dx[] = { -1,1,0, 0 };
int dy[] = { 0,0,1,-1 };

struct pos {
	int x, y, depth;
	pos(int a, int b, int c) : y(a), x(b), depth(c) {}
};

void copy_map(int origin[][12], int copy[][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

bool zero_map(int temp[][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (temp[i][j] != 0)
				return false;
		}
	}
	return true;
}

int check_map(int arr[][12]) {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] != 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void rearrange_map(int temp_map[][12]) {
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 1; j--) {
			if (temp_map[j][i] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (temp_map[k][i] != 0) {
						temp_map[j][i] = temp_map[k][i];
						temp_map[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void solve(vector<int> &tv) {

	int temp_map[15][12];
	memset(temp_map, 0, sizeof(temp_map));
	copy_map(map, temp_map);

	
	for (int i = 0; i < tv.size(); i++) {

		int start_col = tv[i];
		queue<pos> q;

		for (int j = 0; j < H; j++) {
			if (temp_map[j][start_col] != 0) {
				q.push(pos(j, start_col, temp_map[j][start_col]));
				break;
			}
		}

		while (!q.empty()) {
			int c_x = q.front().x;
			int c_y = q.front().y;
			int c_depth = q.front().depth;
			q.pop();
			if (c_depth == 1) {
				temp_map[c_y][c_x] = 0;
				continue;
			}
			else {
				temp_map[c_y][c_x] = 0;
				for (int j = 0; j < 4; j++) {
					int nx = c_x;
					int ny = c_y;
					for (int k = 0; k < c_depth - 1; k++) {
						nx = nx + dx[j];
						ny = ny + dy[j];
						if (nx < 0 || ny < 0 || nx >= W || ny >= H)
							continue;
						if (temp_map[ny][nx] != 0) {
							if (temp_map[ny][nx] == 1) {
								temp_map[ny][nx] = 0;
								continue;
							}
							else {
								q.push(pos(ny, nx, temp_map[ny][nx]));
								temp_map[ny][nx] = 0;
							}
						}
					}
				}
			}
		}

		rearrange_map(temp_map);

	}

	int ans = check_map(temp_map);
	minV = min(minV, ans);
}


void dfs(vector<int> &tv, int cnt) {
	if (cnt == N) {
		solve(tv);
		return;
	}
	for (int i = 0; i < W; i++) {
		tv.push_back(i);
		dfs(tv, cnt + 1);
		tv.pop_back();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> W >> H;
		memset(map, 0, sizeof(map));
		minV = 9999;
		vector<int> v;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		dfs(v, 0);

		cout << "#" << tc << " " << minV << endl;

	}

	return 0;
}
