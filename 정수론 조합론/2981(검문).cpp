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

	// X(i) = M * ��(i) + ������
	// X(i-1) = M * ��(i-1) + ������
	// X(i) - X(i-1) = M(��(i) - ��(i-1)) --> ������ �Ұ�
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int differ = v[1] - v[0];
	for (int i = 2; i < N; i++) // X(i) - X(i-1)�� �ִ�����
		differ = gcd(differ, v[i] - v[i - 1]);

	vector<int> gcd_div;	// �ִ������� ���
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
	gcd_div.erase(remove(gcd_div.begin(), gcd_div.end(), 1));	  // 1���� ū M���̹Ƿ� 1�� ����
	sort(gcd_div.begin(), gcd_div.end());
	for (int i = 0; i < gcd_div.size(); i++)
		cout << gcd_div[i] << " ";
	cout << "\n";
}

/*

����
Ʈ���� Ÿ�� �̵��ϴ� ����̴� ������ �˹��� �ް� �Ǿ���.
������ ����̰� ����ϴ� ȭ���� �ϳ��ϳ� ��� Ȯ���� ���̱� ������, �˹��ϴµ� ��û���� ���� �ð��� �ɸ���.

����̴� �ð��� ����� ���ؼ� ���� ������ �ϱ�� �ߴ�.

���� ��ó�� ���̴� ���� N���� ���̿� ���´�. �� ����, ���̿� ���� ���� M���� �������� ��,
�������� ��� ���� �Ǵ� M�� ��� ã������ �Ѵ�. M�� 1���� Ŀ�� �Ѵ�.

N���� ���� �־����� ��, ������ M�� ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���̿� ���� ���� ���� N�� �־�����. (2 �� N �� 100)

���� �ٺ��� N�� �ٿ��� ���̿� ���� ���� �ϳ��� �־�����. �� ���� ��� 1���� ũ�ų� ����,
1,000,000,000���� �۰ų� ���� �ڿ����̴�. ���� ���� �� �� �̻� �־����� �ʴ´�.

�׻� M�� �ϳ� �̻� �����ϴ� ��츸 �Է����� �־�����.

���
ù° �ٿ� ������ M�� �������� �����Ͽ� ��� ����Ѵ�. �̶�, M�� �����ϴ� �����̾�� �Ѵ�.



���� �Է� 1
3
6
34
38
���� ��� 1
2 4


���� �Է� 2
5
5
17
23
14
83
���� ��� 2
3

*/