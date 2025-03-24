#include <bits/stdc++.h>

using namespace std;

// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     int n = (nums1.size() + nums2.size()) / 2;
//     int i = 0, j = 0, m1, m2;
//     for (int k = 0; k <= n; k++)
//     {
//         m1 = m2;
//         if (i < nums1.size() && (j >= nums2.size() || nums1[i] < nums2[j]))
//         {
//             m2 = nums1[i++];
//         }
//         else
//         {
//             m2 = nums2[j++];
//         }
//     }
//     if ((nums1.size() + nums2.size()) % 2 == 0)
//     {
//         return (m1 + m2) / 2.0;
//     }
//     else
//     {
//         return m2;
//     }
// }

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    vector<int> medianArray;

    int med = (m + n) / 2;

    int i = 0, j = 0, k = 0;

    while (i < m && j < n && k <= med)
    {
        if (nums1[i] <= nums2[j])
        {
            medianArray.push_back(nums1[i]);
            i++;
        }
        else
        {
            medianArray.push_back(nums2[j]);
            j++;
        }
        k++;
    }

    while (i < m && k <= med)
    {
        medianArray.push_back(nums1[i++]);
        k++;
    }

    while (j < n && k <= med)
    {
        medianArray.push_back(nums2[j++]);
        k++;
    }

    if ((m + n) % 2 == 0)
    {
        return (medianArray[medianArray.size() - 2] + medianArray[medianArray.size() - 1]) / 2.0;
    }
    else
    {
        return medianArray[medianArray.size() - 1];
    }
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
    return 0;
}