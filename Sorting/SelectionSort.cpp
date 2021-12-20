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
		cout << "정렬 완료" << endl;
	else
		cout << "정렬 오류 발생" << endl;
}

int main()
{
	random_device rd;	 // 시드값을 얻기 위한 random_device 생성
	mt19937 gen(rd());	// 난수 생성 엔진 초기화

	int n = MAX;
	int arr[MAX + 1];
	uniform_int_distribution<int> dis(-99, 99);		// -99부터 99까지 균등 분포 정의
	for (int i = 0; i < MAX; i++)
		arr[i] = dis(gen);

	cout << "# 랜덤 입력값" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	SelectionSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "정렬하는데 걸린 시간 : " << sec.count() << endl;
	CheckSort(arr, n);

}