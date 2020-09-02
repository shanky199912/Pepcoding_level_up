#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int findUnmatchedPairs(int n, string s1, string s2)
{
    if (s1.length() == 0 || s2.length() == 0)
        return 0;

    queue<char> q1;
    queue<char> q2;

    for (int i = 0; i < n; i++)
    {
        q1.push(s1[i]);
        q2.push(s2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        bool notfound = true;
        char ch = q1.front();
        if (ch != q2.front())
        {
            int size = q2.size();
            while (size-- > 0)
            {
                char temp = q2.front();
                q2.pop();
                q2.push(temp);

                if (q2.front() == q1.front())
                {
                    q1.pop();
                    q2.pop();
                    notfound = false;
                    break;
                }
            }
        }
        else{
            q1.pop();
            q2.pop();
            notfound = false;
        }

        if(notfound) return q1.size();
    }

    return q1.size();
}

void solve()
{

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    cout << findUnmatchedPairs(n, s1, s2) << endl;
}

auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main()
{
    solve();
    // cout << findUnmatchedPairs(4,"rmrm","mmmr") << endl;
    return 0;
}