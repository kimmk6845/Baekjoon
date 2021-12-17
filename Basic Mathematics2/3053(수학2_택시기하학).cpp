#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int R;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	cout << R * R * M_PI << endl;
	cout << R * R * 2 << endl;
}

// 첫째 줄에 반지름 R이 주어진다. R은 10,000보다 작거나 같은 자연수이다.

// 첫째 줄에는 유클리드 기하학에서 반지름이 R인 원의 넓이를, 둘째 줄에는 택시 기하학에서 반지름이 R인 원의 넓이를 출력한다. 정답과의 오차는 0.0001까지 허용한다.

/*
42

5541.769441
3528.000000
*/