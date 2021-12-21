#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

int b[MAX];
void MergeSort(int* a, int l, int r)
{
	if (r > l)
	{
		int mid = (r + l) / 2;
		MergeSort(a, l, mid);
		MergeSort(a, mid + 1, r);

		// merge 과정
		int i, j, k;
		for (i = mid + 1; i > l; i--)
			b[i - 1] = a[i - 1];

		for (j = mid; j < r; j++)
			b[r + mid - j] = a[j + 1];

		for (k = l; k < r + 1; k++)
		{
			if (b[i] < b[j])
			{
				a[k] = b[i];
				i++;
			}
			else
			{
				a[k] = b[j];
				j--;
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
		cout << "정렬 완료" << endl;
	else
		cout << "정렬 오류 발생" << endl;
}

int main()
{
	random_device rd;
	mt19937 gen(rd());

	//int n = MAX;
	//int arr[MAX + 1] = { -1, };
	//uniform_int_distribution<int> dis(1, 99);
	//for (int i = 1; i < MAX; i++)
	//	arr[i] = dis(gen);

	int n = 10;
	int arr[10 + 1] = { -1,24,34,64,0,12,63,18,95,25,99 };
	cout << "정렬전 데이터" << endl;
	for (int i = 1; i < n+1; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	cout << "# 랜덤 입력값" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	MergeSort(arr, 1, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "정렬하는데 걸린 시간 : " << sec.count() << endl;
	CheckSort(arr, n);

	cout << "정렬후 데이터" << endl;
	for (int i = 1; i < n+1; i++)
		cout << arr[i] << " ";
	cout << endl << endl;
}
