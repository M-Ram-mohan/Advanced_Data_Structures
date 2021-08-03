#include <bits/stdc++.h>
using namespace std;
class trienode{
    public:
    int val=0,x;
    trienode* edges[26] = {};
    string ans="";
    void insert(string &s, int st=0)
    {
        if(st==s.length())
        {
            val++;
            return;
        }
        x = s[st] - 'a';
        if(edges[x] == NULL)
        {
            edges[x] = new trienode;
        }
        edges[x]->insert(s,st+1);
        return;
    }
    int find(string &s,int st)
    {
        if(st==s.length())
        return val;
        x = s[st]-'a';
        if(edges[x] == NULL)
        return 0;
        return edges[x]->find(s,st+1);
    }
};
int main()
{
    trienode t;
}