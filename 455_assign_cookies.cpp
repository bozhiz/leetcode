#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i, j;
        for (i = 0, j = 0; i < g.size() && j < s.size(); j++)
        {
            if (s[j] >= g[i])
                i++;
        }

        return i;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    vector<int> g2 = {10, 9, 8, 7};
    vector<int> s2 = {8, 7, 6, 5};

    cout << pS->findContentChildren(g1, s1) << endl;
    cout << pS->findContentChildren(g2, s2) << endl;

    delete pS;
    return 0;
}
