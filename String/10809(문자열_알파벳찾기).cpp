#include <iostream>
#include <string>
using namespace std;

int main()
{
	int c[26];
	fill(c, c + sizeof(c) / sizeof(int), -1); // -1로 초기화
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int idx = (int)s[i] - 97;

		if (c[idx] == -1)
			c[idx] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << c[i] << " ";
}


// 소문자 입력 받아 문자의 위치를 찾음.
// 처음 등장하는 위치를 저장하고, 없다면 -1