#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
bool vi[8];
int ret[8];

void    f(int n)
{
    if (n == M)
    {
        for (int i = 0 ; i < M; i++)
            cout << ret[i] << " ";
        cout <<"\n";
    }
    for (int i = 0; i < N; i++)
    {
        if (vi[i])
            continue;
        vi[i] = true;
        ret[n] = arr[i];
        f(n + 1);
        vi[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);
    f(0);
}