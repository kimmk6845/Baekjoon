#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXSIZE 20000

int V, E;
vector<int> graph[MAXSIZE + 1];
int visit[MAXSIZE + 1];

void DFS(int start, int color);
bool isBipartiteGraph(void);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> V >> E;

        for (int j = 1; j <= V; j++)
            graph[j].clear();
        memset(visit, 0, sizeof(visit));


        for (int j = 0; j < E; j++)
        {
            int e1, e2;
            cin >> e1 >> e2;
            graph[e1].push_back(e2);
            graph[e2].push_back(e1);
        }

        for (int j = 1; j <= V; j++)
            if (visit[j] == 0)
                DFS(j, 1);


        if (isBipartiteGraph())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

void DFS(int start, int color)
{
    visit[start] = color;
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (!visit[next])
            DFS(next, 3 - color);
    }
}

bool isBipartiteGraph(void)
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];
            if (visit[i] == visit[next])
                return 0;
        }
    }
    return 1;
}

/*

����
�׷����� ������ ������ �ѷ� �����Ͽ�, �� ���տ� ���� ���������� ���� �������� �ʵ��� ������ �� ���� ��, �׷��� �׷����� Ư���� �̺� �׷��� (Bipartite Graph)�� �θ���.

�׷����� �Է����� �־����� ��, �� �׷����� �̺� �׷������� �ƴ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �����Ǿ� �ִµ�, ù° �ٿ� �׽�Ʈ ���̽��� ���� K�� �־�����.
�� �׽�Ʈ ���̽��� ù° �ٿ��� �׷����� ������ ���� V�� ������ ���� E�� �� ĭ�� ���̿� �ΰ� ������� �־�����.
�� �������� 1���� V���� ���ʷ� ��ȣ�� �پ� �ִ�.
�̾ ��° �ٺ��� E���� �ٿ� ���� ������ ���� ������ �־����µ�, �� �ٿ� ������ �� ������ ��ȣ u, v (u �� v)�� �� ĭ�� ���̿� �ΰ� �־�����.

���
K���� �ٿ� ���� �Է����� �־��� �׷����� �̺� �׷����̸� YES, �ƴϸ� NO�� ������� ����Ѵ�.

����
2 �� K �� 5
1 �� V �� 20,000
1 �� E �� 200,000
���� �Է� 1
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
���� ��� 1
YES
NO

*/