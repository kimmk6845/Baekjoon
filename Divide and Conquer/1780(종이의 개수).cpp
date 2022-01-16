#include <iostream>
using namespace std;
#define MAX 2187	// 3^7

int paper[MAX][MAX];
void solve(int x, int y, int size);
int cnt_mOne = 0, cnt_zero = 0, cnt_pOne = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solve(0, 0, n);
	cout << cnt_mOne << "\n" << cnt_zero << "\n" << cnt_pOne << "\n";
}

void solve(int x, int y, int size)
{
	bool minus_one = true, zero = true, plus_one = true;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] != -1)
				minus_one = false;
			if (paper[i][j] != 0)
				zero = false;
			if (paper[i][j] != 1)
				plus_one = false;

		}
	}
	if (minus_one)
	{
		cnt_mOne++;
		return;
	}
	if (zero)
	{
		cnt_zero++;
		return;
	}
	if (plus_one)
	{
		cnt_pOne++;
		return;
	}
	solve(x, y, size / 3);
	solve(x, y + size / 3, size / 3);
	solve(x, y + (2 * size / 3), size / 3);

	solve(x + size / 3, y, size / 3);
	solve(x + size / 3, y + size / 3, size / 3);
	solve(x + size / 3, y + (2 * size / 3), size / 3);

	solve(x + (2 * size / 3), y, size / 3);
	solve(x + (2 * size / 3), y + size / 3, size / 3);
	solve(x + (2 * size / 3), y + (2 * size / 3), size / 3);

}


/*

문제
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다.
우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

출력
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.



예제 입력 1
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1

예제 출력 1
10
12
11

*/