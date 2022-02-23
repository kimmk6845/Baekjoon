#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 300

int l;  // L
int px, py, nx, ny;     // ���� �ִ� ��ġ, �̵��Ϸ��� ��ġ
bool maps[MAXSIZE][MAXSIZE];

int BFS(int y, int x);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> l;
        cin >> px >> py >> nx >> ny;

        memset(maps, 0, sizeof(maps));

        cout << BFS(py, px) << "\n";
    }

}

vector<pair<int, int>> next_visit{ {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };   // ����Ʈ �̵� �ݰ�
int BFS(int y, int x)
{
    maps[y][x] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(y, x), 0));

    while (!q.empty())
    {
        int temp_y = q.front().first.first;
        int temp_x = q.front().first.second;
        int move = q.front().second;
        q.pop();

        if (temp_x == nx && temp_y == ny)
            return move;

        for (int i = 0; i < 8; i++)
        {
            int next_y = temp_y + next_visit[i].first;
            int next_x = temp_x + next_visit[i].second;
            if (next_y >= 0 && next_x >= 0 && next_y < l && next_x < l)
            {
                if (!maps[next_y][next_x])
                {
                    maps[next_y][next_x] = true;
                    q.push(make_pair(make_pair(next_y, next_x), move + 1));
                }
            }
        }
    }
}

/*

����
ü���� ���� �� ����Ʈ�� ������ �ִ�. ����Ʈ�� �� ���� �̵��� �� �ִ� ĭ�� �Ʒ� �׸��� �����ִ�. 
����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����. 
����Ʈ�� �� �� �����̸� �� ĭ���� �̵��� �� ������?



�Է�
�Է��� ù° �ٿ��� �׽�Ʈ ���̽��� ������ �־�����.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù° �ٿ��� ü������ �� ���� ���� l(4 �� l �� 300)�� �־�����. ü������ ũ��� l �� l�̴�. 
ü������ �� ĭ�� �� ���� �� {0, ..., l-1} �� {0, ..., l-1}�� ��Ÿ�� �� �ִ�. 
��° �ٰ� ��° �ٿ��� ����Ʈ�� ���� �ִ� ĭ, ����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.

���
�� �׽�Ʈ ���̽����� ����Ʈ�� �ּ� �� ������ �̵��� �� �ִ��� ����Ѵ�.

���� �Է� 1
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
���� ��� 1
5
28
0

*/