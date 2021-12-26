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

// �񳻸�����
// ���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

/*

���� �Է� 1
3 1
���� ��� 1
1
2
3


���� �Է� 2
4 2
���� ��� 2
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