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
        int chance = q.front().second;  // �μ� �� �ִ� ��ȸ

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

// dist�迭�� 3�������� ����� ������ �μ��� �� ���� �μ��� �ʰ� �� ���� �����ֱ� ����
// �Է�>> 6 4
// 0000
// 1110
// 1000
// 0000
// 0111 *
// 0000
// �̿� ���� �Է��� ������ 5���� ���� 1�� �μ��� �������� ���� ����

/*

����
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�.
�ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����.
����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �̶� �ִ� ��η� �̵��Ϸ� �Ѵ�.
�ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �̶� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.

���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.

�� ĭ���� �̵��� �� �ִ� ĭ�� �����¿�� ������ ĭ�̴�.

���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 1,000)�� �־�����. ���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.

���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.




���� �Է� 1
6 4
0100
1110
1000
0000
0111
0000

���� ��� 1
15



���� �Է� 2
4 4
0111
1111
1111
1110

���� ��� 2
-1

*/