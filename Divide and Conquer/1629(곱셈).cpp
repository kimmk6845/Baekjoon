#include <iostream>
using namespace std;

typedef long long ll;

ll pow(ll x, ll y);

ll A, B, C;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << pow(A, B) % C << "\n";
}

ll pow(ll x, ll y)
{
	if (y == 0)
		return 1;
	else if (y == 1)
		return x;

	if (y % 2 > 0)
		return pow(x, y - 1) * x;
	ll half = pow(x, y / 2);
	half %= C;
	return (half * half) % C;
}

/*

����
�ڿ��� A�� B�� ���� ���� �˰� �ʹ�. �� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A, B, C�� �� ĭ�� ���̿� �ΰ� ������� �־�����. A, B, C�� ��� 2,147,483,647 ������ �ڿ����̴�.

���
ù° �ٿ� A�� B�� ���� ���� C�� ���� �������� ����Ѵ�.

** �ð����� 0.5��

���� �Է� 1
10 11 12
���� ��� 1
4

*/