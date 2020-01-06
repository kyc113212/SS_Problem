#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

long long x_pos[1001];
long long y_pos[1001];
bool visited[1001];
int N;

struct item {
	long long idx, dist;
	item(long long a, long long b) : idx(a), dist(b) {}
};

struct cmp {
	bool operator() (item a, item b) {
		return a.dist > b.dist;
	}
};

bool check_map() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (visited[i] == false)
			return true;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T;
	cin >> T;
	double E;
	for (int tc = 1; tc <= T; tc++) {

		memset(x_pos, 0, sizeof(x_pos));
		memset(y_pos, 0, sizeof(y_pos));
		memset(visited, 0, sizeof(visited));

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x_pos[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> y_pos[i];
		}
		cin >> E;

		priority_queue<item, vector<item>, cmp> pq;

		pq.push(item(0, 0));
		//visited[0] = true;
		double ans = 0;

		while (!pq.empty()) {
			if (check_map() == false)
				break;
			
			int c_idx = pq.top().idx;
			double c_dist = pq.top().dist;
			
			pq.pop();

			if (visited[c_idx] == false) {
				visited[c_idx] = true;
				//c_dist *= E;
				//long long temV = floor(c_dist + 0.5);
				//ans += temV;
				//long long temp;
				//temp = c_dist * E;
				//ans += temp;
				ans += c_dist;

				for (int i = 0; i < N; i++) {
					if (visited[i] == false) {
						long long n_dist = pow(x_pos[c_idx] - x_pos[i], 2) + pow(y_pos[c_idx] - y_pos[i], 2);
						pq.push(item(i, n_dist));
					}
				}
			}

			
		}

		ans *= E;
		long long tempV = floor(ans + 0.5);
		
		cout << "#" << tc << " " << tempV << endl;

	}

	return 0;
}
