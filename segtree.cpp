#include <bits/stdc++.h>
using namespace std;
class segnode{
    public:
    int val,lm,rm;
    segnode *left=NULL, *right=NULL;
    int build(vector <int> &a, int l, int r)
    {
        lm=l;
        rm=r;
        if(l==r)
        {
            val = a[l];
            return a[l];
        }
        int m = (l+r)/2;
        if(left==NULL)
        left = new segnode;
        if(right==NULL)
        right = new segnode;
        val = left->build(a,l,m) + right->build(a,m+1,r);
        return val;
    }
    int rmq(int l, int r)
    {
        cout<<"["<<lm<<","<<rm<<"] = "<<val<<endl;
        int ans=0;
        if(l<=lm && rm<=r)
        ans=val;
        else if(r<lm || rm<l)
        ans=0;
        else 
        ans=left->rmq(l,r)+right->rmq(l,r);
        return ans;
    }
    int update(int i, int v)
    {
        int m=(lm+rm)/2;
        if(lm==rm && lm==i)
        {
            val=v;
        }
        else if(i>m)
        {
            right->update(i,v);
            val = left->val + right->val;
        }
        else 
        {
            left->update(i,v);
            val = left->val + right->val;
        }
        return val;
    }
};
int main()
{
    segnode root;
    int i,k,n,l,r;
    char c;
    cin>>n;
    k = log2(n);
    k = pow(2,k);
    if(k<n)
    k*=2;
    vector<int> a(k,0);
    for(i=0;i<n;i++)
    cin>>a[i];
    i = root.build(a,0,k-1);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;
        cin>>k>>l;
        if(c=='u')
        cout<<root.update(k,l)<<endl;
        if(c=='s')
        cout<<root.rmq(k,l)<<endl;
    }
}