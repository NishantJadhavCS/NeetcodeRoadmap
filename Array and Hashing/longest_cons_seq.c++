#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Sorting (nlogn)
int longestConsecutive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxLen = 1;
    int currLen = 1;
    if (nums.size() == 1)
    {
        return 1;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        else if (nums[i] == nums[i - 1] + 1)
        {
            currLen++;
            maxLen = max(currLen, maxLen);
        }
        else
        {
            currLen = 1;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    int result = longestConsecutive(nums);
    cout << result << " ";
}