// Valid Anagram

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Brute Force Method
// bool isAnagram(string s, string t)
// {
//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = 0; j < t.size(); j++)
//         {
//             if (s[i] == t[j])
//             {
//                 s.erase(s.begin() + i);
//                 t.erase(t.begin() + j);
//                 i--;
//                 break;
//             }
//         }
//     }
//     if (s.size() > 0 || t.size() > 0)
//     {
//         return false;
//     }
//     return true;
// }

//
bool isAnagram(string s, string t)
{
    unordered_map<char, int> countT, countS;
    for (char c : s)
    {
        countS[c]++;
    }
    for (char c : t)
    {
        countT[c]++;
    }
    return countS == countT;
}

int main()
{
    string s = "anagram", t = "nagaram";
    cout << boolalpha << isAnagram(s, t);
    return 0;
}