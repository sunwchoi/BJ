#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<int> h;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    h = vector<int>(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    int answer = 0;
    set<double> m;
    for (int i = 0; i < N; i++)
    {
        int view = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            double tmp = ((double)h[i] - h[j]) / (i - j);
            if (m.empty() || *(m.cbegin()) > tmp)
            {
                m.insert(tmp);
                view++;
            }
        }

        m.clear();
        for (int j = i + 1; j < N; j++)
        {
            double tmp = ((double)h[j] - h[i]) / (j - i);
            if (m.empty() || *(m.crbegin()) < tmp)
            {
                m.insert(tmp);
                view++;
            }
        }
        m.clear();

        answer = max(view, answer);
    }

    cout << answer << "\n";
}
