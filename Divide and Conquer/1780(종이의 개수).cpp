#include <iostream>
using namespace std;
#define MAX 2187	// 3^7

int paper[MAX][MAX];
void solve(int x, int y, int size);
int cnt_mOne = 0, cnt_zero = 0, cnt_pOne = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solve(0, 0, n);
	cout << cnt_mOne << "\n" << cnt_zero << "\n" << cnt_pOne << "\n";
}

void solve(int x, int y, int size)
{
	bool minus_one = true, zero = true, plus_one = true;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] != -1)
				minus_one = false;
			if (paper[i][j] != 0)
				zero = false;
			if (paper[i][j] != 1)
				plus_one = false;

		}
	}
	if (minus_one)
	{
		cnt_mOne++;
		return;
	}
	if (zero)
	{
		cnt_zero++;
		return;
	}
	if (plus_one)
	{
		cnt_pOne++;
		return;
	}
	solve(x, y, size / 3);
	solve(x, y + size / 3, size / 3);
	solve(x, y + (2 * size / 3), size / 3);

	solve(x + size / 3, y, size / 3);
	solve(x + size / 3, y + size / 3, size / 3);
	solve(x + size / 3, y + (2 * size / 3), size / 3);

	solve(x + (2 * size / 3), y, size / 3);
	solve(x + (2 * size / 3), y + size / 3, size / 3);
	solve(x + (2 * size / 3), y + (2 * size / 3), size / 3);

}


/*

����
N��Nũ���� ��ķ� ǥ���Ǵ� ���̰� �ִ�. ������ �� ĭ���� -1, 0, 1 �� �ϳ��� ����Ǿ� �ִ�.
�츮�� �� ����� ������ ���� ��Ģ�� ���� ������ ũ��� �ڸ����� �Ѵ�.

���� ���̰� ��� ���� ���� �Ǿ� �ִٸ� �� ���̸� �״�� ����Ѵ�.
(1)�� �ƴ� ��쿡�� ���̸� ���� ũ���� ���� 9���� �ڸ���, ������ �߸� ���̿� ���ؼ� (1)�� ������ �ݺ��Ѵ�.
�̿� ���� ���̸� �߶��� ��, -1�θ� ä���� ������ ����, 0���θ� ä���� ������ ����, 1�θ� ä���� ������ ������ ���س��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 37, N�� 3k ��)�� �־�����. ���� N���� �ٿ��� N���� ������ ����� �־�����.

���
ù° �ٿ� -1�θ� ä���� ������ ������, ��° �ٿ� 0���θ� ä���� ������ ������, ��° �ٿ� 1�θ� ä���� ������ ������ ����Ѵ�.



���� �Է� 1
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1

���� ��� 1
10
12
11

*/