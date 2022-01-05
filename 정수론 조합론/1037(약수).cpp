#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N = N�� ��� �� �ִ� * �ּڰ�

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int maxValue = *max_element(v.begin(), v.end());
	int minValue = *min_element(v.begin(), v.end());

	cout << maxValue * minValue << "\n";
}

/*


����
��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. 
��° �ٿ��� N�� ��¥ ����� �־�����. 1,000,000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.

���
ù° �ٿ� N�� ����Ѵ�. N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�.



���� �Է� 1
2
4 2
���� ��� 1
8


���� �Է� 2
1
2
���� ��� 2
4


���� �Է� 3
6
3 4 2 12 6 8
���� ��� 3
24


���� �Է� 4
14
14 26456 2 28 13228 3307 7 23149 8 6614 46298 56 4 92596
���� ��� 4
185192

*/