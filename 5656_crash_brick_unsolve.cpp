#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, W, H;
int map[15][12];
int maxV = 0;

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


	for (int i = 0; i < tv.size(); i++) {

	}
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
		maxV = 0;
		vector<int> v;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		dfs(v, 0);
		

	}

	return 0;
}
