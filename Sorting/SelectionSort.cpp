#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

int *SelectionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minidx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minidx])
				minidx = j;
		}
		int temp;
		temp = a[i];
		a[i] = a[minidx];
		a[minidx] = temp;
	}
	return a;
}

void CheckSort(int a[], int n)
{
	bool isSorted = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i+1])
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
	random_device rd;	 // �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());	// ���� ���� ���� �ʱ�ȭ

	int n = MAX;
	int arr[MAX + 1];
	uniform_int_distribution<int> dis(-99, 99);		// -99���� 99���� �յ� ���� ����
	for (int i = 0; i < MAX; i++)
		arr[i] = dis(gen);

	cout << "# ���� �Է°�" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	SelectionSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "�����ϴµ� �ɸ� �ð� : " << sec.count() << endl;
	CheckSort(arr, n);

}