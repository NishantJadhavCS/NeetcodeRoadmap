#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Hash Maps Method
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;
    for (const string &s : strs)
    {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        map[sorted_s].push_back(s);
    }
    for (const auto &pair : map)
    {
        ans.push_back(pair.second);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for (const auto &group : result)
    {
        for (const string &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}