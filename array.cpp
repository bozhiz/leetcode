#include <iostream>

using namespace std;

int main()
{
    // int A[] = {10, 20, 0, 13, 15, 0, 0, 10, 40, 0};
    // ans: {10, 20, 13, 15, 10, 40, 0, 0, 0, 0}
    int A[] = {0, 0, 0, 0, 10};
    // ans: {10, 0, 0, 0, 0}
    int size = sizeof(A) / sizeof(A[0]);

    // optimized method, calculate next number 0 position quickly.
    // time complexity: O(n)
    // space complexity: O(1)
    int zero = -1;
    for (int i = 0; i < size; i++)
    {
        if (A[i] != 0)
        {
            if (zero >= 0)
            {
                A[zero] = A[i];
                A[i] = 0;

                // next zero position is right adjcent index
                zero += 1;
            }
        }
        else
        {
            if (zero == -1)
            {
                // first number zero position
                zero = i;
            }
        }
    }

    for (int l = 0; l < size; l++)
        cout << A[l] << " ";
    cout << endl;

    /*
    // time complexity: O(n)
    // space complexity: O(1)
    int zero = -1, last = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "i: " << i << ", A[i]: " << A[i] << endl;
        cout << "last: " << last << endl;
        cout << "zero: " << zero << endl;

        if (A[i] != 0)
        {
            if (zero >= 0)
            {
                A[zero] = A[i];
                A[i] = 0;

                zero = -1;

                cout << "last: " << last << endl;
            }
            else
            {
                last++;
                continue;
            }
        }

        // A[] = { 10, 20, 20, 0, 0, 0, 40 };

        if (zero == -1)
        {
            for (int j = last; j < size; j++)
            {
                if (A[j] == 0)
                {
                    zero = j;
                    cout << "finding next zero: " << zero << endl;
                    break;
                }
            }
        }
    }

    for (int l = 0; l < size; l++)
        cout << A[l] << " ";
    cout << endl;
*/

    /*
    // method 2: use new array
    // time complexity: O(n)
    // space complexity: O(n)
    vector<int> v(size, 0);

    for (int i = 0, j = 0; i < size; i++)
    {
        if (A[i])
            v[j++] = A[i];
    }

    for (auto num : v)
        cout << num << " ";
    cout << endl;
*/

    return 0;
}
