#include <iostream>

using namespace std;

int M, n;
int robotDir;
int robotPos[2];
int dirSet[4][4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

bool isOut(int pos)
{
    if (0 <= pos && pos <= M)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> n;
    string cmd;
    int arg;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd >> arg;
        if (cmd == "MOVE")
        {
            robotPos[0] += dirSet[robotDir][0] * arg;
            robotPos[1] += dirSet[robotDir][1] * arg;
            if (isOut(robotPos[0]) || isOut(robotPos[1]))
            {
                cout << "-1" << "\n";
                return 0;
            }
        }
        else if (cmd == "TURN")
            robotDir = (robotDir + 4 + (arg == 1 ? 1 : -1)) % 4;
    }

    cout << robotPos[0] << " " << robotPos[1] << "\n";
}