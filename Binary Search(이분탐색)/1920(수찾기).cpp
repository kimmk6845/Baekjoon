#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> A;

int Binaray(int num);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.emplace_back(temp);
	}

	sort(A.begin(), A.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		cout << Binaray(num) << "\n";
	}
}

int Binaray(int num)
{
	int first = 0;
	int end = N - 1;

	while (end >= first)
	{
		int mid = (first + end) / 2;
		if (A[mid] == num)
			return 1;
		else if (A[mid] > num)
			end = mid - 1;
		else
			first = mid + 1;
	}
	return 0;
}

/*

����
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1 �� N �� 100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����.
���� �ٿ��� M(1 �� M �� 100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.

���
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.

���� �Է� 1
5
4 1 5 2 3
5
1 3 7 9 5
���� ��� 1
1
1
0
0
1

*/