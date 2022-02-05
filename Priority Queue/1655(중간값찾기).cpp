#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		// �ִ����� ũ�Ⱑ �ּ������� 1��ŭ ũ�ų� ���ƾ� ��
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(temp);
		else
			minHeap.push(temp);

		// �ִ����� top�� �ּ����� top���� �۾ƾ� �� --> �߰��� ã�� ����
		// ���� ����
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top())
		{
			int num1 = maxHeap.top();
			int num2 = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(num2);
			minHeap.push(num1);
		}

		// �ִ����� top�� �߰���
		cout << maxHeap.top() << "\n";
	}
}

/*

����
�����̴� �������� "����� ���ؿ�" ������ �������ְ� �ִ�.
�����̰� ������ �ϳ��� ��ĥ������ ������ ���ݱ��� �����̰� ���� �� �߿��� �߰����� ���ؾ� �Ѵ�.
����, �׵��� �����̰� ��ģ ���� ������ ¦������� �߰��� �ִ� �� �� �߿��� ���� ���� ���ؾ� �Ѵ�.

���� ��� �����̰� �������� 1, 5, 2, 10, -99, 7, 5�� ������� ���ƴٰ� �ϸ�, ������ 1, 1, 2, 2, 2, 2, 5�� ���ʴ�� ���ؾ� �Ѵ�.
�����̰� ��ġ�� ���� �־����� ��, ������ ���ؾ� �ϴ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �����̰� ��ġ�� ������ ���� N�� �־�����. N�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����̴�.
�� ���� N�ٿ� ���ļ� �����̰� ��ġ�� ������ ���ʴ�� �־�����. ������ -10,000���� ũ�ų� ����, 10,000���� �۰ų� ����.

���
�� �ٿ� �ϳ��� N�ٿ� ���� �������� ������ ���ؾ� �ϴ� ���� ������� ����Ѵ�.

���� �Է� 1
7
1
5
2
10
-99
7
5
���� ��� 1
1
1
2
2
2
2
5

*/