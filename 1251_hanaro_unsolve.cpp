#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstrin>

using namespace std;

long long x_pos[1001];
long long y_pos[1001];
bool visited[1001];

struct item{
	int idx, dist;
	item(int a, int b) : idx(a), dist(b) {}
};

struct cmp{
	bool operator() (item a, item b) {
		return a.dist > b.dist;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int T;
	cin >> T;
	double E;
	for(int tc = 1; tc<=T; tc++){
		
		int N;
		memset(x_pos,0,sizeof(x_pos));
		memset(y_pos,0,sizeof(y_pos));
		memset(visited,0,sizeof(visited));

		cin >> N;
		for(int i = 0; i<N; i++){
			cin >> x_pos[i];
		}
		for(int i = 0; i<N; i++){
			cin >> y_pos[i];
		}
		cin >> E;

		priority_queue<item, vector<item>, cmp> pq;

		pq.push(item(0,0));
		visited[0] = true;
		int ans = 0;

		while(!pq.empty()) {
			int c_idx = pq.top().idx;
			int c_dist = pq.top().dist;
			ans += c_dist;
			pq.pop();
			
			for(int i = 0; i<N; i++){
				if(visited[i] == false) {
					int n_dist = pow(x_pos[c_idx]-x_pos[i],2) + pow(y_pos[c_idx]-y_pos[i],2);
					visited[i] = true;
					pq.push(item(i,n_dist));
				}
			}
		}

		ans *= E;

		cout << "#" << tc << " " << ans << endl;

	}

	return 0;
}
