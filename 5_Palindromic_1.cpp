#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l, r, i, j;
        int len = s.length();
        string max;

        for (i = 0; i < len; i++)
        {
            // odd length
            l = i;
            r = i;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                l -= 1;
                r += 1;
            }
            if (r - l - 1 > max.length())
                max = s.substr(l + 1, r - l - 1);

            // even length
            l = i - 1;
            r = i;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                l -= 1;
                r += 1;
            }
            if (r - l - 1 > max.length())
                max = s.substr(l + 1, r - l - 1);
        }
        return max;
    }
};

int main(int argc, char *argv[])
{
    //string s("abcabcbb");
    //string s("dvdf");
    //string s("fjslfjsl3423l42j3fls32");
    string s1("a");
    string s2("abcdcba343abcdcba");

    Solution *pS = new Solution();

    cout << pS->longestPalindrome(s1) << endl;
    cout << pS->longestPalindrome(s2) << endl;

    return 0;
}
