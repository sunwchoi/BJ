#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    unsigned long long answer = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (answer % v[i])
        {
            if (answer < v[i])
                answer = v[i];
            else
                answer = ((answer + v[i]) / v[i]) * v[i];
        }
    }

    cout << answer << "\n";
}