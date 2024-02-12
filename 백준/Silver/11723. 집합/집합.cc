#include <iostream>

using namespace std;

bool    S[21];
int M, x;
string  cmd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> cmd;
        if (cmd == "all")
            for (int j = 1; j <= 20; j++)
                S[j] = true;
        else if (cmd == "empty")
            for (int j = 1; j <= 20; j++)
                S[j] = false;
        else
        {
            cin >> x;
            if (cmd == "add")
                S[x] = true;
            else if (cmd == "remove")
                S[x] = false;
            else if (cmd == "check")
                cout << (int)S[x] << "\n";
            else if (cmd == "toggle")
                S[x] = !S[x];
        }
    }
}