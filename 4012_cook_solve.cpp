#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int map[16][16];
int visited[16];
int N;
int minV = 9999;
vector<pair<int,int>> a, b;

int solve() {
	int sum1 = 0;
	int sum2 = 0;
	a.clear();
	b.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] == 1 && visited[j] == 1) {
				if (i == j)
					continue;
				else {
					a.push_back(make_pair(i, j));
				}
			}
			else if (visited[i] == 0 && visited[j]==0) {
				if (i == j)
					continue;
				else {
					b.push_back(make_pair(i, j));
				}
			}
		}

		/*if (visited[i] == 1) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}*/
	}

	for (int i = 0; i < a.size(); i++) {
		int from = a[i].first;
		int to = a[i].second;
		sum1 += map[from][to];

		int from2 = b[i].first;
		int to2 = b[i].second;
		sum2 += map[from2][to2];
	}
	

	

	

	int ans = 0;
	ans = abs(sum1 - sum2);

	return ans;
}

void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		int ans = solve();
		minV = min(ans, minV);
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {

	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		a.clear();
		b.clear();
		minV = 9999;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		dfs(0, 0);

		cout << "#" << t << " " << minV << endl;

	}

	return 0;
}
