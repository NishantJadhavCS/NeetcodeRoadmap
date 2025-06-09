#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> map1, map2;
    int n1 = s1.length(), n2 = s2.length();
    if (n2 < n1)
        return false;
    for (int i = 0; i < n1; i++)
    {
        map1[s1[i]]++;
        map2[s2[i]]++;
    }
    if (map1 == map2)
        return true;
    for (int i = n1; i < n2; i++)
    {
        char oldChar = s2[i - n1];
        map2[oldChar]--;
        if (map2[oldChar] == 0)
        {
            map2.erase(oldChar);
        }
        map2[s2[i]]++;
        if (map1 == map2)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    cout << boolalpha << checkInclusion(s1, s2) << endl;
    return 0;
}