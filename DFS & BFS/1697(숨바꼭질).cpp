#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 100001

int N, K;
bool pos[MAXSIZE];

int BFS();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    pos[N] = true;
    cout << BFS() << "\n";

}

int BFS()
{
    queue<pair<int, int>> q;     // 위치, 시간
    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        int next_x = q.front().first;
        int cnt = q.front().second;
        vector<int> next_visit{ next_x + 1, next_x * 2, next_x - 1 };

        q.pop();

        if (next_x == K)
            return cnt;

        for (int i = 0; i < 2; i++)
        {
            next_x = next_visit[i];
            if (next_x < MAXSIZE && !pos[next_x])
            {
                q.push(make_pair(next_x, cnt + 1));
                pos[next_x] = true;
            }
        }

        next_x = next_visit[2];     // 음수 이동
        if (next_x >= 0 && !pos[next_x])
        {
            q.push(make_pair(next_x, cnt + 1));
            pos[next_x] = true;
        }

    }
}

/*

문제
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.



예제 입력 1
5 17

예제 출력 1
4


**힌트**
수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.

*/