#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i, j;
#define pii  pair<lli, lli>
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define SORT(v) sort(v.begin(),v.end());
#define R_SORT(v) sort(v.begin(),v.end(),greater<lli>());
#define en "\n"

void solve()
{

    string line;
    lli cnt = 0;

   
    ofstream mylife2;

    mylife2.open("output.txt"); 

    ifstream myfile("input.txt"); 

    if (!myfile.is_open())
        cout << "Failed to Open" << endl;
    else
    {

        bool comment = true;
        while (getline(myfile, line))
        {
            lli cnt = 0;
            for (i = 0; i < line.size(); i++)
            {

                if (line[0] == '/' && line[1] == '*')
                    comment = false;

                else if (line[0] == '*' && line[1] == '/')
                    comment = true;

                else if (line[0] == '/' && line[1] == '/')
                    break;

                else if (comment == true)
                {

                    if (cnt == 0)
                    {
                        cout << ' ';
                        mylife2<<' ';
                    }

                    cout << line[i];    
                    mylife2 << line[i]; 
                }
                cnt++;
            }
        }
        myfile.close();
        mylife2.close();
    }
    // cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
