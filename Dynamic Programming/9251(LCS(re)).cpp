#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXSIZE 1001

int dp[MAXSIZE][MAXSIZE];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[s1.length()][s2.length()] << "\n";
}

/*
   A   C   A   Y   K   P
C  0   0   0   0   0   0   0
A  0   0   1   1   1   1   1
P  0   1   1   2   2   2   2
C  0   1   1   2   2   2   3
A  0   1   2   2   2   2   3
K  0   1   2   3   3   3   3
   0   1   2   3   3   4   4

   두 문자가 같지 않을 때 i, j 인덱스의 왼쪽, 위쪽 중에 최댓값을 취하는 것은
   두 문자를 각각 포함하지 않은 DP의 값에서 1을 더해줘야 하기 때문

*/

/*

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.



예제 입력 1
ACAYKP
CAPCAK

예제 출력 1
4

*/