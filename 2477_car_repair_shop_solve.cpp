#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, A, B;
int at[9];
int bt[9];
int depart_time[1002];
int finish_depart[1002];
int finished[1002];
int using_recept[9];
int using_repair[9];
int finish_recept[1002];

struct data1 {
	int recept, repair, time;
	bool finished;
	int person_number;
	data1(int a, int b, bool c, int d, int e) : recept(a), repair(b), finished(c), time(d), person_number(e) {}
};

struct waiting_data {
	int person_number, time;
	waiting_data(int a, int b) : person_number(a), time(b) {}
};

bool check_finish() {
	for (int i = 1; i <= K; i++) {
		if (finished[i] == 0)
			return false;
	}

	return true;
}

bool check_recept() {
	for (int i = 0; i < N; i++) {
		if (using_recept[i] == 0)
			return false;
	}

	return true;
}

bool check_repair() {
	for (int i = 0; i < M; i++) {
		if (using_repair[i] == 0)
			return false;
	}

	return true;
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(at, 0, sizeof(at));
		memset(bt, 0, sizeof(bt));
		memset(depart_time, 0, sizeof(depart_time));
		memset(finished, 0, sizeof(finished));
		memset(finish_depart, 0, sizeof(finish_depart));
		memset(using_recept, 0, sizeof(using_recept));
		memset(using_repair, 0, sizeof(using_repair));
		memset(finish_recept, 0, sizeof(finish_recept));
		cin >> N >> M >> K >> A >> B;
		vector<data1> v[1002];
		vector<waiting_data> recept_space[9];
		vector<waiting_data> repair_space[9];
		queue<waiting_data> wating_recept;
		queue<waiting_data> wating_repair;
		int ans = 0;

		for (int i = 0; i < N; i++) {
			cin >> at[i];
		}
		for (int j = 0; j < M; j++) {
			cin >> bt[j];
		}
		for (int i = 1; i <= K; i++) {
			cin >> depart_time[i];
			v[i].push_back(data1(0, 0, false, depart_time[i], i));
		}

		int c_time = 0;
		while (check_finish() == false) {
			//1. 대기시간(tk) 줄인다.
			//2. 접수창구 full인지 확인한 후 가장 접수창구에 넣는다
			//3. 다 차있을경우 queue에 넣는다.
			//4. 접수창구에서 시간이 다 지난 경우 수리창구에 넣는다.
			//5. 수리창구가 다 차있을경우 queue에 넣는다.

			//recept는 recept에서 모두 처리
			for (int i = 1; i <= K; i++) {//i는 사람
				
				for (int k = 0; k < M; k++) {//i는 수리창구
					if (using_repair[k] == 1) {
						//repair_space[i][0].time--;
						if (repair_space[k][0].time == 0) { //repair 시간 다 끝나면 접수창구 확인하고 finish check
							v[repair_space[k][0].person_number][0].repair = k + 1;
							if (v[repair_space[k][0].person_number][0].repair == B && v[repair_space[k][0].person_number][0].recept == A) {
								ans += repair_space[k][0].person_number;
							}
							finished[repair_space[k][0].person_number] = 1;
							//using_repair[i] = 0;
							//repair_space[i][0].person_number = 0;
							//repair_space[i][0].time = 0;
							if (!wating_repair.empty()) {
								repair_space[k][0].person_number = wating_repair.front().person_number;
								repair_space[k][0].time = bt[k];
								wating_repair.pop();
							}
							else {
								using_repair[k] = 0;
								repair_space[k][0].person_number = 0;
								repair_space[k][0].time = 0;
							}
							//repair_space[i].pop_back();
						}

					}
				}
				
				for (int j = 0; j < N; j++) {
					if (using_recept[j] == 1) {
						if (recept_space[j][0].time == 0) {
							v[recept_space[j][0].person_number][0].recept = j + 1;	//recept_space 기억							

							if (check_repair() == true) {
								wating_repair.push(waiting_data(recept_space[j][0].person_number, 0));
							}
							else {

								for (int k = 0; k < M; k++) {	//수리창구
									if (using_repair[k] == 0 && repair_space[k].empty() && finish_recept[recept_space[j][0].person_number] == 0) {
										using_repair[k] = 1;
										finish_recept[recept_space[j][0].person_number] = 1;
										repair_space[k].push_back(waiting_data(recept_space[j][0].person_number, bt[k]));
										break;
										//역에 push back이 두번됨
									}
									else if (using_repair[k] == 0 && !repair_space[k].empty() && finish_recept[recept_space[j][0].person_number] == 0) {
										using_repair[k] = 1;
										finish_recept[recept_space[j][0].person_number] = 1;
										repair_space[k][0].person_number = recept_space[j][0].person_number;
										repair_space[k][0].time = bt[k];
									}
								}
							}


							if (!wating_recept.empty()) {
								recept_space[j][0].person_number = wating_recept.front().person_number;
								recept_space[j][0].time = at[j];
								wating_recept.pop();
							}
							else {
								using_recept[j] = 0;
								recept_space[j][0].person_number = 0;
								recept_space[j][0].time = 0;
							}

						}
					}
				
				
				if (finish_depart[i] == 0 && v[i][0].time == 0) {
					if (check_recept() == true) {//recept가 full
						finish_depart[i] = 1; //1013수정
						wating_recept.push(waiting_data(i, 0));
					}
					else {
						for (int j = 0; j < N; j++) {	//접수창구
							if (using_recept[j] == 0 && finish_depart[i] == 0 && recept_space[j].empty()) {
								finish_depart[i] = 1;	//1013수정
								using_recept[j] = 1;
								recept_space[j].push_back(waiting_data(i, at[j]));
							}
							else if (using_recept[j] == 0 && !recept_space[j].empty() && finish_depart[i] == 0) {
								finish_depart[i] = 1;
								using_recept[j] = 1;
								recept_space[j][0].person_number = i;
								recept_space[j][0].time = at[j];
							}
						}
					}
				}

				

					



				}
			}

			c_time++;

			for (int i = 1; i <= K; i++) {
				if (finish_depart[i] == 0) {
					if (v[i][0].time == 0)
						continue;
					v[i][0].time--;	//대기시간 줄여준다.
					//여기서 한번에 시간을 줄여본다.
				}
			}
			for (int i = 0; i < N; i++) {
				if (using_recept[i] == 1) {
					if (recept_space[i][0].time == 0)
						continue;
					recept_space[i][0].time--;
				}
			}
			for (int i = 0; i < M; i++) {
				if (using_repair[i] == 1) {
					if (repair_space[i][0].time == 0)
						continue;
					repair_space[i][0].time--;
				}
			}



		}

		if (ans == 0)
			cout << "#" << tc << " " << -1 << endl;
		else
			cout << "#" << tc << " " << ans << endl;


	}

	return 0;
}
