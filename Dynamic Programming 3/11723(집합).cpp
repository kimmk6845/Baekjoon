#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 20

bool set[MAXSIZE + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    memset(set, false, sizeof(set));
    for (int i = 0; i < M; i++)
    {
        string s;
        int x;
        cin >> s;
        if (s == "all" || s == "empty")
        {
            if (s == "all")
                memset(set, true, sizeof(set));
            if (s == "empty")
                memset(set, false, sizeof(set));
        }
        else
        {
            cin >> x;

            if (s == "add")
                set[x] = true;
            if (s == "remove")
                set[x] = false;
            if (s == "check")
                cout << set[x] << "\n";
            if (s == "toggle")
                set[x] = !set[x];
        }
    }
}

/*

����
����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
remove x: S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
check x: S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
toggle x: S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
empty: S�� ���������� �ٲ۴�.
�Է�
ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.

��° �ٺ��� M���� �ٿ� �����ؾ� �ϴ� ������ �� �ٿ� �ϳ��� �־�����.

���
check ������ �־���������, ����� ����Ѵ�.



���� �Է� 1
26
add 1
add 2
check 1
check 2
check 3
remove 2
check 1
check 2
toggle 3
check 1
check 2
check 3
check 4
all
check 10
check 20
toggle 10
remove 20
check 10
check 20
empty
check 1
toggle 1
check 1
toggle 1
check 1

���� ��� 1
1
1
0
1
0
1
0
1
0
1
1
0
0
0
1
0

*/