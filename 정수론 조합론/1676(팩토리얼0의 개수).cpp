#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int two_cnt = 0, five_cnt = 0;
	int result;
	for (int i = n; i >= 1; i--)
	{
		for (int j = i; i; j /= 2)
		{
			if (j % 2 == 0)
				two_cnt++;
			else break;		// ���μ� 2�� ���̻� ������ Ż��
		}

		for (int j = i; j; j /= 5)
		{
			if (j % 5 == 0)
				five_cnt++;
			else break; // 5������ Ż��
		}
	}
	result = min(two_cnt, five_cnt);
	cout << result << "\n";
}

/*
���μ����� -> 2�� 5�� ����

����
N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (0 �� N �� 500)

���
ù° �ٿ� ���� 0�� ������ ����Ѵ�.



���� �Է� 1
10
���� ��� 1
2


���� �Է� 2
3
���� ��� 2
0

*/