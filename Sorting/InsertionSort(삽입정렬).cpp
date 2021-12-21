#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

int* InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int v = a[i];	// 임시 저장소에 저장
		int j = i;
		while (a[j - 1] > v)
		{
			a[j] = a[j - 1];	// 오른쪽으로 한 자리씩 이동시켜 빈자리 만듦
			j--;
		}
		a[j] = v;	// 빈자리에 삽입
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
	int arr[MAX + 1];
	uniform_int_distribution<int> dis(-99, 99);
	for (int i = 0; i < MAX; i++)
		arr[i] = dis(gen);

	cout << "# 랜덤 입력값" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	InsertionSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "정렬하는데 걸린 시간 : " << sec.count() << endl;
	CheckSort(arr, n);

}