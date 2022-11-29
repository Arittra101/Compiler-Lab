#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i, j;

#define pii pair<lli, lli>
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" \
                 << "\n";
#define no cout << "NO" \
                << "\n";
#define SORT(v) sort(v.begin(), v.end());
#define R_SORT(v) sort(v.begin(), v.end(), greater<lli>());
#define en "\n"

void solve()
{

    string line;
    lli cnt = 0;
    ofstream mylife2;
    mylife2.open("pupils.txt"); // write
    ifstream myfile("cp.txt");  // read

    if (!myfile.is_open())
        cout << "Failed to Open" << endl;
    else
    {

        bool samne_asbe = false;
        bool onelinecmnt = true;
        while (getline(myfile, line))
        {
            cnt++;
            for (i = 0; i < line.size(); i++)
            {
                if (onelinecmnt == false)
                {
                    samne_asbe = false;
                    onelinecmnt = true;
                }
                else if (line[0] == '/' && line[1] == '*')
                {
                    samne_asbe = true;
                    i++;
                }

                else if (line[0] == '/' && line[1] == '/')
                {
                    samne_asbe = true;
                    onelinecmnt = false;
                }
                else if (samne_asbe == false)
                {
                    if (line[i] != ' ')
                    {
                        cout << line[i];
                        mylife2 << line[i];
                    }
                }
                if (line[0] == '*' && line[1] == '/')
                {
                    samne_asbe = false;
                    i++;
                }
            }
        }
        myfile.close();
        mylife2.close();
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
