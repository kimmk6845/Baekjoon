#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v.push_back(make_pair(n1, n2));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
}

/*

��ǥ �����ϱ�
2���� ��� ���� �� N���� �־�����. 
��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�: ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

���: ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.


�Է�>>>
5
3 4
1 1
1 -1
2 2
3 3

���>>>
1 -1
1 1
2 2
3 3
3 4

*/