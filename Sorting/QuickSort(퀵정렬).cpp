#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

void QuickSort(int* a, int l, int r)
{
	int temp;

	// �迭 a[]�� �κ� �迭 a[l:r]�� ������������ ����
	if (r > l)
	{
		int v = a[r];	// ���� ������ ���� �Ǻ�
		int i = l - 1;	// �¿��� ��� �����̴� ������
		int j = r;		// �쿡�� �·� ...
		while (1)
		{
			do {
				i++;
			} while (a[i] < v);		// �Ǻ������� ������ i�� ����
			
			do {
				j--;
			} while (a[j] > v);		// �Ǻ������� ũ�� j�� ����

			if (i >= j)
				break;

			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		temp = a[i];
		a[i] = a[r];
		a[r] = temp;

		QuickSort(a, l, i - 1);
		QuickSort(a, i + 1, r);
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
	//for (int i = 1; i < n+1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;

	cout << "# ���� �Է°�" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	QuickSort(arr, 1, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "�����ϴµ� �ɸ� �ð� : " << sec.count() << endl;
	CheckSort(arr, n);

	//cout << "������ ������" << endl;
	//for (int i = 1; i < n+1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;
}
