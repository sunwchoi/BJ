#include <iostream>

using namespace std;

int N;
long long arr[50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < N; j++)
        {
            if (input[j] == 'Y')
                arr[i] |= ((long long)1 << (N - 1 - j));
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        long long bit = arr[i];
        long long cmp = (long long)1 << (N - 1 - i);
        for (int j = 0; j < N; j++)
        {
            if ((arr[j] & cmp) == cmp)
                bit |= arr[j];
        }
        if (bit)
            answer = max(__builtin_popcountll(bit) - 1, answer);
    }

    cout << answer << "\n";
}