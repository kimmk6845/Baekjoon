#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 2000001


////////// STL ������� �ʰ� Queue ����
int que[MAX];
int q_rear = 0;
int q_front = 0;

void push(int x);
int pop();
int size();
int empty();
int front();
int back();

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
			int num;
			cin >> num;
			push(num);
		}
		if (s == "pop")
			cout << pop() << "\n";
		if (s == "size")
			cout << size() << "\n";
		if (s == "empty")
			cout << empty() << "\n";
		if (s == "front")
			cout << front() << "\n";
		if (s == "back")
			cout << back() << "\n";
	}
}

void push(int x)
{
	que[q_rear] = x;
	q_rear++;
}
int pop()
{
	if (q_front == q_rear || q_rear == 0)
		return -1;

	q_front++;
	return que[q_front - 1];
}
int size()
{
	return q_rear - q_front;
}
int empty()
{
	if (q_front == q_rear || q_rear == 0)
		return 1;
	else
		return 0;
}
int front()
{
	if (q_front == q_rear || q_rear == 0)
		return -1;
	return que[q_front];
}
int back()
{
	if (q_front == q_rear || q_rear == 0)
		return -1;
	return que[q_rear - 1];
}

/*
///////////// STL�� �̿��� ����Ǯ��
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> Q;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int num;
			cin >> num;
			Q.push(num);
		}
		if (s == "pop")
		{
			if (!Q.empty())
			{
				cout << Q.front() << "\n";
				Q.pop();
			}
			else
				cout << -1 << "\n";
		}
		if (s == "size")
			cout << Q.size() << "\n";
		if (s == "empty")
			cout << Q.empty() << "\n";
		if (s == "front")
		{
			if (!Q.empty())
			{
				cout << Q.front() << "\n";
			}
			else
				cout << -1 << "\n";
		}
		if (s == "back")
		{
			if (!Q.empty())
			{
				cout << Q.back() << "\n";
			}
			else
				cout << -1 << "\n";
		}
	}
}
*/

/*

����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����.
��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.
�־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.


���� �Է� 1
15
push 1
push 2
front
back
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
front

���� ��� 1
1
2
2
0
1
2
-1
0
1
-1
0
3

*/