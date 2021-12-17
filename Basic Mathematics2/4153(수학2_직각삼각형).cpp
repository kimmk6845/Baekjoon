#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	while (1)
	{
		int x, y, z;
		cin >> x >> y >> z;

		if (x == 0 && y == 0 && z == 0)
			break;

		// z�� ���� ū ���� �����
		if (x > y)
			swap(x, y);
		if (y > z)
			swap(y, z);

		if (z * z == x * x + y * y)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}

// ���� ����Ʈ�ε��� �� ������ ���̰� 3, 4, 5�� �ﰢ���� ���� �ﰢ���ΰ��� �˾Ƴ´�. �־��� ������ ���̷� �ﰢ���� �������� �ƴ��� �����Ͻÿ�.

// �Է��� �������� �׽�Ʈ���̽��� �־����� �������ٿ��� 0 0 0�� �Էµȴ�. �� �׽�Ʈ���̽��� ��� 30,000���� ���� ���� ������ �־�����, �� �Է��� ���� ���̸� �ǹ��Ѵ�.

// �� �Է¿� ���� ���� �ﰢ���� �´ٸ� "right", �ƴ϶�� "wrong"�� ����Ѵ�.

/*
6 8 10
25 52 60
5 12 13
0 0 0
*/

/*
right
wrong
right
*/