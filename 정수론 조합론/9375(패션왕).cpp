#include <iostream>
#include <map>
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
		int n;
		cin >> n;

		string name, type;
		map<string, int> m;
		for (int j = 0; j < n; j++)
		{
			cin >> name >> type;
			m[type]++;
		}

		int result = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++)
			result *= (iter->second + 1);
		cout << result - 1 << endl;		// �˸����� ����
	}

}

/*

����
�غ��̴� �мǿ� �ſ� �ΰ��ؼ� �ѹ� �Ծ��� �ʵ��� ������ ���� �ٽ� ���� �ʴ´�.
���� ��� ���� �غ��̰� �Ȱ�, ��Ʈ, ����, �Ź��� �Ծ��ٸ�, �������� ������ �߰��� �԰ų� �Ȱ��� ��� �����ϰų� �ؾ��Ѵ�.
�غ��̰� ���� �ǻ���� �־������� ���� �غ��̴� �˸��� �ƴ� ���·� ��ĥ���� �ۿ� ���ƴٴ� �� ������?

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� �־�����. �׽�Ʈ ���̽��� �ִ� 100�̴�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� �غ��̰� ���� �ǻ��� �� n(0 �� n �� 30)�� �־�����.
���� n������ �غ��̰� ���� �ǻ��� �̸��� �ǻ��� ������ �������� ���еǾ� �־�����. ���� ������ �ǻ��� �ϳ��� ���� �� �ִ�.
��� ���ڿ��� 1�̻� 20������ ���ĺ� �ҹ��ڷ� �̷���������� ���� �̸��� ���� �ǻ��� �������� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���� �غ��̰� �˸��� �ƴ� ���·� �ǻ��� ���� �� �ִ� ��츦 ����Ͻÿ�.

��Ʈ
ù ��° �׽�Ʈ ���̽��� headgear�� �ش��ϴ� �ǻ��� hat, turban�̸� eyewear�� �ش��ϴ� �ǻ��� sunglasses�̹Ƿ�
(hat), (turban), (sunglasses), (hat,sunglasses), (turban,sunglasses)�� �� 5���� �̴�.

���� �Է� 1
2
3
hat headgear
sunglasses eyewear
turban headgear
3
mask face
sunglasses face
makeup face

���� ��� 1
5
3

*/