#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int R;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	cout << R * R * M_PI << endl;
	cout << R * R * 2 << endl;
}

// ù° �ٿ� ������ R�� �־�����. R�� 10,000���� �۰ų� ���� �ڿ����̴�.

// ù° �ٿ��� ��Ŭ���� �����п��� �������� R�� ���� ���̸�, ��° �ٿ��� �ý� �����п��� �������� R�� ���� ���̸� ����Ѵ�. ������� ������ 0.0001���� ����Ѵ�.

/*
42

5541.769441
3528.000000
*/