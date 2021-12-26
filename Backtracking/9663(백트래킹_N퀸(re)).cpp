// ��Ʈ��ŷ�� ���� ��ǥ�� ����
#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

// col[i]�� x��ǥ, i�� y��ǥ
bool check(int level)
{
	for (int i = 0; i < level; i++)
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;	//�밢���̰ų� ���� ����
	return true;
}

void nqueen(int x)
{
	if (x == N)
		total++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[x] = i;		// �ش� ��ġ�� �� ��ġ
			if (check(x))	// ��ȿ�ϴٸ� ���� �࿡ �� ��ġ, �ƴϸ� �ٸ� ��ġ�� ��ġ ����
				nqueen(x + 1);
		}
	}
}

int main()
{
	cin >> N;
	nqueen(0);
	cout << total;
}

// N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�. N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// ù° �ٿ� N�� �־�����. (1 �� N < 15)
// ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.

/*

�Է�>>>
8

���>>>
92

*/