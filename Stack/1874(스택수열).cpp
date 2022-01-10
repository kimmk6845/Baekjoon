#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> stk;
	string s = "";
	int cnt = 1;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num >= cnt)
		{
			while (num + 1 != cnt) {
				stk.push(cnt++);
				s += "+";
			}
			stk.pop();
			s += "-";
		}
		else
		{
			if (stk.top() == num)
			{
				stk.pop();
				s += "-";
			}
			else
				flag = false;
		}
	}

	if (flag)
	{
		for (int i = 0; i < s.length(); i++)
			cout << s[i] << "\n";
	}
	else
		cout << "NO" << "\n";
}

/*

����
���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�.
������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.

1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�.
�̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����.
������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�.
�̸� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����.
���� ���� ������ �� �� ������ ���� ����.

���
�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.



���� �Է� 1
8
4
3
6
8
7
5
2
1
���� ��� 1
+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-



���� �Է� 2
5
1
2
5
3
4
���� ��� 2
NO

��Ʈ
1���� n������ ���� ���� ���ʷ� [push, push, push, push, pop, pop, push, push, pop, push, push, pop, pop, pop, pop, pop] ������ �����ϸ� ���� [4, 3, 6, 8, 7, 5, 2, 1]�� ���� �� �ִ�.

*/