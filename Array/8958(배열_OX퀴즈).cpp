#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int* result = new int[num];

	for (int i = 0; i < num; i++)
	{
		string tc;
		cin >> tc;
		int score = 0, cnt = 0;
		for (int j = 0; j < tc.size(); j++)
		{
			if (tc[j] == 'O')
				cnt += 1;
			else
				cnt = 0;
			score += cnt;
		}
		result[i] = score;
	}
	for (int i = 0; i < num; i++)
		cout << *(result + i) << endl;

	delete[] result;
}

/*

OX����, ������ �� �������� ���ӵ� O�� ������ ��


����
"OOXXOXXOOO"�� ���� OX������ ����� �ִ�. O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�. ������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�. ���� ���, 10�� ������ ������ 3�� �ȴ�.

"OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.

OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����. ���ڿ��� O�� X������ �̷���� �ִ�.

���
�� �׽�Ʈ ���̽����� ������ ����Ѵ�.



���� �Է� 1
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX

���� ��� 1
10
9
7
55
30

*/