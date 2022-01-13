#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string p;
		cin >> p;

		int n;
		string arr;
		cin >> n;
		cin >> arr;

		deque<int> D;
		string temp;
		for (int j = 0; j < arr.length(); j++)
		{
			// �� �϶��� temp�� �ִٰ� ,�� ������ ���� ����
			if (isdigit(arr[j]))
				temp += arr[j];
			else
			{
				if (!temp.empty())
				{
					D.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		bool error = false;
		bool reverse = false;
		for (int j = 0; j < p.length(); j++)
		{
			if (p[j] == 'R')
				reverse = !reverse;
			else
			{
				if (D.empty())	// ���� �����ϴµ� ���� ��������� ����
				{
					cout << "error" << endl;
					error = true;
					break;
				}

				if (reverse)
					D.pop_back();
				else
					D.pop_front();
			}
		}


		if (!error)
		{
			cout << "[";
			if (reverse)
			{
				if (!D.empty())
				{
					while (D.size() != 1)
					{
						cout << D.back() << ",";
						D.pop_back();
					}
					cout << D.back();
					D.pop_back();
				}
			}
			else
			{
				if (!D.empty())
				{
					while (D.size() != 1)
					{
						cout << D.front() << ",";
						D.pop_front();
					}
					cout << D.front();
					D.pop_front();
				}
			}
			cout << "]\n";
		}
	}
}

/*

����
�����̴� �ָ��� �� ���� ��� ���ο� ��� AC�� �������. AC�� ���� �迭�� ������ �ϱ� ���� ���� ����̴�.
�� ���� �� ���� �Լ� R(������)�� D(������)�� �ִ�.

�Լ� R�� �迭�� �ִ� ������ ������ ������ �Լ��̰�, D�� ù ��° ���ڸ� ������ �Լ��̴�.
�迭�� ����ִµ� D�� ����� ��쿡�� ������ �߻��Ѵ�.

�Լ��� �����ؼ� �� ���� ����� �� �ִ�. ���� ���, "AB"�� A�� ������ ������ �ٷ� �̾ B�� �����ϴ� �Լ��̴�.
���� ���, "RDD"�� �迭�� ������ ���� ó�� �� ���ڸ� ������ �Լ��̴�.

�迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. T�� �ִ� 100�̴�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �Լ� p�� �־�����. p�� ���̴� 1���� ũ�ų� ����, 100,000���� �۰ų� ����.

���� �ٿ��� �迭�� ����ִ� ���� ���� n�� �־�����. (0 �� n �� 100,000)

���� �ٿ��� [x1,...,xn]�� ���� ���·� �迭�� ����ִ� ���� �־�����. (1 �� xi �� 100)

��ü �׽�Ʈ ���̽��� �־����� p�� ������ �հ� n�� ���� 70���� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ���� �迭�� �Լ��� ������ ����� ����Ѵ�. ����, ������ �߻��� ��쿡�� error�� ����Ѵ�.



���� �Է� 1
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

���� ��� 1
[2,1]
error
[1,2,3,5,8]
error

*/