#include <iostream>
using namespace std;

int lcm(int num1, int num2)
{
	int a = num1;
	int b = num2;
	int mod = a % b;
	while (mod)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	int result = b;

	return num1 * num2 / result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int num1, num2;
	for (int i = 0; i < T; i++)
	{
		cin >> num1 >> num2;
		cout << lcm(num1, num2) << "\n";
	}
}

/*

����
�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�.
�̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.

�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. ��° �ٺ��� T���� �ٿ� ���ļ� A�� B�� �־�����. (1 �� A, B �� 45,000)

���
ù° �ٺ��� T���� �ٿ� A�� B�� �ּҰ������ �Է¹��� ������� �� �ٿ� �ϳ��� ����Ѵ�.



���� �Է� 1
3
1 45000
6 10
13 17

���� ��� 1
45000
30
221

*/