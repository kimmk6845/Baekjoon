#include <iostream>
using namespace std;
#define MAXSIZE 101

int A[MAXSIZE][MAXSIZE];
int B[MAXSIZE][MAXSIZE];
int result[MAXSIZE][MAXSIZE];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Matrix A
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	// Matrix B
	int M2, K;
	cin >> M2 >> K;		// M2�� M�� ������ ���� ��
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {	//O(N^3) ���⵵
				result[i][j] += A[i][k] * B[k][j];
			}
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

/*

����
N*Mũ���� ��� A�� M*Kũ���� ��� B�� �־����� ��, �� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ��� A�� ũ�� N �� M�� �־�����. ��° �ٺ��� N���� �ٿ� ��� A�� ���� M���� ������� �־�����.
�� ���� �ٿ��� ��� B�� ũ�� M�� K�� �־�����. �̾ M���� �ٿ� ��� B�� ���� K���� ���ʴ�� �־�����.
N�� M, �׸��� K�� 100���� �۰ų� ����, ����� ���Ҵ� ������ 100���� �۰ų� ���� �����̴�.

���
ù° �ٺ��� N���� �ٿ� ��� A�� B�� ���� ����� ����Ѵ�. ����� �� ���Ҵ� �������� �����Ѵ�.


���� �Է� 1
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3

���� ��� 1
-1 -2 6
-3 -6 12
-5 -10 18

*/