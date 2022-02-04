#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> heap;	// 최소힙 만들기
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (temp == 0)
		{
			if (heap.empty())
				cout << 0 << "\n";
			else
			{
				cout << heap.top() << "\n";
				heap.pop();
			}
		}
		else
			heap.push(temp);
	}

}
