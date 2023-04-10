#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string st)
    {
        if (st.length() == 0)
        {
            return true;
        }

        stack<char> s;
        for (auto i : st)
        {
            if (i == '(' || i == '{' || i == '[')
            {
                s.push(i);
            }
            else
            {
                if (s.empty())
                    return false;
                if ((i == ')' && s.top() == '(') || (i == '}' && s.top() == '{') || (i == ']' && s.top() == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return s.empty();
    }
};