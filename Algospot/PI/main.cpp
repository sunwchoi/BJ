#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define INF 1000000

int C;
string num;
vector<int> minLevel;

void getLevel(int idx, int* level)
{
	int arr[5] = {1, 2, 4, 5, 10};
	
	if (num[idx] != num[idx + 1])
		arr[0] = 0;
	for (int i = idx + 2; i < idx + 5 && i < num.length(); i++)
	{
		if (num[i - 1] != num[i])
			arr[0] = 0;
		if (!((num[i - 2] + 1 == num[i - 1] && num[i - 1] + 1 == num[i]) ||
				num[i - 2] - 1 == num[i - 1] && num[i - 1] - 1 == num[i]))
			arr[1] = 0;
		if (num[i - 2] != num[i])
			arr[2] = 0;
		if (num[i - 2] - num[i - 1] != num[i - 1] - num[i])
			arr[3] = 0;
		for (int j = 0; j < 5; j++)
			if (arr[j])
			{
				level[i - idx - 2] = arr[j];
				break ;
			}
	}
}

int getMinLevel(int idx)
{
	if (minLevel[idx] != INF)
		return minLevel[idx];
	
	int level[3];
	getLevel(idx, level);

	for (int i = 3; i <= 5 && idx + i <= num.length(); i++)
		if (idx + i == num.length())
			return minLevel[idx] = level[i - 3];

	for (int i = 3; i <= 5 && idx + i < num.length(); i++)
	{
		minLevel[idx] = min(level[i - 3] + getMinLevel(idx + i), minLevel[idx]);
	}
	return minLevel[idx];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> num;
		minLevel = vector<int>(num.length(), INF);
		cout << getMinLevel(0) << "\n";
	}
}
