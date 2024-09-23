#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
            st.insert(numbers[i] + numbers[j]);
    }
    
    for (auto it = st.begin(); it != st.end(); it++)
        answer.push_back(*it);
    return answer;
}