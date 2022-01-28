/*

����
�������� �� N���� ������ ���� �ִ�. ������ ���� ��ǥ�� x1, ..., xN�̰�, �� �������� ���� ��ǥ�� ������ ���� ����.

�����̴� ���� ��𼭳� �������̸� ���� ���ؼ� ���� ������ C���� ��ġ�Ϸ��� �Ѵ�.
�ִ��� ���� ������ �������̸� ����Ϸ��� �ϱ� ������, �� ������ �����⸦ �ϳ��� ��ġ�� �� �ְ�, ���� ������ �� ������ ������ �Ÿ��� ������ ũ�� �Ͽ� ��ġ�Ϸ��� �Ѵ�.

C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (2 �� N �� 200,000)�� �������� ���� C (2 �� C �� N)�� �ϳ� �̻��� �� ĭ�� ���̿� �ΰ� �־�����.
��° �ٺ��� N���� �ٿ��� ���� ��ǥ�� ��Ÿ���� xi (0 �� xi �� 1,000,000,000)�� �� �ٿ� �ϳ��� �־�����.

���
ù° �ٿ� ���� ������ �� ������ ������ �ִ� �Ÿ��� ����Ѵ�.



���� �Է� 1
5 3
1
2
8
4
9

���� ��� 1
3

��Ʈ
�����⸦ 1, 4, 8 �Ǵ� 1, 4, 9�� ��ġ�ϸ� ���� ������ �� ������ ������ �Ÿ��� 3�̰�, �� �Ÿ����� ũ�� �����⸦ 3�� ��ġ�� �� ����.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;
int result = -1;
vector<int> v;


bool solve(int mid);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	int left = 1;	// �ּҰŸ�
	int right = v.back() - v.front(); // �ִ�Ÿ�
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (solve(mid))
		{
			result = max(result, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result << "\n";

}

bool solve(int mid)
{
	int cnt = 1;	// ������ ��
	int pre = v[0];
	for (int i = 1; i < N; i++)
	{
		if (v[i] - pre >= mid)
		{
			cnt++;
			pre = v[i];
		}
	}

	if (cnt >= C)
		return true;
	return false;
}
