#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	vector<int> v;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
		v.push_back(s[i] - '0');

	sort(v.begin(), v.end());

	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
}

// sort 내림차순 정렬을 이용

/*

#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	string str;
	cin>>str;
	sort(str.begin(), str.end(), greater<char>());
	cout<<str;
}

*/

/*
문제
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

입력
첫째 줄에 정렬하려고 하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.



예제 입력 1
2143
예제 출력 1
4321


예제 입력 2
999998999
예제 출력 2
999999998


예제 입력 3
61423
예제 출력 3
64321


예제 입력 4
500613009
예제 출력 4
965310000
*/