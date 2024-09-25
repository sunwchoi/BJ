#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int start1 = 0, start2 = 0;
    
    for (int i = 0; i < goal.size(); i++)
    {
        if (start1 != cards1.size() && cards1[start1] == goal[i])
            start1++;
        else if (start2 != cards2.size() && cards2[start2] == goal[i])
            start2++;
        else
            return "No";
    }
    return "Yes";
}