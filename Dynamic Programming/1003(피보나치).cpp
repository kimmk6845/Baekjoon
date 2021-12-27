#include <iostream>
using namespace std;

int fibo[50] = { 0,1, };

int fibonacci(int n)
{
	if (n == 0 || n == 1)
		return fibo[n];
	else if (fibo[n] == 0)
		fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return fibo[n];
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
			cout << "1 0" << "\n";
		else
			cout << fibonacci(num-1) << " " << fibonacci(num) << "\n";
	}
}

// 피보나치의 0과 1이 나오는 횟수를 구하는 프로그램
// 시간 제한 0.25초

/*
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.



예제 입력 1
3
0
1
3

예제 출력 1
1 0
0 1
1 2


예제 입력 2
2
6
22

예제 출력 2
5 8
10946 17711

*/