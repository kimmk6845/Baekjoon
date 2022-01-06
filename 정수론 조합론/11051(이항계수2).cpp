#include <iostream>
using namespace std;
#define MAXSIZE 1001

// 이항계수1 문제에서 오버플로우가 발생하는 것을 해결하는 문제
int dp[MAXSIZE][MAXSIZE] = { 0 };
int solve(int n,int k)
{
	if (n == k || k == 0)
		return 1;

	if (dp[n][k] != 0)
		return dp[n][k] % 10007;

	// 이항계수 구하는 공식
	// DP[a][b] = DP[a-1][b-1] + DP[a-1][b]
	dp[n][k] = solve(n - 1, k - 1) + solve(n - 1, k); 
	return dp[n][k] % 10007;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << solve(N, K) << "\n";

}

/*

문제
자연수 N과 정수 K가 주어졌을 때 이항 계수
(N K)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)

출력

(N K)를 10,007로 나눈 나머지를 출력한다.


예제 입력 1
5 2

예제 출력 1
10

*/