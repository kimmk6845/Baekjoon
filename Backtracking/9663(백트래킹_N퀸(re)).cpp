// 백트래킹의 가장 대표적 예제
#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

// col[i]는 x좌표, i는 y좌표
bool check(int level)
{
	for (int i = 0; i < level; i++)
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;	//대각선이거나 같은 라인
	return true;
}

void nqueen(int x)
{
	if (x == N)
		total++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[x] = i;		// 해당 위치에 퀸 배치
			if (check(x))	// 유효하다면 다음 행에 퀸 배치, 아니면 다른 위치로 배치 변경
				nqueen(x + 1);
		}
	}
}

int main()
{
	cin >> N;
	nqueen(0);
	cout << total;
}

// N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다. N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

// 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
// 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

/*

입력>>>
8

출력>>>
92

*/