#include <iostream>

using namespace std;

string  p, arg;
int T, n, b, e;
int arr[100000];

void    parsing()
{
    int idx = 0;
    for (int i = 0; i < arg.length(); i++)
    {
        int tmp = 0;
        while ('0' <= arg[i] && arg[i] <= '9' && i < arg.length())
            tmp = tmp * 10 + (arg[i++] - '0');
        if (tmp != 0)
            arr[idx++] = tmp;
    }
}

void    R()
{
    if (b < e) 
    {
        b--; e--;
        swap(b, e);
    }
    else if (e < b)
    {
        b++; e++;
        swap(b, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> p >> n >> arg;
        parsing();
        b = 0; e = n;
        for (int j = 0; j < p.length(); j++)
        {
            if (p[j] == 'R')
                R();
            else
            {
                if (b == e)
                {
                    cout << "error\n";
                    b = -1;
                    break ;
                }
                b < e ? b++ : b--;
            }
        }
        if (b >= 0)
        {
            cout << "[";
            for (int j = b; j < e; j++)
            {
                cout << arr[j];
                if (j != e - 1)
                    cout << ",";
            }
            for (int j = b; j > e; j--)
            {
                cout << arr[j];
                if (j != e + 1)
                    cout << ",";
            }
            cout << "]\n";
        }
    }
}