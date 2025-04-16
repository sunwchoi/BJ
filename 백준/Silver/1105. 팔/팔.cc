#include <iostream>

using namespace std;

unsigned long long L, R;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> R;

    int answer = 0;
    while (L)
    {
        int l = L % 10;
        int r = R % 10;
        if (l == r)
        {
            if (l == 8)
                answer++;
        }
        else
            answer = 0;

        R /= 10;
        L /= 10;
    }

    cout << (R ? 0 : answer) << "\n";
}