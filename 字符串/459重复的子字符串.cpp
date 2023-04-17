#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s)
{
    return (s + s).find(s, 1) != s.size();
}

int main()
{
    string s;
    cin >> s;
    cout << repeatedSubstringPattern(s) << endl;
    return 0;
}