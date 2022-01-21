#include <iostream>
using namespace std;

typedef long long ll;

ll A[5][5];
ll N, B;

void solve(ll A1[5][5], ll A2[5][5]);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll result[5][5] = { 0 };
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
		result[i][i] = 1;	// 단위행렬로 만들기
	}

	while (B != 0)
	{
		if (B % 2 == 1)
			solve(result, A);
		solve(A, A);
		B /= 2;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}
}

void solve(ll A1[5][5], ll A2[5][5])
{
	ll result[5][5] = { 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				result[i][j] += A1[i][k] * A2[k][j];
			result[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A1[i][j] = result[i][j];
}

/*

A ^ B

B가 홀수: A * A ^ (B - 1)
B가 짝수: (A * A) ^ (B / 2)
B가 0이 되면 종료

*/

/*


문제
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오.
수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.



예제 입력 1
2 5
1 2
3 4

예제 출력 1
69 558
337 406


예제 입력 2
3 3
1 2 3
4 5 6
7 8 9

예제 출력 2
468 576 684
62 305 548
656 34 412


예제 입력 3
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1

예제 출력 3
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512

*/