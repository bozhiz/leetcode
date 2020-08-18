#include <iostream>  
#include <set>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxLen = 0;
        set<char> v;
        
        while(i<s.size() && j<s.size()) {
            //cout<<s[i]<<endl;
            if(v.find(s[i]) == v.end()) {
                v.insert(s[i++]);
                maxLen = max((int)v.size(), maxLen);
            }
            else {
                /*
                std::cout << "myset contains:";
                for (std::set<char>::iterator it=v.begin(); it!=v.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << '\n';
                cout<<"i="<<i<<", b="<<b<<endl;
                */
                v.erase(s[j++]);
            }
        }

        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    //string s("abcabcbb");
    string s("dvdf");
    //string s("fjslfjsl3423l42j3fls32");
    Solution *pS = new Solution();

	cout << pS->lengthOfLongestSubstring(s) << endl;

	return 0;
}
