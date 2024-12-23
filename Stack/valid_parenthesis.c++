#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack<int> br;
    for (int i = 0; i < s.size(); i++)
    {
        char a = s[i];
        if (a == '(' || a == '{' || a == '[')
        {
            br.push(a);
        }
        if (a == ')' || a == '}' || a == ']')
        {
            if (br.size() == 0)
            {
                return false;
            }
            if (a == ')')
            {
                if (br.top() == '(')
                {
                    br.pop();
                }
                else
                {
                    return false;
                }
            }
            if (a == '}')
            {
                if (br.top() == '{')
                {
                    br.pop();
                }
                else
                {
                    return false;
                }
            }
            if (a == ']')
            {
                if (br.top() == '[')
                {
                    br.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (br.size() >= 1)
    {
        return false;
    }
    return true;
}

int main()
{
    string s = "]";
    cout << boolalpha << isValid(s);
    return 0;
}
