#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define MAXSIZE 10001

//// STL������� �ʰ� STACK����
int stk[MAXSIZE];
int stk_s = 0;	// ����ũ��

void push(int n);
int pop();
int size();
int empty();
int top();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int x;
			cin >> x;
			push(x);
		}
		if (s == "pop")
			cout << pop() << endl;
		if (s == "size")
			cout << size() << endl;
		if (s == "empty")
			cout << empty() << endl;
		if (s == "top")
			cout << top() << endl;
	}
}

void push(int n)
{
	stk[stk_s] = n;
	stk_s++;
}

int pop()
{
	if (stk_s == 0)
		return -1;
	stk_s--;
	return stk[stk_s];
}

int size()
{
	return stk_s;
}

int empty()
{
	if (stk_s == 0)
		return 1;
	else
		return 0;
}

int top()
{
	if (stk_s == 0)
		return -1;
	return stk[stk_s - 1];
}


//// STL�� �̿��� �䱸 ���� ������Ű��
/*
int main()
{
	stack<int> stk;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int n;
			cin >> n;
			stk.push(n);
		}
		if (s == "pop")
		{
			if (stk.size() == 0)
				cout << -1 << endl;
			else
			{
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		if (s == "size")
			cout << stk.size() << endl;
		if (s == "empty")
			cout << stk.empty() << endl;
		if (s == "top")
		{
			if (stk.size() == 0)
				cout << -1 << endl;
			else
				cout << stk.top() << endl;
		}
	}
}
*/


/*

����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. (���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.)
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����.
��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����.
������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.



���� �Է� 1
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top

���� ��� 1
2
2
0
2
1
-1
0
1
-1
0
3



���� �Է� 2
7
pop
top
push 123
top
pop
top
pop

���� ��� 2
-1
-1
123
123
-1
-1

*/