#include <iostream>

using namespace std;

int N, K;
int L;
int ans = -1;
int D[7];
int d[7];
int dp[1000001][11];

int f(int n, int k)
{
    if (k == 0)
    {
        ans = max(ans, n);
        return ans;
    }

    if (dp[n][k])
        return dp[n][k];

    int ret = -1;
    for (int i = 0; i < L; i++)
    {
        for (int j = i + 1; j < L; j++)
        {
            int ni = (n % D[i]) / d[i];
            int nj = (n % D[j]) / d[j];

            if (j == L - 1 && ni == 0)
                continue;
            
            int nextN = n - (d[i] * ni + d[j] * nj) + (d[i] * nj + d[j] * ni);
            ret = max(ret, f(nextN, k - 1));
        }
    }

    return dp[n][k] = ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> K;
    D[0] = 10;
    d[0] = 1;

    for (L = 1; N / D[L - 1]; L++)
    {
        D[L] = D[L - 1] * 10;
        d[L] = d[L - 1] * 10;
    }

    cout << f(N, K) << "\n";
}
