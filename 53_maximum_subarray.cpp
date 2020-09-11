#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums)
        {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2{-7, -1, -3, -4, -1, -2, -1, -5, -4};
    Solution *pS = new Solution();

    cout << pS->maxSubArray(v1) << endl;
    cout << pS->maxSubArray(v2) << endl;

    delete pS;
    return 0;
}
