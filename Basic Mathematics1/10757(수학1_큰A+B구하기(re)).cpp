#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, sum;
int num1[10001], num2[10001];
string s1, s2, tmp;
vector<int> ans;

int main()
{
	cin >> s1 >> s2;

	// 더 긴 수를 s1으로 저장하기
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	// num1, num2 배열을 만드는 과정
	for (int i = 0; i < s1.size(); i++)
		num1[i + 1] = s1[i] - '0';

	for (int i = 0; i < s2.size(); i++)
		num2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0';

	// num배열들의 끝부분부터 덧셈을 하면서 ans벡터에 값 저장
	for (int i = s1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum >= 10)
		{
			num1[i - 1]++;
			sum -= 10;
		}
		ans.push_back(sum);
	}

	// 맨 앞자리수 출력
	if (num1[0] != 0) cout << 1;

	// ans벡터 거꾸로 출력
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}

}

// int형의 범위를 넘어가는 수의 덧셈

/*

문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

출력
첫째 줄에 A+B를 출력한다.



예제 입력 1
9223372036854775807 9223372036854775808

예제 출력 1
18446744073709551615

*/