
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
		if (cnt == 2)	// 1과 자기 자신으로만 나눠지면 소수
			result++;
		cnt = 0;
	}
	cout << result << endl;
}

/*

문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 
다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.



예제 입력 1
4
1 3 5 7

예제 출력 1
3
*/