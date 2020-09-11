#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int i, v, r = 0;
        bool m = false;

        for (i = 0; i < str.length() && str[i] == ' '; i++)
        {
            ;
        }

        if (str[i] == '-')
        {
            m = true;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }

        for (; i < str.length(); i++)
        {
            if (str[i] < '0' || str[i] > '9')
                break;

            v = str[i] - '0';
            if (m)
                v = 0 - v;

            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && v >= 7))
                return INT_MAX;
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && v <= -8))
                return INT_MIN;

            r = r * 10 + v;
        }

        return r;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();

    cout << pS->myAtoi("42") << endl;
    cout << pS->myAtoi("-42") << endl;
    cout << pS->myAtoi("2147483647") << endl;
    cout << pS->myAtoi("2147483648") << endl;
    cout << pS->myAtoi("-2147483648") << endl;
    cout << pS->myAtoi("-2147483649") << endl;
    cout << pS->myAtoi("  +004500") << endl;

    delete pS;
    return 0;
}
