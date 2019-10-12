#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct info {
	int number, rotate;
	info(int a, int b) : number(a), rotate(b) {}
};

int tob1[8], tob2[8], tob3[8], tob4[8];
int K;


void rotate(int arr[8], int dir) {
	if (dir == 1) {
		int end = arr[7];
		int i = 0;
		int temp = arr[i];
		int temp2 = arr[i + 1];
		while (i < 7) {
			arr[i + 1] = temp;
			i++;
			temp = temp2;
			temp2 = arr[i + 1];
		}
		arr[0] = end;
	}
	if (dir == -1) {
		int first = arr[0];
		int i = 7;
		int temp = arr[i];
		int temp2 = arr[i - 1];
		while (i > 0) {
			arr[i - 1] = temp;
			i--;
			temp = temp2;
			temp2 = arr[i - 1];
		}
		arr[7] = first;
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
		
	for (int tc = 1; tc <= T; tc++) {
		
		memset(tob1, 0, sizeof(tob1));
		memset(tob2, 0, sizeof(tob2));
		memset(tob3, 0, sizeof(tob3));
		memset(tob4, 0, sizeof(tob4));
		vector<info> v;
		cin >> K;
		for (int j = 0; j < 8; j++) {
			cin >> tob1[j];
		}
		for (int j = 0; j < 8; j++) {
			cin >> tob2[j];
		}
		for (int j = 0; j < 8; j++) {
			cin >> tob3[j];
		}
		for (int j = 0; j < 8; j++) {
			cin >> tob4[j];
		}

		for (int i = 0; i < K; i++) {
			int n, r;
			cin >> n >> r;
			v.push_back(info(n, r));
		}

		for (int i = 0; i < K; i++) {
			int r_number = v[i].number;
			int r_rotate = v[i].rotate;
			bool flag1, flag2, flag3, flag4;
			flag1 = flag2 = flag3 = flag4 = false;
			int r1, r2, r3, r4;

			if (r_number == 1) {
				if (r_rotate == 1) {
					r1 = 1;
					r2 = -1;
					r3 = 1;
					r4 = -1;
				}
				else if (r_rotate == -1) {
					r1 = -1;
					r2 = 1;
					r3 = -1;
					r4 = 1;
				}
				flag1 = true;
				if (tob1[2] != tob2[6]) {
					flag2 = true;
				}
				if (tob2[2] != tob3[6] && flag2 == true) {
					flag3 = true;
				}
				if (tob3[2] != tob4[6] && flag3 == true) {
					flag4 = true;
				}
				if (flag1 == true) {
					rotate(tob1, r1);
				}
				if (flag2 == true) {
					rotate(tob2, r2);
				}
				if (flag3 == true) {
					rotate(tob3, r3);
				}
				if (flag4 == true) {
					rotate(tob4, r4);
				}
				
			}

			else if (r_number == 2) {
				if (r_rotate == -1) {
					r1 = 1;
					r2 = -1;
					r3 = 1;
					r4 = -1;
				}
				else if (r_rotate == 1) {
					r1 = -1;
					r2 = 1;
					r3 = -1;
					r4 = 1;
				}
				flag2 = true;
				if (tob1[2] != tob2[6]) {
					flag1 = true;
				}
				if (tob2[2] != tob3[6]) {
					flag3 = true;
				}
				if (tob3[2] != tob4[6] && flag3 == true) {
					flag4 = true;
				}
				if (flag1 == true) {
					rotate(tob1, r1);
				}
				if (flag2 == true) {
					rotate(tob2, r2);
				}
				if (flag3 == true) {
					rotate(tob3, r3);
				}
				if (flag4 == true) {
					rotate(tob4, r4);
				}

			}

			else if (r_number == 3) {
				if (r_rotate == 1) {
					r1 = 1;
					r2 = -1;
					r3 = 1;
					r4 = -1;
				}
				else if (r_rotate == -1) {
					r1 = -1;
					r2 = 1;
					r3 = -1;
					r4 = 1;
				}
				flag3 = true;
				if (tob3[6] != tob2[2]) {
					flag2 = true;
				}
				if (tob1[2] != tob2[6] && flag2 == true) {
					flag1 = true;
				}
				if (tob3[2] != tob4[6]) {
					flag4 = true;
				}
				if (flag1 == true) {
					rotate(tob1, r1);
				}
				if (flag2 == true) {
					rotate(tob2, r2);
				}
				if (flag3 == true) {
					rotate(tob3, r3);
				}
				if (flag4 == true) {
					rotate(tob4, r4);
				}

			}

			else if (r_number == 4) {
				if (r_rotate == -1) {
					r1 = 1;
					r2 = -1;
					r3 = 1;
					r4 = -1;
				}
				else if (r_rotate == 1) {
					r1 = -1;
					r2 = 1;
					r3 = -1;
					r4 = 1;
				}
				flag4 = true;
				if (tob3[2] != tob4[6]) {
					flag3 = true;
				}
				if (tob2[2] != tob3[6] && flag3 == true) {
					flag2 = true;
				}
				if (tob1[2] != tob2[6] && flag2 == true) {
					flag1 = true;
				}
				if (flag1 == true) {
					rotate(tob1, r1);
				}
				if (flag2 == true) {
					rotate(tob2, r2);
				}
				if (flag3 == true) {
					rotate(tob3, r3);
				}
				if (flag4 == true) {
					rotate(tob4, r4);
				}

			}


		}

		int ans = 0;
		ans = tob1[0] * 1 + tob2[0] * 2 + tob3[0] * 4 + tob4[0] * 8;
		cout << "#" << tc << " " << ans << endl;

	}

	return 0;
}
