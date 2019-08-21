#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];
int visited[101];

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int flag = 0;
		memset(map, 0, sizeof(map));
		queue<int> q;
		int maxV = -9999;
		int T, N;
		cin >> T >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
			//maxV = max(maxV, b);
			if (a == 0) {
				visited[a] = 0;
				q.push(b);
			}
		}

		while (!q.empty()) {
			int temp_v = q.front();
			if (temp_v == 99) {
				flag = 1;
				break;
			}
			
			for (int i = 0; i < 99; i++) {
				for (int j = 0; j < 99; j++) {
					if (map[i][j] == 1) {
						if (!visited[j]) {
							q.push(j);
						}
					}
				}
			}
			
		}


		cout << "#" << tc << " " << flag << endl;
	}

	return 0;
}
