#include <iostream>  
#include <map>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
         * record each characters last position,
         * moving sliding window head faster by skiping
         */
        int i = 0, j = 0, maxLen = 0;
        map<char, int> m;
        
        for(i=j=0; i<s.size(); i++) {
            if(m.find(s[i]) == m.end()) {
                m.insert(pair<char, int>(s[i], i));
                maxLen = max(i-j+1, maxLen);
            }
            else {
                if(m[s[i]]>=j)
                    j = m[s[i]]+1;
                m[s[i]] = i;
                maxLen = max(i-j+1, maxLen);
            }
        }

        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    //string s("abcabcbb");
    //string s("dvdf");
    //string s("fjslfjsl3423l42j3fls32");
    Solution *pS = new Solution();
    string s("tmmzuxt");

	cout << pS->lengthOfLongestSubstring(s) << endl;

	return 0;
}
