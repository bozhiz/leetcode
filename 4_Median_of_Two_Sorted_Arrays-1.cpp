#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        int m1, m2;
        double ans = 0.0;

        int l1 = nums1.size();
        int l2 = nums2.size();

        if ((l1 + l2) % 2)
            m1 = m2 = (l1 + l2) / 2 + 1;
        else
        {
            m1 = (l1 + l2) / 2;
            m2 = m1 + 1;
        }

        for (int m = 0; m < m1; m++)
        {
            if (i == l1)
            {
                ans = nums2[j];
                j++;
            }
            else if (j == l2)
            {
                ans = nums1[i];
                i++;
            }
            else if (i < l1 && nums1[i] <= nums2[j])
            {
                ans = nums1[i];
                i++;
            }
            else if (j < l2 && nums1[i] > nums2[j])
            {
                ans = nums2[j];
                j++;
            }
        }

        if (m1 == m2)
            return ans;

        if (i == l1)
        {
            ans += nums2[j];
            ans /= 2;
        }
        else if (j == l2)
        {
            ans += nums1[i];
            ans /= 2;
        }
        else if (i < l1 && nums1[i] <= nums2[j])
        {
            ans += nums1[i];
            ans /= 2;
        }
        else if (j < l2 && nums1[i] > nums2[j])
        {
            ans += nums2[j];
            ans /= 2;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v1 = {1, 3};
    vector<int> v2 = {3, 4};

    Solution *pS = new Solution();

    cout << pS->findMedianSortedArrays(v1, v2) << endl;

    delete pS;
    return 0;
}
