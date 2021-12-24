#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int arr[MAX];
bool IsVisit[MAX];
vector<int> v;
int n, m, cnt;

void DFS(int cnt) {		// 깊이우선탐색
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (IsVisit[i]) continue;

		IsVisit[i] = true;
		v.push_back(arr[i]);
		DFS(cnt + 1);
		v.pop_back();
		IsVisit[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
		IsVisit[i] = false;
	}

	DFS(0);
}

/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. 
>>> 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
첫째 줄에 자연수 N과 M이 주어진다. 
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

입력1>>>
3 1

출력1>>>
1
2
3

입력2>>>
4 2

출력2>>>
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3

입력3>>>
4 4

출력3>>>
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1

*/