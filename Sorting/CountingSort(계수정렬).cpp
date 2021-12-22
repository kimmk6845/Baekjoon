#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000
#define NUM_RANGE 1000

void CountingSort(int* a, int n, int m)
{
	int b[MAX + 1] = { 0, };
	int count[NUM_RANGE + 1] = { 0, };
	for (int i = 1; i <= n; i++)
		count[a[i]]++;					// ���� ���� ����
	for (int i = 2; i <= m; i++)
		count[i] += count[i - 1];		// ���Ұ� �� ��ġ ���
	for (int i = n; i >= 1; i--) {
		b[count[a[i]]] = a[i];
		count[a[i]]--;
	}
	for (int i = 1; i <= n; i++)
		a[i] = b[i];
}

void CheckSort(int a[], int n)
{
	bool isSorted = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			isSorted = false;
		if (!isSorted)
			break;
	}

	if (isSorted)
		cout << "���� �Ϸ�" << endl;
	else
		cout << "���� ���� �߻�" << endl;
}

int main()
{
	random_device rd;
	mt19937 gen(rd());

	int n = MAX;
	int m = NUM_RANGE;
	int arr[MAX + 1] = { -1, };
	uniform_int_distribution<int> dis(1, m);
	for (int i = 1; i < MAX; i++)
		arr[i] = dis(gen);

	cout << "# ���� �Է°�" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	CountingSort(arr, n, m);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "�����ϴµ� �ɸ� �ð� : " << sec.count() << endl;
	CheckSort(arr, n);
}
