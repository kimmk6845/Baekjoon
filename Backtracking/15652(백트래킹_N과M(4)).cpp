#include <iostream>
#define MAX 9
using namespace std;

int arr[MAX];
bool IsVisit[MAX];
int n, m;

void dfs(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++)
	{
		IsVisit[i] = true;
		arr[cnt] = i;
		dfs(i, cnt + 1);
		IsVisit[i] = false;
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}

// 비내림차순
// 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

/*

예제 입력 1
3 1
예제 출력 1
1
2
3


예제 입력 2
4 2
예제 출력 2
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4

*/