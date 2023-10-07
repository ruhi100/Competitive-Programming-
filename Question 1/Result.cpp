#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,h;
	    cin>>n>>h;
	    vector<int> v;
	    int a;
	    for(int i=0;i<n;i++){
	        cin>>a;
	        v.push_back(a);
	    }
	    sort(v.begin(),v.end());
	    int ans=0;
	    for(int i=v.size()-1;i>=0;i--){
	        if(h<=v[i]){
	            ans=v[i];
	            break;
	        }
	        else{
	            h-=v[i];
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}