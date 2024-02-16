#include <iostream>
#include <set>

using namespace std;

int N, x;
multiset<pair<int, int> >    st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (st.empty())
                cout << "0\n";
            else
            {
                auto it = st.begin();
                cout << it->second<< "\n";
                st.erase(it);
            }
        }
        else
            st.insert(make_pair(abs(x), x));
    }
}