#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int schedule[16];
int visited[16];
int day[4];
int minV = 9999;

bool check_day(int temp_s[16], int idx) {
	for (int i = idx + 1; i < 12; i++) {
		if (temp_s[i] != 0) {
			return false;
		}
	}
	return true;
}

bool check_visited() {
	for (int i = 0; i < 12; i++) {
		if (schedule[i] != 0) {
			if (visited[i] == 0) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int idx, int sumV, int term) {
	if (idx > 12) {
		if (check_day(schedule, idx) == true) {
			if (check_visited() == true) {
				minV = min(sumV, minV);
				return;
			}
		}
		return;
	}
	if (check_day(schedule, idx) == true) {
		if (check_visited() == true) {
			minV = min(sumV, minV);
			return;
		}
	}

	
	for (int k = idx; k < 12; k++) {
		for (int i = 0; i < 3; i++) {
			if (schedule[k] != 0 && visited[k] == 0) {
				if (i == 0) {
					visited[k] = 1;
					int value = 0;
					for (int j = 0; j < schedule[k]; j++) {
						value += day[i];
					}
					sumV += value;
					dfs(k, sumV, i);
					sumV -= value;
					visited[k] = 0;
				}
				else if (i == 1) {
					visited[k] = 1;
					sumV += day[i];
					dfs(k, sumV, i);
					sumV -= day[i];
					visited[k] = 0;
				}
				else if (i == 2) {
					for (int j = k; j < k + 3; j++) {
						if (j >= 12)
							break;
						visited[j] = 1;
					}
					sumV += day[i];
					dfs(k + 3, sumV, i);
					sumV -= day[i];
					for (int j = k; j < k + 3; j++) {
						visited[j] = 0;
					}
				}
			}
		}
		
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int ans = 0;
		int start_month = 0;
		memset(schedule, 0, sizeof(schedule));
		memset(visited, 0, sizeof(visited));
		memset(day, 0, sizeof(day));
		for (int i = 0; i < 4; i++) {
			cin >> day[i];
		}

		for (int i = 0; i < 12; i++) {
			cin >> schedule[i];
		}

		for (int i = 0; i < 12; i++) {
			if (schedule[i] != 0)
			{
				start_month = i;
				break;
			}
		}

		minV = 9999;

		for (int i = 0; i < 4; i++) {
			if (schedule[start_month] != 0 && visited[start_month] == 0) {
				//visited[i] = true;
				if (i == 0) {
					visited[start_month] = 1;
					int value = 0;
					for (int j = 0; j < schedule[start_month]; j++) {
						value += day[i];
					}
					ans += value;
					dfs(start_month, ans, i);
					ans -= value;
					visited[start_month] = 0;
				}
				else if (i == 1) {
					visited[start_month] = 1;
					ans += day[i];
					dfs(start_month, ans, i);
					ans -= day[i];
					visited[start_month] = 0;
				}
				else if (i == 2) {
					for (int j = start_month; j < start_month + 3; j++) {
						if (j >= 12)
							break;
						visited[j] = 1;
					}
					ans += day[i];
					dfs(start_month + 3, ans, i);
					ans -= day[i];
					for (int j = start_month; j < start_month + 3; j++) {
						visited[j] = 0;
					}
				}
				else if (i == 3) {
					int tempV = day[i];
					minV = min(tempV, minV);
				}
			}
		}

		cout << "#" << T << " " << minV << endl;

	}

	return 0;
}
