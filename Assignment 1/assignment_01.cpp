#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i, j;

void solve()
{

    string line;
    lli cnt = 0;

    // write file
    ofstream mylife2;

    mylife2.open("pupils.txt"); // write

    ifstream myfile("cp.txt"); // read

    if (!myfile.is_open())
        cout << "Failed to Open" << endl;
    else
    {

        bool comment = true;
        while (getline(myfile, line))
        {
            
            for (i = 0; i < line.size(); i++)
            {

                if (line[0] == '/' && line[1] == '*')  comment = false;

                else if (line[0] == '*' && line[1] == '/')   comment = true;

                else if (line[0] == '/' && line[1] == '/')   break;

                else if (comment == true)
                {
                    if (line[i] != ' ')
                    {
                        cout << line[i];       //console print
                        mylife2 << line[i];  //file orint
                      
                    }
                }
               
               
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
