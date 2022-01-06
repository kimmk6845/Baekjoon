#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int num1, int num2)
{
	int mod = num1 % num2;
	while (mod)
	{
		num1 = num2;
		num2 = mod;
		mod = num1 % num2;
	}
	return num2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// X(i) = M * 몫(i) + 나머지
	// X(i-1) = M * 몫(i-1) + 나머지
	// X(i) - X(i-1) = M(몫(i) - 몫(i-1)) --> 나머지 소거
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int differ = v[1] - v[0];
	for (int i = 2; i < N; i++) // X(i) - X(i-1)의 최대공약수
		differ = gcd(differ, v[i] - v[i - 1]);

	vector<int> gcd_div;	// 최대공약수의 약수
	for (int i = 1; i <= differ; i++)
	{
		if (differ % i == 0)
		{
			if (i > differ / i)
				break;
			gcd_div.push_back(i);

			if (i == differ / i)
				break;
			gcd_div.push_back(differ / i);
		}
	}
	gcd_div.erase(remove(gcd_div.begin(), gcd_div.end(), 1));	  // 1보다 큰 M값이므로 1은 제거
	sort(gcd_div.begin(), gcd_div.end());
	for (int i = 0; i < gcd_div.size(); i++)
		cout << gcd_div[i] << " ";
	cout << "\n";
}

/*

문제
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다.
경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때,
나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

입력
첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)

다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고,
1,000,000,000보다 작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.

항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

출력
첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.



예제 입력 1
3
6
34
38
예제 출력 1
2 4


예제 입력 2
5
5
17
23
14
83
예제 출력 2
3

*/