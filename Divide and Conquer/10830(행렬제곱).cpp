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
		result[i][i] = 1;	// ������ķ� �����
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

B�� Ȧ��: A * A ^ (B - 1)
B�� ¦��: (A * A) ^ (B / 2)
B�� 0�� �Ǹ� ����

*/

/*


����
ũ�Ⱑ N*N�� ��� A�� �־�����. �̶�, A�� B������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� �ſ� Ŀ�� �� ������, A^B�� �� ���Ҹ� 1,000���� ���� �������� ����Ѵ�.

�Է�
ù° �ٿ� ����� ũ�� N�� B�� �־�����. (2 �� N ��  5, 1 �� B �� 100,000,000,000)

��° �ٺ��� N���� �ٿ� ����� �� ���Ұ� �־�����. ����� �� ���Ҵ� 1,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٺ��� N���� �ٿ� ���� ��� A�� B������ ����� ����Ѵ�.



���� �Է� 1
2 5
1 2
3 4

���� ��� 1
69 558
337 406


���� �Է� 2
3 3
1 2 3
4 5 6
7 8 9

���� ��� 2
468 576 684
62 305 548
656 34 412


���� �Է� 3
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1

���� ��� 3
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512

*/