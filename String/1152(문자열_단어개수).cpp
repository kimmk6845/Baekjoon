#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			flag = true;
		else if (flag) {
			flag = false;
			cnt++;
		}
	}
	cout << cnt;
}


/*

����
���� ��ҹ��ڿ� �������� �̷���� ���ڿ��� �־�����. �� ���ڿ����� �� ���� �ܾ ������? �̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ����� �Ѵ�.

�Է�
ù �ٿ� ���� ��ҹ��ڿ� �������� �̷���� ���ڿ��� �־�����. �� ���ڿ��� ���̴� 1,000,000�� ���� �ʴ´�. �ܾ�� ���� �� ���� ���еǸ�, ������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �������� �����ϰų� ���� �� �ִ�.

���
ù° �ٿ� �ܾ��� ������ ����Ѵ�.



���� �Է� 1
The Curious Case of Benjamin Button
���� ��� 1
6


���� �Է� 2
 The first character is a blank
���� ��� 2
6


���� �Է� 3
The last character is a blank
���� ��� 3
6

*/