#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>


using namespace std;

char arr[101] = { 0 };

void dfs(int cnt) {
	if (arr[cnt] == 0)
		return;
	dfs(cnt * 2);
	cout << arr[cnt];
	dfs(cnt * 2 + 1);
}

int main() {

	//ios_base::sync_with_stdio(false); 이거쓰면 char형 값이 안나옴
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	for (int t = 1; t <= 10; t++) {
		memset(arr, 0, sizeof(arr));
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int a;
			char b;
			cin >> a >> b;
			if ((N % 2 == 0 && i < N / 2) || (N % 2 == 1 && i <= N / 2)) {
				scanf("%*d %*d");
			}
			else if ((N % 2 == 0) && (N/2 == i)) {
				scanf("%*d");
			}
			arr[a] = b;
		}
		cout << "#" << t << " ";
		dfs(1);
		cout << '\n';

	}

	return 0;
}
