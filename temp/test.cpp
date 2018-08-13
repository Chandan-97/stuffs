#include<bits/stdc++.h>
using namespace std;

int n,s,v[100000];

pair<int,int>p[100000];

int f(int m)
{
    int r=0,i,j,x,y,g,k,e=0;

    int v1[n]={0};

    for(i = 0; i < n; i++){
        x = p[i].second;
        y = p[i].first;
        // cout<<x<<" "<<y<<"\n";

        g = 0;
        k = min(n-1, x+m);
        j = max(e, x-m);

        for(;j <= k; j++){
            if(v[j] < y)
                g = max(g, v1[j]);
        }

        v1[x] = g+1;
        //cout<<v1[x]<<"\n";
        r += v1[x];
    }
    //cout<<r<<" "<<s<<"\n";
    if(r < s) return 1;
    return 0;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int x;
        int l=0,h,m,i,ans=0;
        unordered_map<int,bool>d;

        cin>>n>>s;
        for(i=0;i<n;i++)
            cin>>v[i];
        
        for(i=0;i<n;i++){
            //cout<<v[i]<<" ";
            p[i].first=v[i];
            p[i].second=i;
        }

        for(i=n;i<100000;i++){
            p[i].first=10000000000;
            p[i].second=i;
        }

        sort(p,p+100000);
        
        l=0;
        h=n;
        while(l<=h){
            m=(l+h)/2;
            // cout<<m<<"\n";

            if(d[m]!=1){
                d[m]=1;
                x=f(m);
            }
            else
                break;
            
            if(x==0)
                h=m-1;
            else
                l=m+1;
        }

        cout<<l<<"\n";
    }

    return 0;
}
