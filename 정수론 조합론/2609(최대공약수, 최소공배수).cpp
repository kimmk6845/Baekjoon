#include <iostream>
using namespace std;

int gcd(int num1, int num2) // �ִ�����
{
	// ��Ŭ���� ȣ����
	// a mod b = c --> b mod c = d --> c mod d = 0
	// ==> �ִ� ������� d�� ��
	int mod = num1 % num2;
	while (mod)
	{
		num1 = num2;
		num2 = mod;
		mod = num1 % num2;
	}
	return num2;
}
int lcm(int num1, int num2)  // �ּҰ����
{
	return num1 * num2 / gcd(num1, num2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2;
	cin >> num1 >> num2;

	cout << gcd(num1, num2) << "\n" << lcm(num1, num2) << "\n";
}

/*

����
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.

���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������, ��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.


���� �Է� 1
24 18

���� ��� 1
6
72

*/