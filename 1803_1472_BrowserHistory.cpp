#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
    int ind;
    vector<string> history;

public:
    BrowserHistory(string homepage)
    {
        ind = 0;
        history.push_back(homepage);
    }

    void visit(string url)
    {
        int i = history.size() - 1;
        while (i > ind)
        {
            history.pop_back();
            i--;
        }
        ind++;
        history.push_back(url);
    }

    string back(int steps)
    {
        ind -= steps;
        if (ind < 0)
            ind = 0;
        return history[ind];
    }

    string forward(int steps)
    {
        ind += steps;
        if (ind >= history.size())
            ind = history.size() - 1;
        return history[ind];
    }
};

int main()
{

    return 0;
}