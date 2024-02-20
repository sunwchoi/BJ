#include <iostream>
#include <climits>

using namespace std;

int T, N;
string  mbti[100000];

int cnt(int idx, int jdx)
{
    int ret = 0;
    for (int i = 0; i < 4; i++)
        if (mbti[idx][i] != mbti[jdx][i])
            ret++;
    return ret;
}

int f()
{
    int ret = INT_MAX;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                ret = min(cnt(i, j) + cnt(j, k) + cnt(k, i), ret);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> mbti[j];
        cout << ((N >= 16 * 3) ? 0 : f()) << "\n";
    }
}