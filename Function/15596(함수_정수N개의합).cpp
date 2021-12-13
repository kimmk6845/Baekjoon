#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int>& a)
{
	long long result;
	for (int i = 0; i < a.size(); i++)
		result += a[i];

	return result;
}
