#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num, cnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string s;
		cin >> s;
		bool flag = false;
		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (s[j] != s[j - 1] && s[j] == s[k])  {
					flag = true;
					break;
				}
			}
		}
		if (flag == false) cnt++;
	}
	cout << cnt;

}

/*

����
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.



���� �Է� 1
3
happy
new
year
���� ��� 1
3


���� �Է� 2
4
aba
abab
abcabc
a
���� ��� 2
1


���� �Է� 3
5
ab
aa
aca
ba
bb
���� ��� 3
4


���� �Է� 4
2
yzyzy
zyzyz
���� ��� 4
0


���� �Է� 5
1
z
���� ��� 5
1

*/

// �����ؼ� ������ �ܾ �׷� �ܾ�
// �׷�ܾ�: ccazzzzbb, kim, aabbccdd
// ��׷�: aaadddccad, aabbccbb