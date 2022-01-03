#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 연산자가 두 개 이상 연속해서 나오지 않으니,
	// +, -, 수식 끝이 아니면 tmp에 저장하고
	// +, -, 수식 끝이면 tmp에 저장한 값을 stoi함수를 이용해 int형 result에 저장
	// result에 저장할 때 부호를 IsMius에 따라 바꿔줌
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	int result = 0;
	string tmp = "";
	bool isMinus = false;

	for (int i = 0; i <= input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '\0') {
			if (isMinus)
				result -= stoi(tmp);
			else
				result += stoi(tmp);

			tmp = "";
			if (input[i] == '-')
				isMinus = true;
		}
		else
			tmp += input[i];
	}

	cout << result << "\n";
}

/*

문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 
입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.


예제 입력 1
55-50+40

예제 출력 1
-35


예제 입력 2
10+20+30+40

예제 출력 2
100

*/