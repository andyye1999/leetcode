#include <iostream>
#include <string>
#include <stack>

using namespace std;

// stack用法
bool kuohao(string s)
{
    if(s.size() % 2 == 1) return false;
    stack<char> st;
    for(int i =0;i < s.size();i++)
    {
        if(s[i] == '(') st.push(')');
        else if (s[i] == '{') st.push('}');
        else if (s[i] == '[') st.push(']');
        else if(st.empty() || st.top() != s[i]) return false;
        else st.pop();
    }
    if(st.empty()) return true;
    else return false;
}

int main()
{
    string s;
    cin >> s;
    cout << kuohao(s) << endl;
    return 0;
}