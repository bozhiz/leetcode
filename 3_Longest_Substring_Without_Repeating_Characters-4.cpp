#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        /*
         * record each characters last position,
         * moving sliding window head faster by skiping
         * 
         * use vector faster the character indexing
         */
        int i, j, maxLen = 0;
        int n = s.size();
        vector<int> v(256, -1);

        for (i = j = 0; i < n; i++)
        {
            j = max(j, v[s[i]] + 1);
            v[s[i]] = i;
            maxLen = max(i - j + 1, maxLen);
        }

        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    //string s("abcabcbb");
    //string s("dvdf");
    //string s("fjslfjsl3423l42j3fls32");
    string s("tmmzuxt");

    Solution *pS = new Solution();

    cout << pS->lengthOfLongestSubstring(s) << endl;

    return 0;
}
