#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    set<vector<int>> triplets;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                triplets.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
        }
        for (auto trip : triplets)
        {
            result.push_back(trip);
        }
    }
    return result;
}

int main()
{
    vector<int> numbers = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(numbers);
    for (auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}