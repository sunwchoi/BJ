#include <iostream>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    int pre = 1;
    int ppre = 0;
    int cur = 1;
    for (int i = 2; i <= n; i++)
    {
        cur = pre + ppre;

        ppre = pre;
        pre = cur;
    }

    cout << cur << "\n";
}