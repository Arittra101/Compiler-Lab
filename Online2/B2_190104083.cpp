/*
 id : 190104083
 Date : 22.12.22
 Group : B2
 Online 02
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i, j;
#define pii  pair<lli, lli>

void solve()
{
    string s;
    cin>>s;
    lli ln = s.size();
    if(s[0]=='c')
    {
        lli flag=0;
        lli ind = 0;
        for(i=1; i<ln; i++)
        {
            if(s[i]=='_')  ind = i;

            flag=1;
        }
        if(flag==1)
        {
            for(int k=1; k<ind; k++)
            {
                if(s[k]>='a' && s[k]<='z') flag=1;
                else
                {
                    flag=0;
                    cout<<"String does not follow the patter"<<endl;
                    return;
                }
            }
            lli cnt=0;
            for(int  k=ind+1; k<s.size(); k++)
            {
                lli x = s[k]-'0';
                if(x>=0 && x<=9)  cnt++;

                else
                {
                    cout<<"String does not follow the patter"<<endl;
                    return;
                }
            }
            if(cnt>=2)  cout<<"follow  the pattern"<<endl;

            else
            {
                cout<<"String does not follow the patter"<<endl;
                return;
            }
        }
        else cout<<"String does not follow the patter"<<endl;

    }
    else cout<<"String does not follow the patter"<<endl;
}
int main()
{

    solve();
    return 0;
}
