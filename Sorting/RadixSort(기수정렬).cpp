#include <iostream>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
#define MAX 15000

int GetRadix(int* a, int n) {

	int max_val = 0;
	for (int i = 0; i < n; i++) {
		if (max_val < a[i]) {
			max_val = a[i];
		}
	}

	int max_radix = 1;
	while (max_val / 10 > 0) {
		max_val /= 10;
		max_radix *= 10;
	}

	return max_radix;
}

void RadixSort(int* a, int n) {
	int m = GetRadix(a, n);

	queue<int> Q[10];

	for (int i = 1; i < m + 1; i *= 10) {
		for (int j = 0; j < n; j++) {
			int k = 0;
			if (a[j] >= i)
				k = (a[j] / i) % 10;

			Q[k].push(a[j]);
		}

		int idx = 0;
		for (int j = 0; j < 10; j++) {
			while (!Q[j].empty()) {
				a[idx] = Q[j].front();
				Q[j].pop();
				idx++;
			}
		}
	}
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
	int arr[MAX + 1] = { -1, };
	uniform_int_distribution<int> dis(1, 99);
	for (int i = 1; i < MAX; i++)
		arr[i] = dis(gen);

	cout << "# ���� �Է°�" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	RadixSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "�����ϴµ� �ɸ� �ð� : " << sec.count() << endl;
	CheckSort(arr, n);
}