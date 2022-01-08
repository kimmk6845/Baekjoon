#include <iostream>
using namespace std;
#define MAXSIZE 30

int dp[MAXSIZE + 1][MAXSIZE + 1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < MAXSIZE; i++)	// N=1일때, M의 수가 전부임
		dp[1][i] = i;
	for (int i = 2; i < MAXSIZE; i++)
	{
		for (int j = i; j <= MAXSIZE; j++)
		{
			for (int k = j; k >= i; k--)
				dp[i][j] += dp[i - 1][k - 1];
		}
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}
}

/*

N=1,M=1  ans = 1
N=1,M=2  ans = 2
N=1,M=3  ans = 3 ... N=1일때는 M의 수가 답
N=2,M=2  ans = 1
N=2,M=3  ans = 3
N=2,M=4  ans = 6

dp[1][1] = 1         dp[1][2] = 2                    dp[1][3] = 3
dp[2][2] = dp[1][1], dp[2][3] = dp[1][2] + dp[1][1], dp[2][4] = dp[1][3] + dp[1][2] + dp[1][1]
dp[3][3] = dp[2][2], dp[3][4] = dp[2][3] + dp[2][2], dp[3][5] = dp[2][4] + dp[2][3] + dp[2][2]

*/

/*

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
그 다음 줄부터 각각의 테스트케이스에 대해 강의 서쪽과 동쪽에 있는 사이트의 개수 정수 N, M (0 < N ≤ M < 30)이 주어진다.

출력
각 테스트 케이스에 대해 주어진 조건하에 다리를 지을 수 있는 경우의 수를 출력한다.


예제 입력 1
3
2 2
1 5
13 29

예제 출력 1
1
5
67863915

*/