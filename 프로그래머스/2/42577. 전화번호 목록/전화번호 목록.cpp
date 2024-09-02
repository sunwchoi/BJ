#include <string>
#include <vector>
#include <iostream>

#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> num;
    
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 1; j <= phone_book[i].length(); j++)
        {
            num[phone_book[i].substr(0, j)]++;
        }
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        if (num[phone_book[i]] > 1)
            return false;
    }
    return true;
    
}