#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;
    multiset<int> ms;
    for (int i = 0; i < k; i++)
    {
        ms.insert(nums[i]);
    }
    int maxValue = *ms.rbegin();
    result.push_back(maxValue);
    for (int i = k; i < nums.size(); i++)
    {
        int last = nums[i - k];
        ms.erase(ms.find(last));
        ms.insert(nums[i]);
        maxValue = *ms.rbegin();
        result.push_back(maxValue);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for (int res : result)
    {
        cout << res << endl;
    }
    return 0;
}