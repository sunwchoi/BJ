#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, char>> tr(26);
string answer[3];
int N;

void traversal(char nde) {

    if (nde == '.')
        return;
    answer[0] += nde;
    traversal(tr[nde - 'A'].first);
    answer[1] += nde;
    traversal(tr[nde - 'A'].second);
    answer[2] += nde;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        char p, lc, rc;
        cin >> p >> lc >> rc;
        tr[p - 'A'] = make_pair(lc, rc);
    }

    traversal('A');

    for (int i = 0; i < 3; i++)
        cout << answer[i] << endl;

    return 0;
}