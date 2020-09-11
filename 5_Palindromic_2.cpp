#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        /* Manacher's algorithm */

        int i, id = 0, mr = 0, rid = 0, rlen = 0;
        string t = "$#";
        for (i = 0; i < s.length(); i++)
        {
            t += s[i];
            t += "#";
        }

        vector<int> p(t.length(), 0);

        for (i = 1; i < t.length(); i++)
        {
            p[i] = mr > i ? min(p[2 * id - i], mr - i) : 1;
            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;

            if (mr < p[i] + i)
            {
                mr = p[i] + i;
                id = i;
            }

            if (rlen < p[i])
            {
                rlen = p[i];
                rid = i;
            }
        }
        return s.substr((rid - rlen) / 2, rlen - 1);
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();

    cout << pS->longestPalindrome("a") << endl;
    cout << pS->longestPalindrome("abcdcba343abcdcba") << endl;
    cout << pS->longestPalindrome("cbbd") << endl;

    delete pS;
    return 0;
}
