#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> stk;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		string s;
		getline(cin, s);

		if (s == ".")
			break;

		bool isBracket = true;	// ��ȣ�� �ϳ��� ���� ���ڿ� ����
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				stk.push(s[i]);

			if (s[i] == ')')
			{
				if (!stk.empty() && stk.top() == '(')	// ������ ������� �ʴ��� Ȯ���ؾ� ��Ÿ�� ���� �߻����� ���� -->   )( �� ���� �Է�...
					stk.pop();
				else
				{
					isBracket = false;
					break;
				}
			}
			if (s[i] == ']')
			{
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
				{
					isBracket = false;
					break;
				}
			}
		}

		if (stk.empty())
		{
			if (isBracket)
				cout << "yes" << "\n";
			else
				cout << "no" << "\n";
		}
		else
		{
			cout << "no" << "\n";
			for (int i = 0; !stk.empty(); i++) // ���ÿ� �����ִ� ��ȣ ����
				stk.pop();
		}
	}
}

/*

����
����� ������ �� �����־�� �Ѵ�. ��� ��, ���� ��� �׸��� ���� ��ȣ�� ������ ��ȣó�� ���̴�.

�������� �ӹ��� � ���ڿ��� �־����� ��, ��ȣ���� ������ �� ������ �ִ��� �Ǵ��ϴ� ���α׷��� ¥�� ���̴�.

���ڿ��� ���ԵǴ� ��ȣ�� �Ұ�ȣ("()") �� ���ȣ("[]")�� 2�����̰�, ���ڿ��� ������ �̷�� ������ �Ʒ��� ����.

��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.
�����̸� ���� ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ����� �Ǵ��غ���.

�Է�
�ϳ� �Ǵ� �����ٿ� ���ļ� ���ڿ��� �־�����.
�� ���ڿ��� ���� ���ĺ�, ����, �Ұ�ȣ("( )") ���ȣ("[ ]")������ �̷���� ������, ���̴� 100���ں��� �۰ų� ����.

�Է��� ������������ �� �������� �� �ϳ�(".")�� ���´�.
���
�� �ٸ��� �ش� ���ڿ��� ������ �̷�� ������ "yes"��, �ƴϸ� "no"�� ����Ѵ�.



���� �Է� 1
So when I die (the [first] I will see in (heaven) is a score list).
[ first in ] ( first out ).
Half Moon tonight (At least it is better than no Moon at all].
A rope may form )( a trail in a maze.
Help( I[m being held prisoner in a fortune cookie factory)].
([ (([( [ ] ) ( ) (( ))] )) ]).
 .
.

���� ��� 1
yes
yes
no
no
no
yes
yes


��Ʈ
7��°�� " ."�� ���� ��ȣ�� �ϳ��� ���� ��쵵 �������� ���ڿ��� ������ �� �ִ�.

*/