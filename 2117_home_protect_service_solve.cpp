#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct pos {
	int y, x, dist;
	pos(int a, int b, int c) : y(a), x(b), dist(c) {}
};

vector<pos> home_pos;
int map[21][21];
int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;

void solve(int y, int x) {
	int max_dist = 0;
	for (int i = 0; i < home_pos.size(); i++) {
		max_dist = max(max_dist, abs(home_pos[i].x - x) + abs(home_pos[i].y - y));
		home_pos[i].dist = abs(home_pos[i].x - x) + abs(home_pos[i].y - y);
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {

			}
		}
	}*/

	int home_count = 0;
	max_dist = max_dist + 1;

	for (int i = 1; i <= max_dist; i++) {
		home_count = 0;
		for (int j = 0; j < home_pos.size(); j++) {
			if (home_pos[j].dist < i) {
				home_count++;
			}
		}
		int operate_fee = M * home_count - i * i - (i - 1)*(i - 1);
		if (operate_fee >= 0) {
			ans = max(ans, home_count);
		}
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
		memset(map, 0, sizeof(map));
		ans = 0;
		home_pos.clear();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					home_pos.push_back(pos(i, j, 0));
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				solve(i, j);
			}
		}

		/*for (int i = 0; i < home_pos.size(); i++) {
			solve(home_pos[i].y, home_pos[i].x, i);
		}*/

		cout << "#" << tc << " " << ans << endl;

	}



	return 0;
}
