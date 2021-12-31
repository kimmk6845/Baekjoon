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

   �� ���ڰ� ���� ���� �� i, j �ε����� ����, ���� �߿� �ִ��� ���ϴ� ����
   �� ���ڸ� ���� �������� ���� DP�� ������ 1�� ������� �ϱ� ����

*/

/*

����
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.

���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.



���� �Է� 1
ACAYKP
CAPCAK

���� ��� 1
4

*/