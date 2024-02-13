#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;
deque<int>  tr;

int f(int mi, int ma)
{
    if (ma - mi == 1)
        return mi;
    int mid = ((long)ma + (long)mi) / 2;
    long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (tr[i] > mid)
            sum += tr[i] - mid;
    }
    return (sum >= M) ? f(mid, ma) : f(mi, mid);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        tr.push_back(tmp);
    }
    cout << f(0, 2000000000 + 1) << "\n";
}