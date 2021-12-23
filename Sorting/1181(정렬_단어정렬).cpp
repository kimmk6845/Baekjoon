#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;		// 사전순서

	return s1.size() < s2.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> v;
	vector<string>::iterator iter;
	vector<string>::iterator end_iter;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);
	end_iter = unique(v.begin(), v.end());
	for (iter = v.begin(); iter != end_iter; iter++)
		cout << *iter << "\n";

}

/*

길이가 짧은 것 우선, 길이 같으면 사전순서

입력: 첫째 줄에 단어의 개수 N이 주어진다. 
(1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
주어지는 문자열의 길이는 50을 넘지 않는다.

출력: 조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.


입력>>>
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours


출력>>>
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate

*/