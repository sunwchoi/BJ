#include <iostream>
#include <unordered_set>

using namespace std;

int N;
int P[48];
int S[48];
int ans;

bool check()
{
    for (int i = 0; i < N; i++)
    {
        if (P[i] != i % 3)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i];

    for (int i = 0; i < N; i++)
        cin >> S[i];

    unordered_set<string> st;
    while (check() == false)
    {
        int arr[48];

        for (int i = 0; i < N; i++)
            arr[S[i]] = P[i];

        string tmp;
        for (int i = 0; i < N; i++)
        {
            P[i] = arr[i];
            tmp += P[i] / 10 + '0';
            tmp += P[i] % 10 + '0';
        }
        
        if (st.find(tmp) != st.end())
        {
            cout << "-1\n";
            return 0;
        }

        st.insert(tmp);
        ans++;
    }

    cout << ans << "\n";
}
