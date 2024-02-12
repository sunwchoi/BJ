#include <iostream>
#include <algorithm>

using namespace std;

int N;
int P[1000];
int sum[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i];
    sort(P, P + N);
    for (int i = 0; i < N; i++)
        sum[i] = P[i] + (i == 0 ? 0 : sum[i - 1]);
    int ret = 0;
    for (int i = 0; i < N; i++)
        ret += sum[i];
    cout << ret << "\n";
}