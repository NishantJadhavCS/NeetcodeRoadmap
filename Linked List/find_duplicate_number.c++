#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    map<int, int> count;
    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
        if (count[nums[i]] > 1)
        {
            return nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    int res = findDuplicate(nums);
    cout << res << endl;
    return 0;
}