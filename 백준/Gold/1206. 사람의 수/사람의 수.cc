#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int N;
int average[50];

int gcd(int l, int r)
{
    int mod = l % r;

    return mod == 0 ? r : gcd(r, mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int ans = 1;

    for (int i = 0; i < N; i++)
    {
        string input;

        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] != '.')
                average[i] = average[i] * 10 + input[j] - '0';
        }

    }

    for (int i = 1; i <= 1000; i++)
    {
        bool isAns = false;
        for (int j = 0; j < N; j++)
        {
            isAns = false;
            for (int k = 0; k <= i * 10000; k += 1000)
            {
                if (average[j] == k / i)
                {
                    isAns = true;
                    break;
                }
            }

            if (isAns == false)
                break;
        }

        if (isAns)
        {
            cout << i << "\n";
            return 0;

        }
    }
}