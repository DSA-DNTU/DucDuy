#include <iostream>
#include <stack>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char x : s)
    {
        if (x == '(' || x == '{' || x == '[')
        {
            st.push(x); // đẩy phần tử vô ngăn xếp
        }
        else if (x == ')' || x == '}' || x == ']')
        {
            if (st.empty()) // check ngăn xếp rỗng
            {
                cout << "Invalid\n";
                return;
            }
            char top = st.top(); // phần tử đầu ngăn xếp
            if ((x == ')' && top != '(') ||
                (x == ']' && top != '[') ||
                (x == '}' && top != '{'))
            {
                cout << "INVALID\n";
                return;
            }
            st.pop(); // lấy phần tử ra ngăn xếp
        }
    }
    if (st.empty()) // check ngăn xếp rỗng
    {
        cout << "Valid\n";
    }
    else
        cout << "Invalid\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}