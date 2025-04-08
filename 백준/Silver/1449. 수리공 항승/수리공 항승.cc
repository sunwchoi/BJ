#include <iostream>

using namespace std;

int N, L;
bool ceiling[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int tmp;
         
        cin >> tmp;
        ceiling[tmp] = true;
    }

    int tape = 0;
    int currentL = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (ceiling[i] && currentL == 0)
        {
            currentL = L;
            tape++;
        }

        if (currentL)
            currentL--;
    }

    cout << tape << "\n";
}