#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> v2(v);
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	//// �ð��ʰ�
	//for (int i = 0; i < n; i++)
	//{
	//	int cnt = 0;
	//	for (int j = 0; j < v2.size(); j++)
	//	{
	//		if (v[i] > v2[j])
	//			cnt++;
	//	}
	//	cout << cnt << " ";
	//}

	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(v2.begin(), v2.end(), v[i]);	// i��° ��Ұ��� ��ġ it
		cout << it - v2.begin() << ' ';        // it���� v2������ ���� �ּҰ��� ���� ���� ��
	}
}

/*
����
������ ���� N���� ��ǥ X1, X2, ..., XN�� �ִ�. �� ��ǥ�� ��ǥ ������ �����Ϸ��� �Ѵ�.

Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.

X1, X2, ..., XN�� ��ǥ ������ ������ ��� X'1, X'2, ..., X'N�� ����غ���.

�Է�
ù° �ٿ� N�� �־�����.

��° �ٿ��� ���� �� ĭ���� ���е� X1, X2, ..., XN�� �־�����.

���
ù° �ٿ� X'1, X'2, ..., X'N�� ���� �� ĭ���� �����ؼ� ����Ѵ�.

����
1 �� N �� 1,000,000
-10^9 �� Xi �� 10^9


���� �Է� 1
5
2 4 -10 4 -9

���� ��� 1
2 3 0 3 1


���� �Է� 2
6
1000 999 1000 999 1000 999

���� ��� 2
1 0 1 0 1 0

*/
