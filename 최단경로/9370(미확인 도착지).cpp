#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXSIZE 2000
#define INF 100000000

int n, m, t;    // ������, ����, ������ �ĺ� ����
int s, g, h;    // �����, g�� h ������ ���� ���� ������
vector<pair<int, int>> edge[MAXSIZE + 1];
vector<int> candidate;

void Init();
vector<int> Dijkstra(int& start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        Init();

        for (int i = 0; i < m; i++)
        {
            int a, b, d;    // a�� b���̿� d���� ����� ����
            cin >> a >> b >> d;
            edge[a].push_back(make_pair(b, d));     // (����,����,����)
            edge[b].push_back(make_pair(a, d));
        }

        for (int i = 0; i < t; i++)
        {
            int x;  // ������ �ĺ�
            cin >> x;

            // �ĺ� ����
            candidate.push_back(x);
        }

        sort(candidate.begin(), candidate.end());

        vector<int> r = Dijkstra(s);
        vector<int> b1 = Dijkstra(g);
        vector<int> b2 = Dijkstra(h);

        vector<int> result;
        for (int i = 1; i <= n; i++)
        {
            // ���� �������� i������ �ɸ� ����� g,h�� �����ؼ� ���ư� ���� �����ϸ� ��� ����
            if (r[i] == r[g] + b1[h] + b2[i] || r[i] == r[h] + b2[g] + b1[i])
                result.push_back(i);
        }

        // result�� ����� ��尡 �ĺ� ����̸� ���
        for (int i = 0; i < candidate.size(); i++)
        {
            int cur = candidate[i];
            for (int j = 0; j < result.size(); j++)
            {
                if (cur == result[j])
                    cout << cur << " ";
            }
        }
        cout << "\n";
    }
}

void Init()
{
    for (int i = 0; i < MAXSIZE; i++)
        edge[i].clear();

    candidate.clear();
}

vector<int> Dijkstra(int& start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push(make_pair(0, start));

    while (!q.empty())
    {
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();

        if (cost <= dist[cur])
        {
            for (int i = 0; i < edge[cur].size(); i++)
            {
                int next = edge[cur][i].first;
                int next_cost = cost + edge[cur][i].second;
                if (next_cost < dist[next]) {
                    dist[next] = next_cost;
                    q.push(make_pair(-next_cost, next));
                }
            }
        }
    }

    return dist;
}


/*

����
(����)B100 ���, ����� �������� �� ��Ŀ�� ������ �� ���� �� ������ �Ÿ����� �̵��ϰ� �ִ�.
���� �ӹ��� �׵��� ���� ���� �ִ��� �˾Ƴ��� ���̴�.
�츮�� �˾Ƴ� ���� �׵��� s�������� ����ߴٴ� ��, �׸��� ������ �ĺ��� �� �ϳ��� �׵��� ��������� ���̴�.
�׵��� ���� ��Ȳ�̱� ������ ���������� ��ȸ���� �ʰ� �ִܰŸ��� �� ���̶� Ȯ���Ѵ�. �̻��̴�. (����)

����! (����� �������� �������� ��) ����� ��𿡵� ������ �ʴ´�. �������� ����� �İ��� ����ŭ �پ��.
�� �İ����� �׵��� g�� h ������ ���̿� �ִ� ���θ� �������ٴ� ���� �˾Ƴ´�.

�� ����� ��ü ���� ���� �ִ� ���ϱ�?



���� �Է��� �� ��° ���̽��� �ð�ȭ�� ���̴�.
�� ����� ȸ�� ������ �� ���� �� �� �ϳ��� ���� �ְ� �������� ǥ�õ� ���ο��� ������ �þҴ�.
���� �׵��� 6���� ���ϰ� �ִ�.

�Է�
ù ��° �ٿ��� �׽�Ʈ ���̽��� T(1 �� T �� 100)�� �־�����. �� �׽�Ʈ ���̽�����

ù ��° �ٿ� 3���� ���� n, m, t (2 �� n �� 2 000, 1 �� m �� 50 000 and 1 �� t �� 100)�� �־�����. ���� ������, ����, ������ �ĺ��� �����̴�.
�� ��° �ٿ� 3���� ���� s, g, h (1 �� s, g, h �� n)�� �־�����. s�� ���������� ������̰�, g, h�� ���� ���� ���� �ִ�. (g �� h)
�� ���� m���� �� �ٸ��� 3���� ���� a, b, d (1 �� a < b �� n and 1 �� d �� 1 000)�� �־�����. a�� b ���̿� ���� d�� ����� ���ΰ� �ִٴ� ���̴�.
�� ���� t���� �� �ٸ��� ���� x�� �־����µ�, t���� ������ �ĺ����� �ǹ��Ѵ�. �� t���� �������� ���� �ٸ� ��ġ�̸� ��� s�� ���� �ʴ�.
������ ���̿��� ���ΰ� ���ƺ��� 1���̴�. m���� �� �߿��� g�� h ������ ���θ� ��Ÿ�� ���� �����Ѵ�.
���� �� ���δ� ������ �ĺ��� �� ��� 1���� ���ϴ� �ִ� ����� �Ϻ��̴�.

���
�׽�Ʈ ���̽�����

�Է¿��� �־��� ������ �ĺ��� �� �Ұ����� ������ ������ ���������� �������� �и���Ų ���������� ������� ����Ѵ�.


���� �Է� 1
2
5 4 2
1 2 3
1 2 6
2 3 2
3 4 4
3 5 3
5
4
6 9 2
2 3 1
1 2 1
1 3 3
2 4 4
2 5 5
3 4 3
3 6 2
4 5 4
4 6 3
5 6 7
5
6

���� ��� 1
4 5
6

*/