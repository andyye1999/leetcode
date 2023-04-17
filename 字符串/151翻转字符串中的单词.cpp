#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void kongge(string &s)
{
    int slow = 0;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] != ' ')
        {
            if(slow != 0) s[slow++] = ' ';
            while(i < s.size() && s[i] != ' ')
            {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

string fanzhuan(string &s)
{
    kongge(s);
    reverse(s.begin(),s.end());
    int slow = 0;
    for(int i = 0;i < s.size();i++)
    {
        while(i < s.size() && s[i] != ' ') i++;
        reverse(s.begin()+slow,s.begin()+i);
        slow = i+1;
    }
    return s;
}