#include <iostream>
#define MAX 9
using namespace std;

int arr[MAX];
bool IsVisit[MAX];
int n, m;

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {
        if (!IsVisit[i])
        {
            IsVisit[i] = true;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            IsVisit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);
}

// N과 M문제에서 오름차순만 출력