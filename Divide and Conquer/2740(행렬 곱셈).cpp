#include <iostream>
using namespace std;
#define MAXSIZE 101

int A[MAXSIZE][MAXSIZE];
int B[MAXSIZE][MAXSIZE];
int result[MAXSIZE][MAXSIZE];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Matrix A
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	// Matrix B
	int M2, K;
	cin >> M2 >> K;		// M2는 M과 무조건 같은 수
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {	//O(N^3) 복잡도
				result[i][j] += A[i][k] * B[k][j];
			}
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

/*

문제
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

입력
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다.
그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다.
N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

출력
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.


예제 입력 1
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3

예제 출력 1
-1 -2 6
-3 -6 12
-5 -10 18

*/