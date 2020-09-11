#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i, b = -1, max = 0;
        set<char> v;

        for (i = 0; i < s.size(); i++)
        {
            cout << s[i] << endl;
            if (v.find(s[i]) == v.end())
            {
                if (b == -1)
                    b = i;
                v.insert(s[i]);
            }
            else
            {
                std::cout << "myset contains:";
                for (std::set<char>::iterator it = v.begin(); it != v.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << '\n';
                cout << "i=" << i << ", b=" << b << endl;
                if (v.size() > max)
                {
                    max = v.size();
                }
                v.clear();
                i = b;
                b = -1;
            }
        }

        if (v.size() > max)
        {
            max = v.size();
        }

        return max;
    }
};

int main(int argc, char *argv[])
{
    //string s("abcabcbb");
    string s("dvdf");
    //string s("fjslfjsl3423l42j3fls32");
    unique_ptr<Solution> pS(new Solution());

    cout << pS->lengthOfLongestSubstring(s) << endl;

    return 0;
}
