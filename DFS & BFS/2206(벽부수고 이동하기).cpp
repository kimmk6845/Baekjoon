#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define MAXSIZE 1000

int N, M;
int maps[MAXSIZE][MAXSIZE];
int dist[MAXSIZE][MAXSIZE][2];

int BFS(int h,int w);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
            maps[i][j] = s[j] - '0';
    }

    dist[0][0][1] = 1;
    cout << BFS(0, 0) << "\n";
}

vector<pair<int, int>> next_visit{ {1,0},{0,1},{-1,0},{0,-1} };
int BFS(int h,int w)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(h, w), 1));

    while (!q.empty())
    {
        int temp_h = q.front().first.first;
        int temp_w = q.front().first.second;
        int chance = q.front().second;  // 부술 수 있는 기회

        if (temp_h == N - 1 && temp_w == M - 1)
            return dist[temp_h][temp_w][chance];

        for (int i = 0; i < 4; i++)
        {
            int next_h = temp_h + next_visit[i].first;
            int next_w = temp_w + next_visit[i].second;

            if (next_h >= 0 && next_w >= 0 && next_h < N && next_w < M)
            {
                if (maps[next_h][next_w] == 1 && chance == 1)
                {
                    dist[next_h][next_w][chance - 1] = dist[temp_h][temp_w][chance] + 1;
                    q.push(make_pair(make_pair(next_h, next_w), 0));
                }

                if (maps[next_h][next_w] == 0 && dist[next_h][next_w][chance] == 0)
                {
                    dist[next_h][next_w][chance] = dist[temp_h][temp_w][chance] + 1;
                    q.push(make_pair(make_pair(next_h, next_w), chance));
                }
            }
        }
        q.pop();
    }

    return -1;
}

// dist배열을 3차원으로 만드는 이유는 부수고 갈 때와 부수지 않고 갈 때를 나눠주기 위함
// 입력>> 6 4
// 0000
// 1110
// 1000
// 0000
// 0111 *
// 0000
// 이와 같은 입력이 들어오면 5행의 우측 1을 부수고 지나가는 것이 빠름

/*

문제
N×M의 행렬로 표현되는 맵이 있다.
맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다.
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.




예제 입력 1
6 4
0100
1110
1000
0000
0111
0000

예제 출력 1
15



예제 입력 2
4 4
0111
1111
1111
1110

예제 출력 2
-1

*/