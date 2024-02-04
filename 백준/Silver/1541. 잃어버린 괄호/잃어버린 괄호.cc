#include <iostream>

using namespace std;

string	s;
int	sum;

int	cal(int idx, bool minus)
{
	int	num = 0;
	if ((s[idx] == '+' || s[idx] == '-')
		&& s[idx++] == '-')
		minus = true;
	while('0' <= s[idx] && s[idx] <= '9')
		num = 10 * num + s[idx++] - '0';
	return (minus ? -1 * num : num) + (s[idx] ? cal(idx, minus) : 0) ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	cout << cal(0, false) << "\n";
}