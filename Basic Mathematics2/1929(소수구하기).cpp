#include <iostream>
using namespace std;

bool IsPrime(int x)
{
	if (x ==0 || x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = m; i < n + 1; i++)
	{
		if (IsPrime(i))
			cout << i << "\n";
	}
}

/*

# �ð����� 2��

����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. 
(1 �� M �� N �� 1,000,000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.


���� �Է� 1
3 16

���� ��� 1
3
5
7
11
13

*/