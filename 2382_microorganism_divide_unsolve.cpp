#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
int map[101][101];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };

struct value {
	int y, x;
	int cnt;
	int dir;
	value(int a, int b, int c, int d) : y(a), x(b), cnt(c), dir(d) {}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> N >> M >> K;
		memset(map, 0, sizeof(map));
		queue<value> q;
		
		for (int i = 0; i < K; i++) {
			int r, c, n,d;
			cin >> r >> c >> n >> d;
			q.push(value(r, c, n, d));
			map[r][c] = n;
		}

		for (int i = 0; i < M; i++) {
			int q_size = q.size();
			for (int j = 0; j < q_size; j++) {
				int c_x = q.front().x;
				int c_y = q.front().y;
				int c_dir = q.front().dir;
				int c_cnt = q.front().cnt;
				q.pop();

				int n_x = c_x + dx[c_dir];
				int n_y = c_y + dy[c_dir];

				if(n_x == 0 || n_y == 0 || n_x == N -1 || n_y == N-1) {
					if (c_dir == 1)
						c_dir = 2;
					if (c_dir == 2)
						c_dir = 1;
					if (c_dir == 3)
						c_dir = 4;
					if (c_dir == 4)
						c_dir = 3;
				}



			}
		}
	}

	

	return 0;
}
