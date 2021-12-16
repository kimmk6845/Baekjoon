#include <iostream>
#include <vector>
#include <numeric>	// accumulate
#include <algorithm>	// min_element
using namespace std;

int main()
{
	vector<int> v;
	int M, N;
	int cnt = 0;
	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 2)
			v.push_back(i);
		cnt = 0;
	}

	if (v.empty())
		cout << -1 << endl;
	else
	{
		cout << accumulate(v.begin(), v.end(), 0) << endl;
		cout << *min_element(v.begin(), v.end()) << endl;
	}
}

/*

����
�ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

���� ��� M=60, N=100�� ��� 60�̻� 100������ �ڿ��� �� �Ҽ��� 61, 67, 71, 73, 79, 83, 89, 97 �� 8���� �����Ƿ�, �̵� �Ҽ��� ���� 620�̰�, �ּڰ��� 61�� �ȴ�.

�Է�
�Է��� ù° �ٿ� M��, ��° �ٿ� N�� �־�����.

M�� N�� 10,000������ �ڿ����̸�, M�� N���� �۰ų� ����.

���
M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ã�� ù° �ٿ� �� ����, ��° �ٿ� �� �� �ּڰ��� ����Ѵ�.

��, M�̻� N������ �ڿ��� �� �Ҽ��� ���� ���� ù° �ٿ� -1�� ����Ѵ�.



���� �Է� 1
60
100
���� ��� 1
620
61


���� �Է� 2
64
65
���� ��� 2
-1

*/