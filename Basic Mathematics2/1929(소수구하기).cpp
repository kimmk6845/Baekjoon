#include <iostream>
using namespace std;

bool IsPrime(int x)
{
	if (x ==0 || x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = m; i < n + 1; i++)
	{
		if (IsPrime(i))
			cout << i << "\n";
	}
}

/*

# 시간제한 2초

문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. 
(1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.


예제 입력 1
3 16

예제 출력 1
3
5
7
11
13

*/