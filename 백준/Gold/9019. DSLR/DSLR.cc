#include <iostream>
#include <queue>

using namespace std;

int T, A, B;

int D(int n)
{
    return (n*2)%10000 ;
}

int S(int n)
{
    return n == 0 ? 9999 : n - 1;
}

int L(int n)
{
    int d1 = n / 1000;
    int d2 = (n % 1000) / 100;
    int d3 = (n % 100) / 10;
    int d4 = n % 10;

    return 1000 * d2 + 100 * d3 + 10 * d4 + d1;
}

int R(int n)
{
    int d1 = n / 1000;
    int d2 = (n % 1000) / 100;
    int d3 = (n % 100) / 10;
    int d4 = n % 10;

    return 1000 * d4 + 100 * d1 + 10 * d2 + d3;
}

string  bfs()
{
    queue<pair<int, string> >   qu;
    vector<bool> vi(10000);

    qu.push(make_pair(A, ""));
    vi[A] = true;
    while (1)
    {
        pair<int, string>   nde = qu.front();
        qu.pop();
        int tmp;
        if (!vi[tmp = D(nde.first)])
        {
            if (tmp == B)
                return nde.second + "D";
            vi[tmp] = true;
            qu.push(make_pair(tmp, nde.second + "D"));
        }
        if (!vi[tmp = S(nde.first)])
        {
            if (tmp == B)
                return nde.second + "S";
            vi[tmp] = true;
            qu.push(make_pair(tmp, nde.second + "S"));
        }
        if (!vi[tmp = L(nde.first)])
        {
            if (tmp == B)
                return nde.second + "L";
            vi[tmp] = true;
            qu.push(make_pair(tmp, nde.second + "L"));
        }
        if (!vi[tmp = R(nde.first)])
        {
            if (tmp == B)
                return nde.second + "R";
            vi[tmp] = true;
            qu.push(make_pair(tmp, nde.second + "R"));
        }
    }
    return "";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cout << bfs() << "\n";
    }
}