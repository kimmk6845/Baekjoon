/*

����
�����̴� ũ�Ⱑ N��N�� �迭 A�� �������. �迭�� ����ִ� �� A[i][j] = i��j �̴�.
�� ���� ������ �迭 B�� ������ B�� ũ��� N��N�� �ȴ�. B�� �������� �������� ��, B[k]�� ���غ���.

�迭 A�� B�� �ε����� 1���� �����Ѵ�.

�Է�
ù° �ٿ� �迭�� ũ�� N�� �־�����. N�� 105���� �۰ų� ���� �ڿ����̴�.
��° �ٿ� k�� �־�����. k�� min(109, N2)���� �۰ų� ���� �ڿ����̴�.

���
B[k]�� ����Ѵ�.

���� �Է� 1
3
7
���� ��� 1
6

*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int result = -1;
	cin >> N >> K;

	int left = 1;
	int right = K;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += min(N, mid / i);

		if (cnt >= K)
		{
			result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << result << "\n";

}
