#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 101

int n, m;   // n: 정점 m:간선
bool graph[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE];
queue<int> bfs_queue;
int cnt;    // 바이러스에 걸리는 컴퓨터 수

void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int edge1, edge2;
        cin >> edge1 >> edge2;
        graph[edge1][edge2] = true;
        graph[edge2][edge1] = true;
    }

    BFS(1);     // 1번 컴퓨터 바이러스
    cout << cnt << "\n";
}

void BFS(int node)
{
    bfs_queue.push(node);
    visited[node] = true;

    while (!bfs_queue.empty())
    {
        int visit_node = bfs_queue.front();
        for (int i = 1; i <= n; i++)
        {
            if (graph[visit_node][i])
            {
                if (!visited[i])
                {
                    cnt++;
                    visited[i] = true;
                    bfs_queue.push(i);
                }
            }
        }
        bfs_queue.pop();
    }
}

/*

문제
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다.
한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자.
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다.
하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

    1---2----3     4
    |  /          /
    | /          /
    5---6       7

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다.
컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다.
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다.
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

예제 입력 1
7
6
1 2
2 3
1 5
5 2
5 6
4 7
예제 출력 1
4

*/