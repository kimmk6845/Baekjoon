#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int num;
		string s;
		cin >> num;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			for (int k = 0; k < num; k++)
				cout << s[j];
		}
		cout << endl;
	}
}

/*

����
���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. S���� QR Code "alphanumeric" ���ڸ� ����ִ�.

QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), ���ڿ� S�� �������� ���еǾ� �־�����. S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���� P�� ����Ѵ�.



���� �Է� 1
2
3 ABC
5 /HTP

���� ��� 1
AAABBBCCC
/////HHHHHTTTTTPPPPP

*/