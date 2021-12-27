#include <iostream>
using namespace std;

int fibo[50] = { 0,1, };

int fibonacci(int n)
{
	if (n == 0 || n == 1)
		return fibo[n];
	else if (fibo[n] == 0)
		fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return fibo[n];
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
			cout << "1 0" << "\n";
		else
			cout << fibonacci(num-1) << " " << fibonacci(num) << "\n";
	}
}

// �Ǻ���ġ�� 0�� 1�� ������ Ƚ���� ���ϴ� ���α׷�
// �ð� ���� 0.25��

/*
�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, N�� �־�����. N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
�� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.



���� �Է� 1
3
0
1
3

���� ��� 1
1 0
0 1
1 2


���� �Է� 2
2
6
22

���� ��� 2
5 8
10946 17711

*/