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
        edge[u].push_back(make_pair(w, v));     // (����, ���, ����)
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
    q.push(make_pair(0, start));    // start���� start�� ���� ���, ���

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

����
����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, ��� ������ ����ġ�� 10 ������ �ڿ����̴�.

�Է�
ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����.
(1 �� V �� 20,000, 1 �� E �� 300,000) ��� �������� 1���� V���� ��ȣ�� �Ű��� �ִٰ� �����Ѵ�.
��° �ٿ��� ���� ������ ��ȣ K(1 �� K �� V)�� �־�����.
��° �ٺ��� E���� �ٿ� ���� �� ������ ��Ÿ���� �� ���� ���� (u, v, w)�� ������� �־�����. �̴� u���� v�� ���� ����ġ w�� ������ �����Ѵٴ� ���̴�.
u�� v�� ���� �ٸ��� w�� 10 ������ �ڿ����̴�.
���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ������ �����Ѵ�.

���
ù° �ٺ��� V���� �ٿ� ����, i��° �ٿ� i�� ���������� �ִ� ����� ��ΰ��� ����Ѵ�.
������ �ڽ��� 0���� ����ϰ�, ��ΰ� �������� �ʴ� ��쿡�� INF�� ����ϸ� �ȴ�.

���� �Է� 1
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
���� ��� 1
0
2
3
7
INF

*/