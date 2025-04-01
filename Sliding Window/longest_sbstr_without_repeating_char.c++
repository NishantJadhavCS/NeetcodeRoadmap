#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> substrings = {};
    int start = 0, maxLength = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (substrings.find(s[i]) != substrings.end())
        {
            substrings.erase(s[start]);
            start++;
        }
        substrings.insert(s[i]);
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
}

int main()
{
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}