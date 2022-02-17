// 최단거리 = BFS
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 100

int N, M;
int graph[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int cnt[MAXSIZE][MAXSIZE];

void BFS(int w, int h);

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
            graph[i][j] = s[j] - '0';
    }

    cnt[0][0]++;
    BFS(0, 0);
    cout << cnt[N - 1][M - 1] << "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << cnt[i][j] << " ";
        cout << endl;
    }
}


vector<pair<int, int>> next_visit{ {1,0},{-1,0},{0,1},{0,-1} };
void BFS(int w, int h)
{
    queue<pair<int, int>> q;
    q.push(make_pair(w, h));

    while (!q.empty())
    {
        int temp_w = q.front().first;
        int temp_h = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            int next_w = temp_w + next_visit[i].first;
            int next_h = temp_h + next_visit[i].second;
            if (next_w >= 0 && next_h >= 0 && next_w < N && next_h < M)
            {
                if (graph[next_w][next_h] == 1 && !visited[next_w][next_h])
                {
                    visited[next_w][next_h] = true;
                    cnt[next_w][next_h] = cnt[temp_w][temp_h] + 1;
                    q.push(make_pair(next_w, next_h));
                }
            }
        }
        q.pop();
    }
}

/*

문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.



예제 입력 1
4 6
101111
101010
101011
111011

예제 출력 1
15




예제 입력 2
4 6
110110
110110
111111
111101

예제 출력 2
9




예제 입력 3
2 25
1011101110111011101110111
1110111011101110111011101

예제 출력 3
38




예제 입력 4
7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111

예제 출력 4
13

*/