#include <iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int result = factorial(N) / (factorial(K) * factorial(N - K));
	cout << result << "\n";
}

/*
���װ��
(n k) = 0            (k < 0)
		n!/k!(n-k)!  (0<=k<=n)
		0            (k > n)
*/

/*

����
�ڿ��� N�� ���� K�� �־����� �� ���� ���
(N K)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 0 �� K �� N)

���

(N K)�� ����Ѵ�.


���� �Է� 1
5 2

���� ��� 1
10

*/