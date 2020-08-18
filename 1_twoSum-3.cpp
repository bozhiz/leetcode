#include<iostream>  
#include<vector>
#include<map>
  
using namespace std; 

class Solution {
public:
	Solution() {}

    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
		map<int, int> m;
		 
        for(i=0; i<nums.size(); i++) {
            if(m.find(target - nums[i]) != m.end())
            	return {m[target - nums[i]], i};
            
            m[nums[i]] = i;
        }
        
        return {0, 0};
    }
};

int main(int argc, char *argv[])
{
	vector<int> input = {2, 7, 11, 15};
	vector<int> output;
	int target = 18;

	Solution *s = new Solution();

	output = s->twoSum(input, target);
	cout<<"["<<output[0]<<", "<<output[1]<<"]"<<endl;

	return 0;
}
