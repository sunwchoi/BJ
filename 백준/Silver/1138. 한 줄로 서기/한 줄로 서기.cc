#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    answer = vector<int>(N);
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            if (answer[j] == 0)
            {
                if (tmp-- == 0)
                {
                    answer[j] = i;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << answer[i] << " ";
    cout << "\n";
}