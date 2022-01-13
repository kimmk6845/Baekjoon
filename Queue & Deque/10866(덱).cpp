#include <iostream>
#include <string>
#include <deque>
using namespace std;
#define MAX 10001


//////////////STL 사용하지 않고 Deque 구현
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
////////// STL 사용해서 구현
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

문제
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


예제 입력 1
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

예제 출력 1
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


예제 입력 2
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

예제 출력 2
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