#include <iostream>

using namespace std;

int N, M;
string  S, P;

void    makeP()
{
    for (int i = 0; i < N; i++)
        P += "IO";
    P += "I";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> S;
    makeP();
    int pos = 0;
    int cnt = 0;
    while (((pos = S.find(P.c_str(), pos)) || true)&& pos++ != string::npos)
        cnt++;
    cout << cnt << "\n";
}