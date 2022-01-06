#include <iostream>
using namespace std;
#define MAXSIZE 1001

// ���װ��1 �������� �����÷ο찡 �߻��ϴ� ���� �ذ��ϴ� ����
int dp[MAXSIZE][MAXSIZE] = { 0 };
int solve(int n,int k)
{
	if (n == k || k == 0)
		return 1;

	if (dp[n][k] != 0)
		return dp[n][k] % 10007;

	// ���װ�� ���ϴ� ����
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

����
�ڿ��� N�� ���� K�� �־����� �� ���� ���
(N K)�� 10,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 1,000, 0 �� K �� N)

���

(N K)�� 10,007�� ���� �������� ����Ѵ�.


���� �Է� 1
5 2

���� ��� 1
10

*/