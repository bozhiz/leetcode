#include <unordered_map>
#include "tools.hpp"

using namespace std;

class Solution
{
public:
    void category_string(vector<string> &strs)
    {
        unordered_map<int, multiset<string>> um;

        for (auto i = 0; i < strs.size(); i++)
        {
            int len = strs[i].length();
            auto search = um.find(len);
            if (search != um.end())
            {
                search->second.insert(strs[i]);
            }
            else
            {
                um[len].insert(strs[i]);
            }
        }

        for (auto m = um.begin(); m != um.end(); m++)
        {
            for (auto s = m->second.begin(); s != m->second.end(); s++)
            {
                cout << m->first << "    " << *s << endl;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    unique_ptr<Solution> pS(new Solution());

    vector<string> v{
        "1",
        "12",
        "123",
        "1234",
        "12345",
        "123456",
        "1234567",
        "1",
        "12",
        "123",
        "1234",
        "12345",
        "123456"};

    pS->category_string(v);

    return 0;
}
