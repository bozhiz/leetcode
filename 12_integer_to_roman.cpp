#include <unordered_map>
#include "tools.hpp"

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<string> roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> n{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string ans;

        while (num > 0)
        {
            for (int i = 0; i < roman.size(); i++)
            {
                if (n[i] <= num)
                {
                    ans.append(roman[i]);
                    num -= n[i];
                    break;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    unique_ptr<Solution> pS(new Solution());

    cout << pS->intToRoman(1994) << endl;

    return 0;
}
