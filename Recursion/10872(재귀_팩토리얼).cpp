#include <iostream>
using namespace std;

int Factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return n * Factorial(n - 1);
}

int main()
{
	int num;
	cin >> num;
	cout << Factorial(num) << endl;
}

/*

����
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

���
ù° �ٿ� N!�� ����Ѵ�.


���� �Է� 1 
10
���� ��� 1 
3628800


���� �Է� 2 
0
���� ��� 2 
1

*/