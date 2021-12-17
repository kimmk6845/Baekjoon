#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	while (1)
	{
		int x, y, z;
		cin >> x >> y >> z;

		if (x == 0 && y == 0 && z == 0)
			break;

		// z를 가장 큰 수로 만들기
		if (x > y)
			swap(x, y);
		if (y > z)
			swap(y, z);

		if (z * z == x * x + y * y)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}

// 과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다. 주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.

// 입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다. 각 테스트케이스는 모두 30,000보다 작은 양의 정수로 주어지며, 각 입력은 변의 길이를 의미한다.

// 각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.

/*
6 8 10
25 52 60
5 12 13
0 0 0
*/

/*
right
wrong
right
*/