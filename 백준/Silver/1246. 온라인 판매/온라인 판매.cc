#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> P;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    P.resize(M);
    for (int i = 0; i < M; i++)
        cin >> P[i];
    sort(P.begin(), P.end());

    int price = 0;
    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        int sell = M - i < N ? M - i : N;
        int result = P[i] * sell;
        if (result > sum)
        {
            price = P[i];
            sum = result;
        }
    }

    cout << price << " " << sum << "\n";
}