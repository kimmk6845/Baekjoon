// DP2�� 1520(��������)������ ����

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXSIZE 25

int N;
int maps[MAXSIZE + 1][MAXSIZE + 1];
bool visited[MAXSIZE + 1][MAXSIZE + 1];
int cnt;

void DFS(int w,int h);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
            maps[i][j] = s[j] - '0';
    }

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cnt = 0;
            if (maps[i][j] == 1 && !visited[i][j])
            {
                DFS(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}

vector<pair<int, int>> next_visit{ {0,-1},{0,1},{-1,0},{1,0} };
void DFS(int w, int h)
{
    cnt++;
    visited[w][h] = true;

    for (int i = 0; i < 4; i++)
    {
        int next_w = w + next_visit[i].first;
        int next_h = h + next_visit[i].second;
        if (next_w >= 0 && next_h >= 0 && next_w < N && next_h < N)
        {
            if (maps[next_w][next_h] == 1 && !visited[next_w][next_h])
                DFS(next_w, next_h);
        }
    }
}

/*

����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
ö���� �� ������ ������ ����� ���� ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.
���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.
�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.
������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.



���� �Է� 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

���� ��� 1
3
7
8
9

*/