#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

int* ShellSort(int a[], int n)
{
	int h = 1;
	while (h < n)
		h = 3 * h + 1;
	while (h > 0)
	{
		for (int i = h + 1; i < n + 1; i++)
		{
			int v = a[i];
			int j = i;
			while (j > h && a[j - h] > v)
			{
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = v;
		}
		h /= 3;
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
		cout << "정렬 완료" << endl;
	else
		cout << "정렬 오류 발생" << endl;
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
	//cout << "정렬전 데이터" << endl;
	//for (int i = 1; i < n+1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;

	cout << "# 랜덤 입력값" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	ShellSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "정렬하는데 걸린 시간 : " << sec.count() << endl;
	CheckSort(arr, n);

	//cout << "정렬후 데이터" << endl;
	//for (int i = 1; i < n+1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;
}
