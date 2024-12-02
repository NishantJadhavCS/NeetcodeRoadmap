#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// // Brute Force Method
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     vector<int> result;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if ((nums[i] + nums[j]) == target)
//             {
//                 result.push_back(i);
//                 result.push_back(j);
//                 break;
//             }
//         }
//     }
//     return result;
// }

// Two pointer Technique
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    vector<pair<int, int>> sorted_nums;
    for (int i = 0; i < nums.size(); i++)
    {
        sorted_nums.push_back({nums[i], i});
    }
    sort(sorted_nums.begin(), sorted_nums.end());
    int left = 0, right = sorted_nums.size() - 1;
    while (left < right)
    {
        if ((sorted_nums[left].first + sorted_nums[right].first) == target)
        {
            result.push_back(min(sorted_nums[left].second, sorted_nums[right].second));
            result.push_back(max(sorted_nums[left].second, sorted_nums[right].second));
            return result;
        }
        else if ((sorted_nums[left].first + sorted_nums[right].first) < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 4, 5, 6};
    int target = 7;
    vector<int> res = twoSum(nums, target);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}