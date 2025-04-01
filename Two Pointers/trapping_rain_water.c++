#include <bits/stdc++.h>

using namespace std;

// int trap(vector<int> &height)
// {
//     vector<int> leftArray, rightArray;
//     // leftArray.push_back(height[0]);
//     int maxLeft = height[0];
//     rightArray = vector<int>(height.begin() + 1, height.end());
//     int waterStore = 0;
//     // for (int i : leftArray)
//     // {
//     //     cout << i << ' ';
//     // }
//     // cout << " \n";

//     // for (int i : rightArray)
//     // {
//     //     cout << i << ' ';
//     // }
//     int n = height.size();

//     for (int i = 1; i < n - 1; i++)
//     {
//         int maxRight = 0;
//         for (int j = 0; j < rightArray.size(); j++)
//         {
//             maxRight = max(rightArray[j], maxRight);
//         }
//         cout << "Max left: " << maxLeft << endl;
//         cout << "Max Right: " << maxRight << endl;
//         cout << "Current Value: " << height[i] << endl;
//         int minValue = min(maxRight, maxLeft);
//         cout << "Minimum Value: " << minValue << endl;
//         if (minValue > height[i])
//         {
//             waterStore += minValue - height[i];
//         }
//         cout << "Water Store: " << waterStore << endl;
//         rightArray.erase(rightArray.begin());
//         for (int i : rightArray)
//         {
//             cout << i << ' ';
//         }
//         maxLeft = max(height[i], maxLeft);
//         cout << " \n";
//         cout << " \n";
//     }
//     return waterStore;
// }

int trap(vector<int> &height)
{
    int maxLeft = height[0], waterStore = 0;
    vector<int> rightMax;
    int temp = INT16_MIN;
    for (int i = height.size() - 2; i >= 0; i--)
    {
        temp = max(height[i + 1], temp);
        rightMax.push_back(temp);
    }
    reverse(rightMax.begin(), rightMax.end());
    for (int i = 1; i < height.size() - 1; i++)
    {
        int minValue = min(rightMax[i], maxLeft);
        if (minValue > height[i])
        {
            waterStore += minValue - height[i];
        }
        maxLeft = max(height[i], maxLeft);
    }
    return waterStore;
}

int main()
{
    vector<int> numbers = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trap(numbers);
    cout << result;
    return 0;
}