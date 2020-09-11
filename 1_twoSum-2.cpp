#include <iostream>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class Solution
{
public:
	Solution() {}

	vector<int> twoSum(vector<int> &nums, int target)
	{
		int i, tmp;
		map<int, int> mapEle;

		for (i = 0; i < nums.size(); i++)
			mapEle.insert({nums[i], i});

		for (i = 0; i < nums.size(); i++)
		{
			tmp = target - nums[i];
			auto it = mapEle.find(tmp);
			if (it != mapEle.end() && it->second != i)
				return vector<int>{i, it->second};
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
