#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t--){
	    int n, h;
	    cin>> n >> h;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    sort(arr, arr+n);
	    int ans=0;
	    int j=n-1;
	    while(j>=0){
	        if((h-arr[j])<=0){
	            ans=arr[j];
	            break;
	        }
	        h-=arr[j];
	        j--;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
