#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int minVal, maxVal;

	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	minVal = arr[0];
	maxVal = arr[0];

	for (int i = 0; i < N; i++)
	{
		minVal = min(minVal, arr[i]);
		maxVal = max(maxVal, arr[i]);
	}
	cout << minVal << " " << maxVal << endl;

	delete[] arr;

	//// 동적 배열 출력
	//for (int i = 0; i < N; i++)
	//{
	//	cout << *(arr + i) << " ";
	//}
}

