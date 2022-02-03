/*

����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.

���� �Է� 1
6
10 20 10 30 20 50
���� ��� 1
4

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> result;
	for (int i = 0; i < N; i++)
		cin >> v[i];

	result.push_back(v[0]);
	for (int i = 1; i < N; i++)
	{
		if (result.back() < v[i])
			result.push_back(v[i]);
		else
		{
			auto iter = lower_bound(result.begin(), result.end(), v[i]);
			*iter = v[i];
		}
	}

	cout << result.size() << "\n";
}
