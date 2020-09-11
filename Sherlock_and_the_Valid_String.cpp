#include "tools.hpp"

using namespace std;

class Solution
{
public:
    string isValid(string s)
    {
        int d[26] = {0};
        // map<int, int> m;
        int t1 = 0, t2 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < s.size(); i++)
        {
            d[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (d[i] == 0)
                continue;

            if (t1 == 0)
            {
                t1 = d[i];
                c1++;
            }
            else if (t1 == d[i])
            {
                c1++;
                continue;
            }
            else if (t2 == 0)
            {
                t2 = d[i];
                c2++;
            }
            else if (t2 == d[i])
            {
                c2++;
            }
            else
                return "NO";
        }

        if (t1 == 0 || t2 == 0)
            return "YES";

        if (abs(t1 - t2) > 1)
            return "NO";

        if (c1 > 1 && c2 > 1)
            return "NO";

        return "YES";
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();

    cout << pS->isValid("aabbcd") << endl;

    delete pS;
    return 0;
}
