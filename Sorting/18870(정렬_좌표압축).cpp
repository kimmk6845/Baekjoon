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

	//// 시간초과
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
		auto it = lower_bound(v2.begin(), v2.end(), v[i]);	// i번째 요소값의 위치 it
		cout << it - v2.begin() << ' ';        // it에서 v2벡터의 시작 주소값을 빼준 값이 답
	}
}

/*
문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

제한
1 ≤ N ≤ 1,000,000
-10^9 ≤ Xi ≤ 10^9


예제 입력 1
5
2 4 -10 4 -9

예제 출력 1
2 3 0 3 1


예제 입력 2
6
1000 999 1000 999 1000 999

예제 출력 2
1 0 1 0 1 0

*/
