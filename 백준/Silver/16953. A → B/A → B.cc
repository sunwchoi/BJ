#include <iostream>
#include <queue>

using namespace std;

int A, B;

int f()
{
    queue<pair<long long, int> > qu;
    pair<long long, int> nde;

    qu.push(make_pair(A, 1));
    while (qu.size() && (nde = qu.front()).first != B)
    {
        qu.pop();
        if (nde.first * 2 <= B)
            qu.push(make_pair(nde.first * 2, nde.second + 1));
        if (nde.first * 10 + 1 <= B)
            qu.push(make_pair(nde.first * 10 + 1, nde.second + 1));
    }
    return nde.first == B ? nde.second : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    cout << f() << "\n";
}