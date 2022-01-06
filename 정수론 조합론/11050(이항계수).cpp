#include <iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int result = factorial(N) / (factorial(K) * factorial(N - K));
	cout << result << "\n";
}

/*
이항계수
(n k) = 0            (k < 0)
		n!/k!(n-k)!  (0<=k<=n)
		0            (k > n)
*/

/*

문제
자연수 N과 정수 K가 주어졌을 때 이항 계수
(N K)를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

출력

(N K)를 출력한다.


예제 입력 1
5 2

예제 출력 1
10

*/