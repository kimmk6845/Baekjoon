#include <iostream>
#include <string>
using namespace std;

int main()
{
	int c[26];
	fill(c, c + sizeof(c) / sizeof(int), 0);
	string s; int idx;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 97)
			s[i] -= 32;
		idx = (int)s[i] - 65;
		c[idx]++;
	}

	int maxValue = 0; int maxIdx = 0;
	for (int i = 0; i < 26; i++)
	{
		if (maxValue < c[i])
		{
			maxValue = c[i];
			maxIdx = i;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (maxValue == c[i])
			cnt++;
	}

	if (cnt > 1)cout << '?';
	else cout << (char)(maxIdx + 65);
}


/*

����
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

���
ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.


���� �Է� 1
Mississipi
���� ��� 1
?


���� �Է� 2
zZa
���� ��� 2
Z


���� �Է� 3
z
���� ��� 3
Z


���� �Է� 4
baaa
���� ��� 4
A

*/