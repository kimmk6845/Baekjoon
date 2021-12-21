#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

int* BubbleSort(int a[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	return a;
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
	int arr[MAX + 1];
	uniform_int_distribution<int> dis(-99, 99);
	for (int i = 0; i < MAX; i++)
		arr[i] = dis(gen);

	cout << "# ���� �Է°�" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	BubbleSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "�����ϴµ� �ɸ� �ð� : " << sec.count() << endl;
	CheckSort(arr, n);
}
