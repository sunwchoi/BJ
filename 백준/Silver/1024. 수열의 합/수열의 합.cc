#include <iostream>
#include <vector>

using namespace std;

int N, L;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    vector<int> sum(100);

    for (int i = 1; i < 100; i++)
        sum[i] = i + sum[i - 1];

    for (int i = L; i <= 100; i++)
    {
        int start = (N - sum[i - 1]) / i;
        int invalid = (N - sum[i - 1]) % i;

        if (start >= 0 && invalid == 0)
        {
            for (int j = 0; j < i; j++)
                cout << start + j << " ";
            cout << "\n";

            return 0;
        }
    }

    cout << "-1\n";
}