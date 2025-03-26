#include <iostream>
#include <string>
#include <map>

using namespace std;

int m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;
    while (m)
    {
        string s;
        
        cin.ignore();
        getline(cin, s);

        int answer = 0;
        int start = 0, last = 1;
        map<char, int> history;
        
        history[s[start]]++;
        for ( ; last < s.length(); last++)
        {
            history[s[last]]++;
            while (history.size() > m)
            {
                history[s[start]]--;
                if (history[s[start]] == 0)
                    history.erase(s[start]);
                start++;
            }

            if (answer < last - start + 1)
                answer = last - start + 1;
        }

        cout << answer << "\n";
        cin >> m;
    }
}