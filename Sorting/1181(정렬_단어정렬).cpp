#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;		// ��������

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

���̰� ª�� �� �켱, ���� ������ ��������

�Է�: ù° �ٿ� �ܾ��� ���� N�� �־�����. 
(1 �� N �� 20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. 
�־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

���: ���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.


�Է�>>>
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


���>>>
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