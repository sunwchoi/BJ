#include <iostream>
#include <set>

using namespace std;

int T, k, n;
multiset<int> st;
char    cmd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> k;
        st.clear();
        for (int j = 0; j < k; j++)
        {
            cin >> cmd >> n;
            if (cmd == 'D' && !st.empty())
            {
                auto it = (n == 1) ? --st.end() : st.begin();
                st.erase(it);
            }
            else if (cmd == 'I')
                st.insert(n);
        }
        if (st.empty())
            cout << "EMPTY\n";
        else
            cout << *--st.end() << " " << *st.begin() << "\n";
    }
}