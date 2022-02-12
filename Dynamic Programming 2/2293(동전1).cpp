#include <iostream>
using namespace std;
#define V_MAXSIZE 100
#define S_MAXSIZE 10000

int n, k;
int value[V_MAXSIZE + 1];
int dp[S_MAXSIZE + 1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> value[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = value[i]; j < k + 1; j++)
            dp[j] += dp[j - value[i]];

    cout << dp[k] << "\n";

}

/*

����
n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���.
�� ������ ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�.
�� ����� ���� ���Ͻÿ�. ������ ������ �� ���� ����� �� �ִ�.

����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����.
������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ����� ���� ����Ѵ�. ����� ���� 231���� �۴�.



���� �Է� 1
3 10
1
2
5

���� ��� 1
10

*/