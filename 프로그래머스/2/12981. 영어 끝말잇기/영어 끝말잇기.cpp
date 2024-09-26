#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> st;
    st.insert(words[0]);
    string pre = words[0];
    
    
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i].length() == 1 ||
            pre.back() != words[i][0] ||
            st.find(words[i]) != st.end()
            )
            return {i % n + 1, i / n + 1};
        st.insert(words[i]);
        pre = words[i];
    }
    return {0, 0};
}