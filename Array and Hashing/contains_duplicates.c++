// Contains Duplicate

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Brute Force Basic Method
// bool containsDuplicate(vector<int> &nums)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// Sort Method (nlogn)
// bool containsDuplicate(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if ((nums[i] - nums[i - 1]) == 0)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// Using Normal Unordered Sets
//  bool containsDuplicate(vector<int> &nums)
//  {
//      unordered_set<int> num;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          num.insert(nums[i]);
//      }
//      if (num.size() != nums.size())
//      {
//          return true;
//      }
//      return false;
//  }

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> num;
    for (int i = 0; i < nums.size(); i++)
    {
        num.insert(nums[i]);
        if (num.size() != i + 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 1, 3, 8};
    bool res = containsDuplicate(nums);
    cout << res;
    return 0;
}