#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// reserve 头文件algorithm
string fanzhuan(string s,int k)
{

    for(int i = 0;i < s.size();i += (2*k))
    {
        if(i+k <= s.size())
        {
            reverse(s.begin()+i,s.begin()+i+k);
        }
        else
        {
            reverse(s.begin()+i,s.end());
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    string result = fanzhuan(s,n);
    cout << result << endl;
    return 0;
}