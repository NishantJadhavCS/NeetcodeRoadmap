#include <bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int result;
    int left = 1, right = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        right = max(right, piles[i]);
    }
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int64_t hour = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int64_t dif = (piles[i] + mid - 1) / mid;
            hour += dif;
        }
        if (hour <= h)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

// int minEatingSpeed(vector<int> &piles, int h)
// {
//     int k = 1;
//     while (k < 5)
//     {
//         int64_t hour = 0;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             int64_t dif = ceil(static_cast<double>(piles[i]) / k);
//             hour = static_cast<long long>(hour) + static_cast<long long>(dif);
//         }
//         if (hour <= h)
//         {
//             return k;
//         }
//         k++;
//     }
//     return 1;
// }

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = minEatingSpeed(piles, h);
    cout << result << endl;
    return 0;
}