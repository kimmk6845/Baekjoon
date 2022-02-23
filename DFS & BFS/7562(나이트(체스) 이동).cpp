#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 300

int l;  // L
int px, py, nx, ny;     // 현재 있는 위치, 이동하려는 위치
bool maps[MAXSIZE][MAXSIZE];

int BFS(int y, int x);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> l;
        cin >> px >> py >> nx >> ny;

        memset(maps, 0, sizeof(maps));

        cout << BFS(py, px) << "\n";
    }

}

vector<pair<int, int>> next_visit{ {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };   // 나이트 이동 반경
int BFS(int y, int x)
{
    maps[y][x] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(y, x), 0));

    while (!q.empty())
    {
        int temp_y = q.front().first.first;
        int temp_x = q.front().first.second;
        int move = q.front().second;
        q.pop();

        if (temp_x == nx && temp_y == ny)
            return move;

        for (int i = 0; i < 8; i++)
        {
            int next_y = temp_y + next_visit[i].first;
            int next_x = temp_x + next_visit[i].second;
            if (next_y >= 0 && next_x >= 0 && next_y < l && next_x < l)
            {
                if (!maps[next_y][next_x])
                {
                    maps[next_y][next_x] = true;
                    q.push(make_pair(make_pair(next_y, next_x), move + 1));
                }
            }
        }
    }
}

/*

문제
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 
나이트가 이동하려고 하는 칸이 주어진다. 
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?



입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 
체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.

예제 입력 1
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
예제 출력 1
5
28
0

*/