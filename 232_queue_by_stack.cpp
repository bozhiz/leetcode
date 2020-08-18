#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
private:
    stack<int> s;

public:
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stack<int> t;
        int i, l;

        if (s.size() == 0)
        {
            s.push(x);
            return;
        }

        l = s.size();
        for (i = 0; i < l; i++)
        {
            t.push(s.top());
            s.pop();
        }

        s.push(x);

        l = t.size();
        for (i = 0; i < l; i++)
        {
            s.push(t.top());
            t.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = s.top();
        s.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s.empty();
    }
};

int main(int argc, char *argv[])
{
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;

    return 0;
}
