#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


struct value {
	int y, x, stair_number, move;
	value(int a, int b, int c, int d) : y(a), x(b), stair_number(c), move(d) {}
};

struct pos {
	int y, x;
	pos(int a, int b) : y(a), x(b) {}
};

int N;
int map[11][11];
int people_count;
int minV = 9999;
vector<pos> stair;
vector<pos> people;

bool check_people(vector<value> &tv) {
	for (int i = 0; i < tv.size(); i++) {
		if (tv[i].move != 0)
			return false;
	}
	return true;
}

void solve(vector<int> &t_stair) {

	queue<value> people_dist;
	queue<value> stair_count[2];
	queue<value> waiting[2];

	for (int i = 0; i < people_count; i++) {
		int dist = abs(stair[t_stair[i]].x - people[i].x) + abs(stair[t_stair[i]].y - people[i].y);
		people_dist.push(value(people[i].y, people[i].x, t_stair[i], dist));
	}

	
	int b = 0;
	int cnt = 0;
	while (1) {
		//if(check_people())
		int p_size = people_dist.size();
		int s_size0 = stair_count[0].size();
		int s_size1 = stair_count[1].size();
		for (int i = 0; i < s_size0; i++) {
			//size보고 웨이팅 넣음
			int y = stair_count[0].front().y;
			int x = stair_count[0].front().x;
			int stair_number = stair_count[0].front().stair_number;
			int move = stair_count[0].front().move;
			stair_count[0].pop();
			move--;
			
			if (move > 0) {
				stair_count[0].push(value(y, x, stair_number, move));
			}		
			if (stair_count[0].size() < 3 && !waiting[0].empty()) {
				stair_count[0].push(waiting[0].front());
				waiting[0].pop();
			}

		}

		


		for (int i = 0; i < s_size1; i++) {
			//size보고 웨이팅 넣음
			int y = stair_count[1].front().y;
			int x = stair_count[1].front().x;
			int stair_number = stair_count[1].front().stair_number;
			int move = stair_count[1].front().move;
			stair_count[1].pop();
			move--;

			if (move > 0) {
				stair_count[1].push(value(y, x, stair_number, move));
			}
			if (stair_count[1].size() < 3 && !waiting[1].empty()) {
				stair_count[1].push(waiting[1].front());
				waiting[1].pop();
			}
		}

		


		for (int i = 0; i < p_size; i++) {
			int y = people_dist.front().y;
			int x = people_dist.front().x;
			int stair_number = people_dist.front().stair_number;
			int move = people_dist.front().move;
			people_dist.pop();
			move--;
			if (move > 0) {
				people_dist.push(value(y, x, stair_number, move));
			}
			else if (move == 0) {
				if (stair_number == 0) {
					if (stair_count[0].size() > 2) {
						waiting[0].push(value(y, x, stair_number, map[stair[stair_number].y][stair[stair_number].x]));
					}
					else if (stair_count[0].size() <= 2) {
						stair_count[0].push(value(y, x, stair_number, map[stair[stair_number].y][stair[stair_number].x] + 1));
					}
				}
				if (stair_number == 1) {
					if (stair_count[1].size() > 2) {
						waiting[1].push(value(y, x, stair_number, map[stair[stair_number].y][stair[stair_number].x]));
					}
					else if (stair_count[1].size() <= 2) {
						stair_count[1].push(value(y, x, stair_number, map[stair[stair_number].y][stair[stair_number].x] + 1));
					}
				}
				
			}
		}
		cnt++;
		if (stair_count[0].empty() && stair_count[1].empty() && people_dist.empty()) {
			minV = min(cnt, minV);
			return;
		}

	}

	return;
}

void select_stair(vector<int> &v) {
	if (v.size() == people_count) {
		solve(v);
		return;
	}
	for (int i = 0; i < 2; i++) {
		v.push_back(i);
		select_stair(v);
		v.pop_back();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		memset(map, 0, sizeof(map));
		people_count = 0;
		minV = 9999;
		stair.clear();
		people.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					people.push_back(pos(i, j));
					people_count++;
				}
				else if (map[i][j] != 0 && map[i][j]) {
					stair.push_back(pos(i, j));
				}
			}
		}

		vector<int> v;

		select_stair(v);

		cout << "#" << tc << " " << minV << endl;



	}

	return 0;
}
