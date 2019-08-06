#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct item {
	int index, group;
	item(int a, int b) : index(a), group(b) {}
};  



void select_group(vector<item> &tv,int idx, int t_cnt, int group_cnt) {
	if (idx == 2) {

	}
	
	for (int i = idx; i < t_cnt; i++) {

	}
}

int main() {
	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int map[17][17];
		int minV = -9999;
		vector<item> v;
		v.clear();
		memset(map, 0, sizeof(map));
		int N;
		int ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			select_group(v, i, N, 0);
		}



		cout << "#" << t << " " << ans << endl;
	}
	
	return 0;
}
