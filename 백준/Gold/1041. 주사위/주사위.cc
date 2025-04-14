#include <iostream>
#include <climits>
using namespace std;

unsigned long long  N;
unsigned long long value[6];
unsigned long long m[3] = { INT_MAX, INT_MAX, INT_MAX };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> value[i];
        m[0] = min(m[0], value[i]);
    }

    if (N == 1)
    {
        unsigned long long mx = 0;
        int answer = 0;
        for (int i = 0; i < 6; i++)
        {
            mx = max(value[i], mx);
            answer += value[i];
        }

        cout << answer - mx << "\n";
        return 0;
    }

    m[1] = min(value[1] + value[2], m[1]);
    m[1] = min(value[1] + value[3], m[1]);
    m[1] = min(value[4] + value[2], m[1]);
    m[1] = min(value[4] + value[3], m[1]);

    int tmp = min(value[0], value[5]);
    m[2] = m[1] + tmp;

    for (int i = 1; i <= 4; i++)
        m[1] = min(m[1], value[i] + tmp);

    cout << m[0] * (5 * N * N - 16 * N + 12) + m[1] * (8 * N - 12) + m[2] * 4 << "\n";
}