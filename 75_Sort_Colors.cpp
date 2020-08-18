#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /*
         * The solution requires the use of tracking 3 positions, the Low, Mid and High.
         * We assume that the mid is the "Unknown" area that we must evaluate.
         * If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.
         * To achieve this in one pass without preprocessing (counting), we simply traverse the unknown will generating the low and high ends.
         */
        int zero = 0, second = nums.size() - 1, i;

        for (i = zero; i <= second; i++)
        {
            while (nums[i] == 2 && i < second)
                swap(nums[i], nums[second--]);
            while (nums[i] == 0 && i > zero)
                swap(nums[i], nums[zero++]);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> v1 = {2, 0, 2, 1, 1, 0};
    vector<int> v2 = {2, 0, 1};
    vector<int> v3 = {1, 2, 0};

    pS->sortColors(v1);
    for (auto v : v1)
        cout << v << " ";
    cout << endl;
    pS->sortColors(v2);
    for (auto v : v2)
        cout << v << " ";
    cout << endl;
    pS->sortColors(v3);
    for (auto v : v3)
        cout << v << " ";
    cout << endl;

    return 0;
}
