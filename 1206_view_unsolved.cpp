#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[1001][255];
int height[1001];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int tc = 1; tc<=10; tc++){
		int N;
		memset(map,0,sizeof(map));
		memset(height,0,sizeof(height));

		cin >> N;
		
		for(int i = 0; i<N; i++){
			cin >> height[i];
		}

		for(int i = 0; i<N; i++){
			for(int j = 0; j<height[i]; j++){
				map[i][j] = 1;
			}
		}

		for(int i = 0; i<N; i++){
			
		}



	}

	//좌 우 2칸 이상이어야 조망권 보장
	//맨 위 좌우 탐색 후 있으면 내려가서 count
	//없으면 그대로

	return 0;
}
