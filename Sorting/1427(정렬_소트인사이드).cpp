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

// sort �������� ������ �̿�

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
����
�迭�� �����ϴ� ���� ����. ���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.

�Է�
ù° �ٿ� �����Ϸ��� �ϴ� �� N�� �־�����. N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.



���� �Է� 1
2143
���� ��� 1
4321


���� �Է� 2
999998999
���� ��� 2
999999998


���� �Է� 3
61423
���� ��� 3
64321


���� �Է� 4
500613009
���� ��� 4
965310000
*/