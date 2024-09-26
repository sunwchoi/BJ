#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> token(record.size(), vector<string>(3));
    unordered_map<string, string> mp;
    
    for (int i = 0; i < record.size(); i++)
    {
        stringstream s(record[i]);
        
        s >> token[i][0] >> token[i][1] >> token[i][2];
        if (token[i][0] != "Leave")
            mp[token[i][1]] = token[i][2];    
    }
    
    for (int i = 0; i < token.size(); i++)
    {
        if (token[i][0] != "Change")
        {
            
            string line = mp[token[i][1]] + "님이 ";
            if (token[i][0] == "Enter")
                line += "들어왔습니다.";
            else if (token[i][0] == "Leave")
                line += "나갔습니다.";
            answer.push_back(line);
        }
    }
    return answer;
}