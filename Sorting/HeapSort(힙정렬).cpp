#include <iostream>
#include <random>
#include <chrono>
using namespace std;
#define MAX 15000

void Heapify(int* a, int h, int m)
{
	// 루트 h를 제외한 h의 왼쪽 서브트리와 오른쪽 서브트리는 히프
	// 현재 시점으로 노드의 최대 레벨 순서 번호는 m
	int v = a[h];
	int j = 2 * h;
	while (j <= m)
	{
		if (j < m && a[j] < a[j + 1])	// j는 값이 큰 왼쪽 or 오른쪽 자식노드
			j++;
		if (v >= a[j])
			break;
		else
			a[int(j / 2)] = a[j];	// a[j]를 부모 노드로 이동
		j *= 2;
	}
	a[int(j / 2)] = v;
}

void HeapSort(int* a, int n)
{
	for (int i = int(n / 2); i > 0; i--)	// a를 히프로 변환
		Heapify(a, i, n);
	for (int i = n - 1; i > 0; i--)		// a를 오름차순으로 정렬
	{
		int temp;
		temp = a[1];	// a[1]은 제일 큰 원소
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
	//for (int i = 1; i < n + 1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;

	cout << "# 랜덤 입력값" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	HeapSort(arr, n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	cout << "정렬하는데 걸린 시간 : " << sec.count() << endl;
	CheckSort(arr, n);

	//cout << "정렬후 데이터" << endl;
	//for (int i = 1; i < n + 1; i++)
	//	cout << arr[i] << " ";
	//cout << endl << endl;
}
