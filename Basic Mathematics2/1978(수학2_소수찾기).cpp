
#include <iostream>
using namespace std;

int main() {
	int N, result = 0;
	int temp, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int div = 1; div <= temp; div++) {
			if (temp % div == 0)
				cnt++;
		}
		if (cnt == 2)	// 1�� �ڱ� �ڽ����θ� �������� �Ҽ�
			result++;
		cnt = 0;
	}
	cout << result << endl;
}

/*

����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. 
�������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.



���� �Է� 1
4
1 3 5 7

���� ��� 1
3
*/