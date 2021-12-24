#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int arr[MAX];
bool IsVisit[MAX];
vector<int> v;
int n, m, cnt;

void DFS(int cnt) {		// ���̿켱Ž��
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
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
>>> 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
ù° �ٿ� �ڿ��� N�� M�� �־�����. 
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.

�Է�1>>>
3 1

���1>>>
1
2
3

�Է�2>>>
4 2

���2>>>
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

�Է�3>>>
4 4

���3>>>
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