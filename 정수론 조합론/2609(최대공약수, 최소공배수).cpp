#include <iostream>
using namespace std;

int gcd(int num1, int num2) // 최대공약수
{
	// 유클리드 호제법
	// a mod b = c --> b mod c = d --> c mod d = 0
	// ==> 최대 공약수는 d가 됨
	int mod = num1 % num2;
	while (mod)
	{
		num1 = num2;
		num2 = mod;
		mod = num1 % num2;
	}
	return num2;
}
int lcm(int num1, int num2)  // 최소공배수
{
	return num1 * num2 / gcd(num1, num2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2;
	cin >> num1 >> num2;

	cout << gcd(num1, num2) << "\n" << lcm(num1, num2) << "\n";
}

/*

문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.


예제 입력 1
24 18

예제 출력 1
6
72

*/