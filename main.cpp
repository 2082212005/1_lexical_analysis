#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

const int maxn=1e4+5;

map<string,string> mp;

void init()
{
    mp.clear();
    mp["BEGIN"]="Begin";
    mp["END"]="End";
    mp["FOR"]="For";
    mp["IF"]="If";
    mp["THEN"]="Then";
    mp["ELSE"]="Else";
    mp["IDENT"]="Ident";
    mp["INT"]="Int";
    mp[":"]="Colon";
    mp["+"]="Plus";
    mp["*"]="Star";
    mp[","]="Comma";
    mp["("]="LParenthesis";
    mp[")"]="RParenthesis";
    mp[":="]="Assign";
    mp["UNKNOWN"]="Unknown";
}
bool isLetter(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return true;
    else
        return false;
}
bool isDigit(char c)
{
	if(c>='0'&&c<='9')
        return true;
    else
        return false;
}

int main(int argc,char* argv[])
{
    init();
	fstream file1;
	file1.open(argv[1]);
	string s;
	file1 >> s;
	string str="";
	for(int i=0;i<s.length();)
    {
        while(s[i]==' '||s[i]=='\n'||s[i]=='\t'||s[i]=='\r')
            i++;
        if(isLetter(s[i]))
        {
            str+=s[i++];
            while(isLetter(s[i])||isDigit(s[i]))
                str+=s[i++];
            if(mp.find(str)!=mp.end())
                printf("%s\n",mp[str].c_str());
            else
                printf("%s(%s)\n",mp["IDENT"].c_str(),str.c_str());
            str="";
        }
        else if(isDigit(s[i]))
        {
            str+=s[i++];
            while(isDigit(s[i]))
                str+=s[i++];
            int j=0;
            if(str!="0")
            {
                for(j=0;str[j]=='0';j++)
                    ;
                str=str.substr(j);
            }
            printf("%s(%s)\n",mp["INT"].c_str(),str.c_str());
            str="";
        }
        else if(s[i]==':'&&s[i+1]!='=')
        {
            printf("%s\n",mp[":"].c_str());
            i++;
        }
        else if(s[i]==':'&&s[i+1]=='=')
        {
            printf("%s\n",mp[":="].c_str());
            i+=2;
        }
        else if(s[i]=='+')
        {
            printf("%s\n",mp["+"].c_str());
            i++;
        }
        else if(s[i]=='*')
        {
            printf("%s\n",mp["*"].c_str());
            i++;
        }
        else if(s[i]==',')
        {
            printf("%s\n",mp[","].c_str());
            i++;
        }
        else if(s[i]=='(')
        {
            printf("%s\n",mp["("].c_str());
            i++;
        }
        else if(s[i]==')')
        {
            printf("%s\n",mp[")"].c_str());
            i++;
        }
        else
        {
            printf("%s\n",mp["UNKNOWN"].c_str());
            break;
        }
    }
    file1.close();
    return 0;
}


