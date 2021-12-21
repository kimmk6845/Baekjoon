#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

void QuickSort(int* a, int l, int r)
{
	int temp;

	// 배열 a[]의 부분 배열 a[l:r]을 오름차순으로 정렬
	if (r > l)
	{
		int v = a[r];	// 가장 오른쪽 원소 피봇
		int i = l - 1;	// 좌에서 우로 움직이는 포인터
		int j = r;		// 우에서 좌로 ...
		while (1)
		{
			do {
				i++;
			} while (a[i] < v);		// 피봇값보다 작으면 i값 증가
			
			do {
				j--;
			} while (a[j] > v);		// 피봇값보다 크면 j값 감소

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
	QuickSort(arr, 1, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "정렬하는데 걸린 시간 : " << sec.count() << endl;
	CheckSort(arr, n);

	//cout << "정렬후 데이터" << endl;
	//for (int i = 1; i < n+1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;
}
