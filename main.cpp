#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
double CalPostFix(vector<string>s)
{
    stack<double>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/")
        {
            char n= s[i][0];
            double kq=0;
            switch(n)
            {
                case '+':
                    {
                        int t2=st.top();st.pop();
                        int t1=st.top();st.pop();
                        kq=t1+t2;
                    }
                     break;
                case '-':
                    {
                        int t2=st.top();st.pop();
                        int t1=st.top();st.pop();
                        kq=t1-t2;
                    }
                     break;
                case '*':
                    {
                        int t2=st.top();st.pop();
                        int t1=st.top();st.pop();
                        kq=t1*t2;
                    }
                     break;
                case '/':
                    {
                        int t2=st.top();st.pop();
                        int t1=st.top();st.pop();
                        kq=t1/t2;
                    }
            break;
            }
            st.push(kq);
        }
        else
        {
            int cv=stoi(s[i]);
            st.push(cv);
        }
    }

    return st.top();
}
void PostList(vector<string>& s)
{
    stack<string>cal;
    vector<string>ss;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=="(")
        {
            cal.push(s[i]);
        }
        else if(s[i]==")")
        {
            while(cal.top()!="(")
            {
                ss.push_back(cal.top());
                cal.pop();
            }
            cal.pop();
        }
        else if(s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/")
        {
            if(s[i]=="*"||s[i]=="/")cal.push(s[i]);
            else
            {
                while(cal.top()!="(")
                {
                    ss.push_back(cal.top());
                    cal.pop();
                }
                cal.push(s[i]);
            }
        }
        else
        {
            if(s[i]!="("&&s[i]!=")")
            ss.push_back(s[i]);
        }
    }
            while(!cal.empty())
        {
            if(cal.top()!="(")ss.push_back(cal.top());
                cal.pop();
        }
        s.clear();

        s=ss;
}
void SToVs(string s, vector<string>& ss)
{
    int j=0;
    string r;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            {
                r+=s[i];
            }
        else
        {
            if(r!="")
            ss.push_back(r);
            r="";
            ss.push_back(std::string(1, s[i]));
        }
        if(i==s.size()-1&&r!="")ss.push_back(r);
    }
}
int main()
{
    string s;
    cin>>s;
    vector<string>ss;
    SToVs(s,ss);
    PostList(ss);
    for(int i=0;i<ss.size();i++)
    {
        cout<<ss[i]<<" ";
    }
    cout<<endl<<CalPostFix(ss);
}
