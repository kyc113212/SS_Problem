#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int map[21][21];

int main() {

	int tc;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;

	for (int t = 0; t < tc; t++) {

		int ans = 0;
		int N, X;
		int cnt = 0;
		bool flag = false;
		cin >> N >> X;
		memset(map, 0, sizeof(map));
		//현재시점보다 큰경우(이전값들 마이너스해서찾는다)
		//현재시점보다 작은경우(다음값 플러스해서 찾는다)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			flag = false;
			for (int j = 0; j < N - 1; j++) {
				if (map[i][j] != map[i][j + 1]) {
					if (abs(map[i][j] - map[i][j + 1]) >= 2)
						flag = true;
					else if (map[i][j] - map[i][j + 1] > 0) { //이전에 있던 값이 더 큰경우 -> 다음값 탐색
						for (int k = j + 1; k < j+1 + X; k++) {
							//if(map[i][k] != )
							if (k >= N)
								flag = true;
							else if (map[i][k] != map[i][j + 1]) {
								flag = true;
							}
						}
					}
					else if (map[i][j] - map[i][j + 1] < 0) { //올라가는경우 이전값 탐색

					}
				}
			}
			if (flag == false) {
				cnt++;
			}
		}

		//j쪽 구문을 while문으로 돌리는것도 확인
			
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[j][i];
			}
		}

		cout << "#" << t + 1 << " " << ans << endl;
	}

	return 0;
}
