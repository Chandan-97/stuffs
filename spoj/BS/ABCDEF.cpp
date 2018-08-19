#include <bits/stdc++.h>
#define sz 105
#define ll long long
#define fast ios_base::sync_with_stdio(false);
#define tc int t; cin>>t; while(t--)
#define fin for(int i=0; i<n; i++)
#define clr(a) memset(a, 0LL, sizeof(a))

using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;

	ll arr[n];
	for(int  i=0; i<n; i++) cin>>arr[i];

	unordered_map <ll, ll> memo;
	for(int a : arr){
		for(int b : arr){
			for(int c : arr){
				memo[a*b + c] += 1;
			}
		}
	}

	ll ans = 0LL;
	for(int d : arr){
		if(d==0)
			continue;
		for(int e : arr){
			for(int f : arr){
				ans += memo[(f+e)*d]*1LL;
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
























