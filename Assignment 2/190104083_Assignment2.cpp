#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i, j;
#define pii  pair<lli, lli>

   ofstream output_file;
   ifstream input_file("input.txt");
//set up part

lli flag =0;
map<string,int>k_map;
map<char,int>op_map;
map<char,int>paren_map;
map<char,int>sperator_map;
vector<string>keyWord
{
    "auto", "break", "case", "char",
    "const", "continue", "default", "do",
    "double", "else", "enum", "extern",
    "float", "for", "goto", "if",
    "int", "long", "register", "return",
    "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

vector<char>parenthesis
{
    '(', ')', '{', '}', '[', ']'
};
vector<char>operato
{
    '+', '-', '*', '/', '%', '=', '<', '>'
};

vector<char>separator{',', ';', '\'', '\"', ':'};

void sep_key_set()
{
    for(int m2=0; m2<separator.size(); m2++) sperator_map[separator[m2]]=1;
}
void paren_key_set()
{
    for(int m2=0; m2<parenthesis.size(); m2++)paren_map[parenthesis[m2]]=1;
}
void map_key_set()
{
    for(int m2=0; m2<keyWord.size(); m2++)k_map[keyWord[m2]]=1;

}
void map_op_set()
{
    for(int m2=0; m2<operato.size(); m2++) op_map[operato[m2]]=1;
}

//set up part

//method------
void isKeyWord(string s)
{
    if(k_map[s]==1)
    {
        cout<<"[kw "<<s<<"]"<<" ";
        output_file<<"[kw "<<s<<"]"<<" ";
        flag = 1;
    }
}

void isParenthesis(string s)
{
    lli cnt=0;
    for(int m2=0; m2<s.size(); m2++)
    {
        if(paren_map[s[m2]]==1)   cnt++;

    }
    if(cnt==s.size() && cnt>0)
    {
        flag=1;
        cout<<"[par "<<s<<"]"<<" ";
        output_file<<"[par "<<s<<"]"<<" ";
    }
    else flag=0;
}

void isOperator(string s)
{

    lli cnt=0;
    for(int m2=0; m2<s.size(); m2++)
    {
        if(op_map[s[m2]]==1)    cnt++;

    }
    if(cnt==s.size())
    {
        flag=1;
        cout<<"[op "<<s<<"]"<<" ";
        output_file<<"[op "<<s<<"]"<<" ";
    }
    else flag=0;
}

void isSeparator(string s)
{
    lli cnt=0;

    for(int m2=0; m2<s.size(); m2++)
    {
        if(sperator_map[s[m2]]==1)
        {
            cnt++;
        }
    }
    if(cnt==s.size() && cnt>0)
    {
        flag=1;
        cout<<"[sep "<<s<<"]"<<" ";
        output_file<<"[sep "<<s<<"]"<<" ";
    }
    else flag=0;
}

void isNumber(string s)
{
    lli cnt=0;
    for(int m=0; m<s.size(); m++)
    {
        lli x = s[m]-'0';
        if(x>=0 && x<=9 || s[m]=='.') cnt++;
    }
    if(cnt==s.size())
    {
        cout<<"[num "<<s<<"]"<<" ";
        output_file<<"[num "<<s<<"]"<<" ";
        flag=1;
    }
    else flag=0;

}

void isIdentifier(string s)
{
    if(k_map[s]==1)
    {
        return;
    }
    lli cnt=0;
    if(s[0]>='A' && s[0]<='Z' || s[0]>='a' && s[0]<='z' || s[0]=='_' )
    {
        cnt++;
        for(int k=1; k<s.size(); k++)
        {
            if(s[k]>='A' && s[k]<='Z' || s[k]>='a' && s[k]<='z' || s[k]=='_' || s[k]>='0' && s[k]<='9') cnt++;

        }
        if(cnt==s.size())
        {
            flag =1;
            cout<<"[id "<<s<<"]"<<" ";
            output_file<<"[id "<<s<<"]"<<" ";
        }
        else flag=0;
    }

}
//method------//

//checking method-----//
void check(string s)
{

    if(!flag)
        isKeyWord(s);
    if(!flag)
        isIdentifier(s);
    if(!flag)
        isNumber(s);
    if(!flag)
        isOperator(s);
    if(!flag)
        isParenthesis(s);
    if(!flag)
        isSeparator(s);
    if(!flag) {
            cout<<"[Undefined "<<s<<"]"<<" ";
            output_file<<"[Undefined "<<s<<"]"<<" ";
    }

}
//checking method-----//

void main_code(string line)
{
    string str="";
    for(i=0; i<line.size(); i++)
    {
        if(line[i]!=' ')str+=line[i];

        if(line[i]==' ')
        {

            flag=0;

            check(str);
            str="";
        }
    }
    if(i==(line.size()))
    {
        flag=0;
        check(str);
    }
}



//Read and write from file
void solve()
{
    map_key_set();
    map_op_set();
    paren_key_set();
    sep_key_set();

    string line;
    lli cnt = 0;

    output_file.open("output1.txt");


    if (!input_file.is_open())
        cout << "Failed to Open" << endl;
    else
    {

        cout<<"INPUT: "<<endl;
        while (getline(input_file, line))
        {
            cout<<line<<endl<<endl;
            output_file<<line<<endl<<endl;
            cout<<"OUTPUT "<<endl;
            output_file<<"OUTPUT "<<endl;
            main_code(line);
        }

        input_file.close();
        output_file.close();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
