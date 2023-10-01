#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, h, curr = 0, maxi = 0;
	    cin >> n >> h;
	    vector<int> arr(n), temp;
	    for (int i = 0; i < n; i++) cin >> arr[i];
	    sort(arr.rbegin(), arr.rend());
	    int i = 0;
	    while(i < n && curr < h){
	        if (curr + arr[i] < h) curr += arr[i++];
	        else temp.push_back(arr[i++]);
	    }
	    if (!temp.empty()) maxi = *max_element(temp.begin(), temp.end());
	    cout << maxi << endl;
	}
	return 0;
}