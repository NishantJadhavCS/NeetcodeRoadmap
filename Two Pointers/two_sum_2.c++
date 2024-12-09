#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Two Pointers Method
vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    vector<int> result;
    while (left < right)
    {
        if ((numbers[left] + numbers[right] == target) && (numbers[left] != numbers[right]))
        {
            result.push_back(left + 1);
            result.push_back(right + 1);
            return result;
        }
        else if ((numbers[left] + numbers[right] < target))
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
    vector<int> numbers = {1, 2, 3, 4};
    int target = 3;
    vector<int> result = twoSum(numbers, target);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}