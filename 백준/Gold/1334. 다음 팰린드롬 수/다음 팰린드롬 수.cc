#include <iostream>

using namespace std;

string input;
string output;

bool check()
{
	if (output.length() > input.length())
		return true;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] > output[i])
			return false;
		else if (input[i] < output[i])
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;

	output = input;
	for (int i = 0; i < output.length(); i++)
		output[output.length() - i - 1] = output[i];
	
	while (check() == false)
	{
		int mid = (output.length() + 1) / 2 - 1;
		
		output[mid]++;
		for (int i = mid; i >= 0 && output[i] == '9' + 1; i--)
		{
			output[i] = '0';
			if (i >= 1)
				output[i - 1]++;
		}

		if (output[0] == '0')
			output = '1' + output;

		for (int i = 0; i < output.length(); i++)
			output[output.length() - i - 1] = output[i];
	}

	cout << output << "\n";
}