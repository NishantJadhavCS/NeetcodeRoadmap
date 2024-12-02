#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Map
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> result;
    unordered_map<int, int> map;
    for (int i : nums)
    {
        map[i]++;
    }
    while (k != 0)
    {
        int max = 0;
        int maxv = 0;
        for (auto pair : map)
        {
            if (pair.second > max)
            {
                max = pair.second;
                maxv = pair.first;
            }
        }
        result.push_back(maxv);
        map.erase(maxv);
        k--;
    }
    return result;
}

int main()
{
    vector<int> nums = {4, 4, 3, 8, 6, 1, 8, 6};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}