#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXSIZE 20000
#define INF 10000000

int V, E, K;
int dist[MAXSIZE + 1];
vector<pair<int, int>> edge[MAXSIZE + 1];

void dijkstra(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(w, v));     // (시작, 비용, 도착)
    }

    dijkstra(K);
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));    // start에서 start로 가는 비용, 경로

    while (!q.empty())
    {
        int cost = -q.top().first;
        int current_node = q.top().second;
        q.pop();

        if (dist[current_node] >= cost)
        {
            for (int i = 0; i < edge[current_node].size(); i++)
            {
                int next = edge[current_node][i].second;
                int next_cost = cost + edge[current_node][i].first;

                if (dist[next] > next_cost)
                {
                    dist[next] = next_cost;
                    q.push(make_pair(-next_cost, next));
                }
            }
        }
    }
}

/*

문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오.
단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다.
(1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다.
둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다.
셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다.
u와 v는 서로 다르며 w는 10 이하의 자연수이다.
서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다.
시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

예제 입력 1
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1
0
2
3
7
INF

*/