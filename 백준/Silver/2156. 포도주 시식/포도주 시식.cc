#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int>	arr(10001);
vector<int>	sum1(10001, -1);
vector<int>	sum2(10001, -1);
int	f1(int i);
int	f2(int i);

int	f1(int i)
{
	if (i < 0)
		return 0;
	if (sum1[i] < 0)
		sum1[i] = max(f2(i - 2), f2(i - 3)) + arr[i];
	return sum1[i];
}

int	f2(int i)
{
	if (i < 0)
		return 0;
	if (sum2[i] < 0)
		sum2[i] = max(f1(i - 1), f2(i - 2)) + arr[i];
	return sum2[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sum1[1] = arr[1];
	sum1[2] = (arr[1] > arr[2]) ? arr[1] : arr[2];
	sum2[1] = arr[1];
	sum2[2] = arr[1] + arr[2];
	if (n == 1 || n == 2)
		cout << sum2[n] << "\n"; 
	else
		cout << max(f2(n), f2(n - 1)) << "\n";
}