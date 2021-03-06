#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define MAXSIZE 10001

//// STL사용하지 않고 STACK구현
int stk[MAXSIZE];
int stk_s = 0;	// 스택크기

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


//// STL을 이용해 요구 조건 만족시키기
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

문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. (만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.)
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.



예제 입력 1
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

예제 출력 1
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



예제 입력 2
7
pop
top
push 123
top
pop
top
pop

예제 출력 2
-1
-1
123
123
-1
-1

*/