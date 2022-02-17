// �ִܰŸ� = BFS
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

����
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.
�̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.



���� �Է� 1
4 6
101111
101010
101011
111011

���� ��� 1
15




���� �Է� 2
4 6
110110
110110
111111
111101

���� ��� 2
9




���� �Է� 3
2 25
1011101110111011101110111
1110111011101110111011101

���� ��� 3
38




���� �Է� 4
7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111

���� ��� 4
13

*/