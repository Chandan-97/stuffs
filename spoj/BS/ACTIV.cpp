#include <bits/stdc++.h>
#define sz 105
#define ll long long
#define fast ios_base::sync_with_stdio(false);
#define tc int t; cin>>t; while(t--)
#define fin for(int i=0; i<n; i++)
#define clr(a) memset(a, 0LL, sizeof(a))

using namespace std;

int n;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2){
	return p1.second < p2.second;
}

int main(){
	while(true){
		cin>>n;
		if(n==-1)
			return 0;
		vector <pair<ll, ll> > v(n);
		int set_contain[n];
		int set_max[n];
		int total_set = 0;
		memset(set_contain, 0, sizeof set_contain);
		memset(set_max, 0, sizeof set_max);
		for(int i=0; i<n; i++){
			int x, y;
			cin>>x>>y;
			v[i] = {x, y};
		}

		sort(v.begin(), v.end(), cmp);

		vector <ll> arr;

		ll dp[2][n];
		memset(dp, 0, sizeof dp);
		ll mod = 100000000LL;

		// don't include v[0]
		dp[0][0] = 0;

		// include v[0]
		dp[1][0] = 1;
		arr.push_back(v[0].second);

		for(int i=1; i<n; i++){
			int idx = upper_bound(arr.begin(), arr.end(), v[i].first) - arr.begin();
			idx--;
			if(idx >=0 && arr[idx] <= v[i].first){
				dp[0][i] = dp[0][i-1] + dp[1][i-1];
				dp[1][i] = 1 + dp[0][idx] + dp[1][idx];
			}
			else{
				dp[0][i] = dp[0][i-1] + dp[1][i-1];
				dp[1][i] = 1;
			}

			dp[0][i] %= mod;
			dp[1][i] %= mod;

			arr.push_back(v[i].second);
		}

		ll ans = (dp[0][n-1] + dp[1][n-1]) % mod;

		printf("%0.8d\n", ans);

	}
}
