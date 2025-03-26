#include <iostream>

using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    int answer = 0;
    int minus = 1;
    bool bX = false;

    if (s[0] == '-')
        minus = -1;

    for (int i = (minus == 1 ? 0 : 1); i < s.size(); i++)
    {
        if (s[i] == 'x')
        {
            bX = true;
            break;
        }

        answer = answer * 10 + s[i] - '0';
    }

    if (bX)
    {
        if (answer)
            cout << answer * minus << "\n";
        else
            cout << 1 * minus << "\n";
    }
    else
        cout << 0 << "\n";
}