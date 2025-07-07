#include <bits/stdc++.h>

using namespace std;

// string minWindow(string s, string t)
// {
//     map<char, int> tMap, windowMap;
//     int n = s.size();
//     for (int i = 0; i < t.size(); i++)
//     {
//         tMap[t[i]]++;
//     }
//     int left = 0, right = 0, req = tMap.size(), found = 0, minLen = INT16_MAX, minStart = 0;
//     while (right < n)
//     {
//         windowMap[s[right]]++;
//         if (tMap.count(s[right]) && windowMap[s[right]] == tMap[s[right]])
//         {
//             found++;
//         }
//         right++;
//         if (found == req)
//         {
//             while (found == req)
//             {
//                 if (right - left < minLen)
//                 {
//                     minLen = right - left;
//                     minStart = left;
//                 }
//                 char ch = s[left];
//                 windowMap[ch]--;

//                 if (tMap.count(ch) && windowMap[ch] < tMap[ch])
//                 {
//                     found--;
//                 }
//                 left++;
//             }
//         }
//     }
//     if (minLen == INT_MAX)
//         return "";
//     else
//         return s.substr(minStart, minLen);
// }

string minWindow(string s, string t)
{
    unordered_map<char, int> tMap, windowMap;
    int n = s.size();
    for (int i = 0; i < t.size(); i++)
    {
        tMap[t[i]]++;
    }
    int left = 0, right = 0, minLen = INT16_MAX, minStart = 0, found = 0, req = tMap.size();
    while (right < n)
    {
        char rch = s[right];
        windowMap[rch]++;
        if (tMap.count(rch) && windowMap[rch] == tMap[rch])
        {
            found++;
        }
        right++;
        if (found == req)
        {
            while (found == req)
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    minStart = left;
                }
                char lch = s[left];
                windowMap[lch]--;
                if (tMap.count(lch) && windowMap[lch] < tMap[lch])
                {
                    found--;
                }
                left++;
            }
        }
    }
    if (minLen == INT16_MAX)
    {
        return "";
    }
    return s.substr(minStart, minLen);
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    string res = minWindow(s, t);
    cout << res << endl;
    return 0;
}