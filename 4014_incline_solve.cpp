#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int map[21][21];
int visited[21];
 
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
            memset(visited, 0, sizeof(visited));
            for (int j = 0; j < N - 1; j++) {
                if (map[i][j] != map[i][j + 1]) {
                    if (abs(map[i][j] - map[i][j + 1]) >= 2) {
                        flag = true;
                        break;
                    }
                    else if (map[i][j] - map[i][j + 1] > 0) { //이전에 있던 값이 더 큰경우 -> 다음값 탐색
                        for (int k = j + 1; k < j + 1 + X; k++) {
                            if (visited[k] == true) {
                                flag = true;
                                break;
                            }
                            if (k >= N) {
                                flag = true;
                                break;
                            }
                            else if (map[i][k] != map[i][j + 1]) {
                                flag = true;
                                break;
                            }
                            visited[k] = true;
                        }
                    }
                    else if (map[i][j] - map[i][j + 1] < 0) { //올라가는경우 이전값 탐색
                        for (int k = j; k > j - X; k--) {
                            if (visited[k] == true) {
                                flag = true;
                                break;
                            }
                            if (k < 0) {
                                flag = true;
                                break;
                            }
                            else if (map[i][k] != map[i][j]) {
                                flag = true;
                                break;
                            }
                            visited[k] = true;
                        }
                    }
                }
            }
            if (flag == false) {
                cnt++;
            }
        }
 
 
        for (int i = 0; i < N; i++) {
            flag = false;
            memset(visited, 0, sizeof(visited));
            for (int j = 0; j < N - 1; j++) {
                if (map[j][i] != map[j + 1][i]) {
                    if (abs(map[j][i] - map[j + 1][i]) >= 2) {
                        flag = true;
                        break;
                    }
                    else if (map[j][i] - map[j + 1][i] > 0) { //이전에 있던 값이 더 큰경우 내려가는 경우
                        for (int k = j + 1; k < j + 1 + X; k++) {
                            if (visited[k] == true) {
                                flag = true;
                                break;
                            }
                            if (k >= N) {
                                flag = true;
                                break;
                            }
                            else if (map[k][i] != map[j + 1][i]) {
                                flag = true;
                                break;
                            }
                            visited[k] = true;
                        }
                    }
                    else if (map[j][i] - map[j + 1][i] < 0) { //올라가는경우 이전값 탐색
                        for (int k = j; k > j - X; k--) {
                            if (visited[k] == true) {
                                flag = true;
                                break;
                            }
                            if (k < 0) {
                                flag = true;
                                break;
                            }
                            else if (map[k][i] != map[j][i]) {
                                flag = true;
                                break;
                            }
                            visited[k] = true;
                        }
                    }
                }
            }
            if (flag == false) {
                cnt++;
            }
        }
 
        cout << "#" << t + 1 << " " << cnt << endl;
    }
 
    return 0;
}
