#include <bits/stdc++.h>

using namespace std;

// int characterReplacement(string s, int k)
// {
//     int maxCount = INT16_MIN;
//     for (int i = 0; i < s.size(); i++)
//     {
//         int count = 1;
//         int n = k;
//         int j = i + 1;
//         cout << "Current element: " << s[i] << " at " << i << endl;
//         while (j < s.size())
//         {
//             cout << "s[i] : " << s[i] << " s[j]: " << s[j] << endl;
//             cout << " j " << j << endl;
//             if (s[i] == s[j])
//             {
//                 cout << "Same " << endl;
//                 count++;
//             }
//             else
//             {
//                 cout << "Not Same " << endl;
//                 if (n > 0)
//                 {
//                     cout << "n -- " << n << endl;
//                     n--;
//                     count++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             j++;
//         }
//         cout << "Count: " << count << endl;
//         maxCount = max(maxCount, count);
//     }
//     return maxCount;
// }

int characterReplacement(string s, int k)
{
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = s.size();
    int maxCount = 0;
    for (int i = 0; i < alphabets.size(); i++)
    {
        int l = 0, r = 0, changes = 0;
        char target = alphabets[i];
        while (r < n)
        {
            if (s[r] != target)
            {
                changes++;
            }
            while (changes > k)
            {
                if (s[l] != target)
                {
                    changes--;
                }
                l++;
            }
            maxCount = max(maxCount, r - l + 1);
            r++;
        }
    }
    return maxCount;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    int result = characterReplacement(s, k);
    cout << result << endl;
    return 0;
}