#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 100001

int N, K;
bool pos[MAXSIZE];

int BFS();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    pos[N] = true;
    cout << BFS() << "\n";

}

int BFS()
{
    queue<pair<int, int>> q;     // ��ġ, �ð�
    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        int next_x = q.front().first;
        int cnt = q.front().second;
        vector<int> next_visit{ next_x + 1, next_x * 2, next_x - 1 };

        q.pop();

        if (next_x == K)
            return cnt;

        for (int i = 0; i < 2; i++)
        {
            next_x = next_visit[i];
            if (next_x < MAXSIZE && !pos[next_x])
            {
                q.push(make_pair(next_x, cnt + 1));
                pos[next_x] = true;
            }
        }

        next_x = next_visit[2];     // ���� �̵�
        if (next_x >= 0 && !pos[next_x])
        {
            q.push(make_pair(next_x, cnt + 1));
            pos[next_x] = true;
        }

    }
}

/*

����
�����̴� ������ ���ٲ����� �ϰ� �ִ�.
�����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�.
�����̴� �Ȱų� �����̵��� �� �� �ִ�.
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�.
�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.

�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.



���� �Է� 1
5 17

���� ��� 1
4


**��Ʈ**
�����̰� 5-10-9-18-17 ������ ���� 4�ʸ��� ������ ã�� �� �ִ�.

*/