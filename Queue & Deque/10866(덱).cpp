#include <iostream>
#include <string>
#include <deque>
using namespace std;
#define MAX 10001


//////////////STL ������� �ʰ� Deque ����
int deq[MAX];
int d_front = 0;
int d_rear = 0;

void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
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

		if (s == "push_back")
		{
			int x;
			cin >> x;
			push_back(x);
		}
		if(s == "push_front")
		{
			int x;
			cin >> x;
			push_front(x);
		}
		if (s == "pop_back")
			cout << pop_back() << "\n";
		if (s == "pop_front")
			cout << pop_front() << "\n";
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

void push_front(int x)
{
	for (int i = d_rear; i > 0; i--)
		deq[i] = deq[i - 1];
	d_rear++;
	deq[0] = x;
}

void push_back(int x)
{
	deq[d_rear] = x;
	d_rear++;
}

int pop_front()
{
	if (d_rear == 0 || d_front == d_rear)
		return -1;

	int pop_value = deq[0];
	for (int i = 0; i < d_rear - 1; i++)
		deq[i] = deq[i + 1];

	d_rear--;
	if (d_front == 0)
		d_front = 0;
	else
		d_front--;

	return pop_value;
}

int pop_back()
{
	if (d_rear == 0 || d_front == d_rear)
		return -1;
	int pop_value = deq[d_rear - 1];
	d_rear--;

	return pop_value;
}

int size()
{
	return d_rear - d_front;
}

int empty()
{
	if (d_rear == 0 || d_front == d_rear)
		return 1;
	return 0;
}

int front()
{
	if (d_front == d_rear || d_rear == 0)
		return -1;
	return deq[0];
}

int back()
{
	if (d_front == d_rear || d_rear == 0)
		return -1;
	return deq[d_rear - 1];
}

/*
////////// STL ����ؼ� ����
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> D;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;


		if (s == "push_back")
		{
			int x;
			cin >> x;
			D.push_back(x);
		}
		if (s == "push_front")
		{
			int x;
			cin >> x;
			D.push_front(x);
		}
		if (s == "pop_back")
		{
			if (!D.empty())
			{
				cout << D.back() << "\n";
				D.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		if (s == "pop_front")
		{
			if (!D.empty())
			{
				cout << D.front() << "\n";
				D.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		if (s == "size")
			cout << D.size() << "\n";
		if (s == "empty")
			cout << D.empty() << "\n";
		if (s == "front")
		{
			if (D.empty())
				cout << -1 << "\n";
			else
				cout << D.front() << "\n";
		}
		if (s == "back")
		{
			if (D.empty())
				cout << -1 << "\n";
			else
				cout << D.back() << "\n";
		}
	}
}
*/

/*

����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. 
�־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.


���� �Է� 1
15
push_back 1
push_front 2
front
back
size
empty
pop_front
pop_back
pop_front
size
empty
pop_back
push_front 3
empty
front

���� ��� 1
2
1
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
22
front
back
pop_front
pop_back
push_front 1
front
pop_back
push_back 2
back
pop_front
push_front 10
push_front 333
front
back
pop_back
pop_back
push_back 20
push_back 1234
front
back
pop_back
pop_back

���� ��� 2
-1
-1
-1
-1
1
1
2
2
333
10
10
333
20
1234
1234
20


*/