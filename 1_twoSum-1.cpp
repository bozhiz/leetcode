#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Solution
{
public:
    Solution() {}

    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i, j, tmp;
        for (i = 0; i < nums.size(); i++)
        {
            tmp = target - nums[i];
            cout << tmp << endl;
            if (tmp > 0)
            {
                for (j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j] == tmp)
                        return vector<int>{i, j};
                }
            }
        }

        return vector<int>{0, 0};
    }
};

int main(int argc, char *argv[])
{
    vector<int> input = {2, 7, 11, 15};
    vector<int> output;
    int target = 18;

    unique_ptr<Solution> pS(new Solution());

    output = pS->twoSum(input, target);
    cout << "[" << output[0] << ", " << output[1] << "]" << endl;

    return 0;
}
