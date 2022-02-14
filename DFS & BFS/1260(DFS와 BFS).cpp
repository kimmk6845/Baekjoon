#include <iostream>
#include <queue>    // BFS
using namespace std;
#define MAXSIZE 1001

int N, M, V;
int edge1, edge2;
bool graph[MAXSIZE][MAXSIZE]; // 간선 연결 = true
queue<int> bfs_queue;
bool bfs_visited[MAXSIZE];
bool dfs_vIsited[MAXSIZE];

void BFS(int node);
void DFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    for (int i = 1; i <= M; i++)
    {
        cin >> edge1 >> edge2;
        graph[edge1][edge2] = true;
        graph[edge2][edge1] = true;
    }



    DFS(V);     // 깊이우선탐색
    cout << "\n";
    BFS(V);     // 너비우선탐색
}

void BFS(int node)  // queue를 이용해 구현
{
    bfs_queue.push(node);
    bfs_visited[node] = true;

    while (!bfs_queue.empty())
    {
        int visit_node = bfs_queue.front();
        cout << visit_node << " ";

        for (int i = 1; i <= N; i++)
        {
            if (graph[visit_node][i])    // 방문한 정점과 연결된 정점이 있을 때
            {
                if (bfs_visited[i] == false)
                {
                    bfs_visited[i] = true;
                    bfs_queue.push(i);
                }
            }
        }

        bfs_queue.pop();    // 방문한 정점 제거
    }
}

void DFS(int node)  // 재귀를 이용해 구현
{
    dfs_vIsited[node] = true;
    cout << node << " ";

    for (int i = 1; i <= N; i++)
    {
        if (graph[node][i])
        {
            if (dfs_vIsited[i] == false)
            {
                dfs_vIsited[i] = true;
                DFS(i);
            }
        }
    }
}


/*

문제
그래프를 DFS(깊이우선탐색)로 탐색한 결과와 BFS(너비우선탐색)로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.
정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
입력으로 주어지는 간선은 양방향이다(트리 X, 그래프 O)

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다.
V부터 방문된 점을 순서대로 출력하면 된다.



예제 입력 1
4 5 1
1 2
1 3
1 4
2 4
3 4

예제 출력 1
1 2 4 3
1 2 3 4



예제 입력 2
5 5 3
5 4
5 2
1 2
3 4
3 1

예제 출력 2
3 1 2 5 4
3 1 4 2 5



예제 입력 3
1000 1 1000
999 1000

예제 출력 3
1000 999
1000 999

*/