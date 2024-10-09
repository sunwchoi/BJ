#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size() / 2;
    set<int> st;
    
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    
    return st.size() > n ? n : st.size();
}