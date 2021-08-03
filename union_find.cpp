#include<bits/stdc++.h>
using namespace std;
class unionfind{
    public:
    unordered_map<int,int> parent;
    void initiate(int n)
    {
        parent.clear();
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    void Union(int x, int y)
    {
        parent[find(y)]=find(x);
        return;
    }
    int find(int y)
    {
        if(parent[y]==y)
        return y;
        return find(parent[y]);
    }
    bool isunion(int x, int y)
    {
        if(parent[find(x)]==parent[find(y)])
        return 1;
        else 
        return 0;
    }
};
int main()
{
    unionfind uf;
    int n;
    cin>>n;
    uf.initiate(n);
    uf.Union(4,3);
    uf.Union(0,1);
    uf.Union(4,0);
    uf.Union(5,2);
    cout<<uf.isunion(4,2)<<endl;
}