/*

#include <iostream>
using namespace std;
#define MAXSIZE 1001

int A[MAXSIZE];
int dp[MAXSIZE];	//증가부분수열
int r_dp[MAXSIZE];  //감소부분수열
int result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int i = 1; i <= n; i++) // 증가부분
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (A[j] < A[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = n; i >= 1; i--) // 감소부분 (뒤에서 증가부분을 찾는 것처럼 구함)
	{
		r_dp[i] = 1;
		for (int j = n; j >= i; j--)
		{
			if (A[j] < A[i] && r_dp[i] < r_dp[j] + 1)
				r_dp[i] = r_dp[j] + 1;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (result < dp[i] + r_dp[i] - 1)
			// -1을 하는 이유는 중복 빼기 위함
			result = dp[i] + r_dp[i] - 1;
		
		// {1,2,3,2,1}일 때,
		// 증가부분 {1,2,3} 부분수열 크기 = 3
		// 감소부분 {3,2,1} 부분수열 크기 = 3
		// 합 = 3 + 3 = 6이됨
		// 부분수열에 3이 중복됐으므로 하나를 뺌
		
	}

	cout << result << "\n";
}


/*

문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.


예제 입력 1
10
1 5 2 1 4 3 4 5 2 1

예제 출력 1
7


힌트
예제의 경우 {*1 5 *2 1 4 *3 *4 *5 *2 *1}이 가장 긴 바이토닉 부분 수열이다.

*/