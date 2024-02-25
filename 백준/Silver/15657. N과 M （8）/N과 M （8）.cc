#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int ret[8];

void    f(int idx, int n)
{
    if (n == M)
    {
        for (int i = 0; i < M; i++)
            cout << ret[i] << " ";
        cout << "\n";
        return ;
    }
    for (int i = idx; i < N; i++)
    {
        ret[n] = arr[i];
        f(i, n + 1);
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
    sort(arr, arr + N);
    f(0, 0);
}