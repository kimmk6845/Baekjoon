#include <iostream>
#include <string>
using namespace std;

int main()
{
	int c[26];
	fill(c, c + sizeof(c) / sizeof(int), -1); // -1�� �ʱ�ȭ
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int idx = (int)s[i] - 97;

		if (c[idx] == -1)
			c[idx] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << c[i] << " ";
}


// �ҹ��� �Է� �޾� ������ ��ġ�� ã��.
// ó�� �����ϴ� ��ġ�� �����ϰ�, ���ٸ� -1