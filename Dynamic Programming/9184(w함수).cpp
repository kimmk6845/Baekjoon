#include <iostream>
using namespace std;

int dp[21][21][21];
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (a < b && b < c)
	{
		if (dp[a][b][c] != 0) return dp[a][b][c];
		else return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		if (dp[a][b][c] != 0) return dp[a][b][c];
		else return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
}

/*

����
��� ȣ�⸸ �����ϸ� ���� ����! �ƴѰ���?

������ ���� ����Լ� w(a, b, c)�� �ִ�.

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
	1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
	w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
	w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
	w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

���� �Լ��� �����ϴ� ���� �ſ� ����. ������, �״�� �����ϸ� ���� ���ϴµ� �ſ� ���� �ð��� �ɸ���. (���� ���, a=15, b=15, c=15)

a, b, c�� �־����� ��, w(a, b, c)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �� ���� a, b, c�� �̷���� ������, �� �ٿ� �ϳ��� �־�����. �Է��� �������� -1 -1 -1�� ��Ÿ����, �� ������ ��� -1�� ���� �Է��� �������� �����ϸ� ����.

���
�Է����� �־��� ������ a, b, c�� ���ؼ�, w(a, b, c)�� ����Ѵ�.


����
-50 �� a, b, c �� 50


���� �Է� 1
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1

���� ��� 1
w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1

*/