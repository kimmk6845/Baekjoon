#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<long long, long long>> v;
void PushVector(long long num)
{
	long long two_cnt = 0, five_cnt = 0;
	for (long long i = 2; i <= num; i *= 2)
		two_cnt += num / i;
	for (long long i = 5; i <= num; i *= 5)
		five_cnt += num / i;
	v.emplace_back(make_pair(two_cnt, five_cnt));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	cin >> n >> m;

	long long two_cnt = 0, five_cnt = 0;
	long long result;
	PushVector(n);
	PushVector(m);
	PushVector(n - m);

	two_cnt = v[0].first - v[1].first - v[2].first;
	five_cnt = v[0].second - v[1].second - v[2].second;
	result = min(two_cnt, five_cnt);
	cout << result << "\n";
}

/*
(n k) = 0            (k < 0)
		n!/k!(n-k)!  (0<=k<=n)
		0            (k > n

n!�� ���μ� 2,5�� ������ k!�� ���μ� ������ (n-k)!�� ���μ� ������ ����
)*/

/*

����
(n m)�� ���ڸ� 0�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� n, m (0 <= m <= n <= 2,000,000,000 ,  n != 0)�� ���´�.

���
ù° �ٿ�
(n m)�� ���ڸ� 0�� ������ ����Ѵ�.


���� �Է� 1
25 12

���� ��� 1
2

*/