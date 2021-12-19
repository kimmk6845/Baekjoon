#include <iostream>
#define MAX_SIZE 10001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[MAX_SIZE] = { 0 };
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[num]++;
    }
    for (int i = 1; i < MAX_SIZE; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << "\n";
}

// ī���� ����(��� ����)

/*

����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 10,000,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� 10,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.



���� �Է� 1
10
5
2
3
1
4
2
3
5
1
7

���� ��� 1
1
1
2
2
3
3
4
5
5
7

*/