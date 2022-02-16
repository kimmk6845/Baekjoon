// DP2의 1520(내리막길)문제와 유사

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

문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.


입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.



예제 입력 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

예제 출력 1
3
7
8
9

*/