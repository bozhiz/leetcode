#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int i, l = 0, r = nums.size() - 1;
        int kth = nums.size() - k;

        while (l < r)
        {
            i = partition(nums, l, r);
            if (i < kth)
                l = i + 1;
            else if (i > kth)
                r = i - 1;
            else
                break;
        }
        return nums[kth];
    }

private:
    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[l];
        int i = l + 1, j = r;

        while (i <= j)
        {
            if (nums[i] > pivot && nums[j] < pivot)
                swap(nums, i++, j--);
            if (nums[i] <= pivot)
                i++;
            if (nums[j] >= pivot)
                j--;
        }
        swap(nums, l, j);
        return j;
    }

    void swap(vector<int> &nums, int l, int r)
    {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> v1 = {3, 2, 1, 5, 6, 4};

    cout << pS->findKthLargest(v1, 2) << endl;
    // cout << v1 << endl;

    return 0;
}
