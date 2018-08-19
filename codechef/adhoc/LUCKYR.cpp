#include <bits/stdc++.h>
#define sz 105
#define ll long long
#define fast ios_base::sync_with_stdio(false);
#define tc int t; cin>>t; while(t--)
#define fin for(int i=0; i<n; i++)
#define clr(a) memset(a, 0LL, sizeof(a))

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int n = str.length();
		int arr[n];
		memset(arr, 0, sizeof arr);

		int cnt = 0;
		ll maxm = 0;
		ll cnt_r = 0;
		for(int i=0; i<n; i++){
			if(str[i] == 'R'){
				cnt_r++;
				if(cnt == 0)
					continue;
				else
					cnt--;
			}
			else{
				cnt++;
				maxm = max((ll)cnt, maxm);
			}
		}

		ll ans = maxm + cnt_r;
		cout<<ans<<endl;
	}
	return 0;
}
