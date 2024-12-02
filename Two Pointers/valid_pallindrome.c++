#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Two Pointer Appraoch
bool isPalindrome(string s)
{
    int start = 0, end = s.size() - 1;
    while (start <= end)
    {
        if (!isalnum(s[start]))
        {
            start++;
            continue;
        }
        if (!isalnum(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

// bool isPalindrome(string s)
// {
//     string revString = "";
//     for (char c : s)
//     {
//         if (isalnum(c))
//         {
//             revString += tolower(c);
//         }
//     }
//     return revString == string(revString.rbegin(), revString.rend());
// }

int main()
{
    string s = "radar";
    cout << boolalpha << isPalindrome(s) << endl;
    return 0;
}