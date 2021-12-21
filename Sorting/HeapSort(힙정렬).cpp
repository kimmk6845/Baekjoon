#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

void Heapify(int* a, int h, int m)
{
	// ��Ʈ h�� ������ h�� ���� ����Ʈ���� ������ ����Ʈ���� ����
	// ���� �������� ����� �ִ� ���� ���� ��ȣ�� m
	int v = a[h];
	int j = 2 * h;
	while (j <= m)
	{
		if (j < m && a[j] < a[j + 1])	// j�� ���� ū ���� or ������ �ڽĳ��
			j++;
		if (v >= a[j])
			break;
		else
			a[int(j / 2)] = a[j];	// a[j]�� �θ� ���� �̵�
		j *= 2;
	}
	a[int(j / 2)] = v;
}

void HeapSort(int* a, int n)
{
	for (int i = int(n / 2); i > 0; i--)	// a�� ������ ��ȯ
		Heapify(a, i, n);
	for (int i = n - 1; i > 0; i--)		// a�� ������������ ����
	{
		int temp;
		temp = a[1];	// a[1]�� ���� ū ����
		a[1] = a[i + 1];
		a[i + 1] = temp;
		Heapify(a, 1, i);
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

	//int n = 10;
	//int arr[10 + 1] = { -1,24,34,64,0,12,63,18,95,25,99 };
	//cout << "������ ������" << endl;
	//for (int i = 1; i < n + 1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;

	cout << "# ���� �Է°�" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	HeapSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "�����ϴµ� �ɸ� �ð� : " << sec.count() << endl;
	CheckSort(arr, n);

	//cout << "������ ������" << endl;
	//for (int i = 1; i < n + 1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;
}
