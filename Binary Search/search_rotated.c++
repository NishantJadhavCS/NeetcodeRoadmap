#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << "Mid " << mid << endl;
        cout << "Mid Num: " << nums[mid] << endl;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target || nums[low] > target)
        {
            cout << "Left" << endl;
            low = mid + 1;
        }
        else
        {
            cout << "Right" << endl;
            high = mid - 1;
            cout << "High: " << high << endl;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3};
    int target = 3;
    int result = search(nums, target);
    cout << result << endl;
    return 0;
}