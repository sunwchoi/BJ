#include <vector>
#include <unordered_set>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    int totalRobot = routes.size();
    vector<vector<int>> snap(totalRobot, vector<int>(3));
    unordered_set<int> endRobot;

    const int ORDER = 0;
    const int POSY = 1;
    const int POSX = 2;


    map<pair<int, int>, int> first;

    for (int i = 0; i < totalRobot; i++)
    {

        snap[i][ORDER] = 0;
        int p = routes[i][0] - 1;
        snap[i][POSY] = points[p][0];
        snap[i][POSX] = points[p][1];

        pair<int, int> pr = make_pair(snap[i][POSX], snap[i][POSY]);
        if (++first[pr] == 2)
            answer++;
    }

    int j = 10;
    while (endRobot.size() != totalRobot)
    {
        map<pair<int, int>, int> cur;
        for (int i = 0; i < totalRobot; i++)
        {
            if (endRobot.find(i) != endRobot.end())
                continue;
            int order = snap[i][ORDER] + 1;
            int& posY = snap[i][POSY];
            int& posX = snap[i][POSX];

            int p = routes[i][order] - 1;
            int goalY = points[p][0];
            int goalX = points[p][1];

            if (goalY != posY)
                posY += goalY < posY ? -1 : 1;
            else if (goalX != posX)
                posX += goalX < posX ? -1 : 1;

            pair<int, int> pr = make_pair(posX, posY);
            if (++cur[pr] == 2)
                answer++;

            if (goalX == posX && goalY == posY)
                snap[i][ORDER]++;
            if (snap[i][ORDER] + 1 == routes[i].size())
                endRobot.insert(i);
        }
    }

    return answer;
}