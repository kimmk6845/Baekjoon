#include <iostream>
#include <queue>    // BFS
using namespace std;
#define MAXSIZE 1001

int N, M, V;
int edge1, edge2;
bool graph[MAXSIZE][MAXSIZE]; // ���� ���� = true
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



    DFS(V);     // ���̿켱Ž��
    cout << "\n";
    BFS(V);     // �ʺ�켱Ž��
}

void BFS(int node)  // queue�� �̿��� ����
{
    bfs_queue.push(node);
    bfs_visited[node] = true;

    while (!bfs_queue.empty())
    {
        int visit_node = bfs_queue.front();
        cout << visit_node << " ";

        for (int i = 1; i <= N; i++)
        {
            if (graph[visit_node][i])    // �湮�� ������ ����� ������ ���� ��
            {
                if (bfs_visited[i] == false)
                {
                    bfs_visited[i] = true;
                    bfs_queue.push(i);
                }
            }
        }

        bfs_queue.pop();    // �湮�� ���� ����
    }
}

void DFS(int node)  // ��͸� �̿��� ����
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

����
�׷����� DFS(���̿켱Ž��)�� Ž���� ����� BFS(�ʺ�켱Ž��)�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�.
���� ��ȣ�� 1������ N�������̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����.
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����.
� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�.
�Է����� �־����� ������ ������̴�(Ʈ�� X, �׷��� O)

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�.
V���� �湮�� ���� ������� ����ϸ� �ȴ�.



���� �Է� 1
4 5 1
1 2
1 3
1 4
2 4
3 4

���� ��� 1
1 2 4 3
1 2 3 4



���� �Է� 2
5 5 3
5 4
5 2
1 2
3 4
3 1

���� ��� 2
3 1 2 5 4
3 1 4 2 5



���� �Է� 3
1000 1 1000
999 1000

���� ��� 3
1000 999
1000 999

*/