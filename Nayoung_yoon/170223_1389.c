/**********************************************************/
//https://www.acmicpc.net/problem/1389*/
//와샬플로이드알고리즘, 최소비용경로탐색
//1389 - 케빈베이커의 6단계 법칙
/**********************************************************/
#include<stdio.h>
#define USER_MAX 101
#define FRIEND_MAX 5001

/*
void printf_table(int A[USER_MAX][USER_MAX], int numb) { //비용행렬 출력을 위한 함수
	printf("\nPRINT TABLE :\n");
	for (int j = 1; j <= numb; j++) {
		for (int k = 1; k <= numb; k++) {
			printf("%d ", A[j][k]);
		}
		printf("\n");
	}
}
*/

int main()
{
	int N, M; // N: 유저수 M: 친구수
	int from, to;
	int standard, compare;
	int friendship[USER_MAX][USER_MAX] = {0}; //유저 간 관계표
	int temp_sum, max_user = 1, max_value = FRIEND_MAX;
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &N, &M);

	// 1) 유저 간 관계표 작성 (비용행렬 작성)
	for (int i = 1; i <= M; i++) {
		from = 0 , to = 0;
		scanf("%d %d", &from, &to);
		friendship[from][to] = 1;
		friendship[to][from] = 1;
	}
//	printf_table(friendship, M);

	// 2) 와샬-플로이드 알고리즘으로 최단거리 산출
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {

			standard = friendship[i][j];
			if (standard == 1) { continue; } // case1. 직접 연결된 노드는 점프
			if (i == j) { continue; } // case2. 출발=도착 인 경우 점프
	
			for (int z = 1; z <= M; z++) { // case3. 간접 연결 시 간선이 존재하는 경우, 그 합이 기존보다 적은 경우.
				if ((friendship[i][z]!= 0 )&& (friendship[z][j] != 0)) {
					compare = friendship[i][z] + friendship[z][j];		
					if (standard == 0) { friendship[i][j] = compare, friendship[j][i] = compare; }
					else if (compare < standard ) { friendship[i][j] = compare, friendship[j][i] = compare; } //교체
			}
			}
		}
	}

	// 3) 정답 산출
//	printf_table(friendship, M);
	
	for (int i = 1; i <= M; i++) {
		temp_sum = 0;
		for (int j = 1; j <= M; j++) { temp_sum += friendship[i][j]; }
		if (max_value > temp_sum) { max_user = i, max_value = temp_sum; }
	}

	printf("%d", max_user);

	return 0;
}
