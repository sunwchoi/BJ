#include <iostream>

using namespace std;

int N, M, ret;
string  S, P;

int start(int idx)
{
    for (; S[idx]; idx++)
        if (S[idx] == 'I')
            return idx;
    return idx;
}

int f(int idx, int cnt, char pre, int total)
{
    if (!S[idx])
        return total;
    if (S[idx] == pre)
        return f(start(idx), 0, 0, total);
    if (S[idx] == 'I' && cnt == N)
    {
        total++;
        cnt--;
    }
    if (S[idx] == 'O')
        cnt++;
    return f(idx + 1, cnt, S[idx], total);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> S;
    cout << f(start(0), 0, 0, 0) << "\n";
}