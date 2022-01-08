#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int two_cnt = 0, five_cnt = 0;
	int result;
	for (int i = n; i >= 1; i--)
	{
		for (int j = i; i; j /= 2)
		{
			if (j % 2 == 0)
				two_cnt++;
			else break;		// 소인수 2가 더이상 없으면 탈출
		}

		for (int j = i; j; j /= 5)
		{
			if (j % 5 == 0)
				five_cnt++;
			else break; // 5없으면 탈출
		}
	}
	result = min(two_cnt, five_cnt);
	cout << result << "\n";
}

/*
소인수분해 -> 2와 5의 개수

문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.



예제 입력 1
10
예제 출력 1
2


예제 입력 2
3
예제 출력 2
0

*/