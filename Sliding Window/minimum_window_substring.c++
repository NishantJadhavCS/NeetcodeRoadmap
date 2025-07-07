#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
    map<char, int> tmap, smap;
    for (int i = 0; i < t.size(); i++)
    {
        tmap[t[i]]++;
    }
    int i = 0;
    while (i < s.size())
    {
        
    }
    return "aa";
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    string res = minWindow(s, t);
    cout << res << endl;
    return 0;
}