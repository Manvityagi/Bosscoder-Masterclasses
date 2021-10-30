#include<bits/stdc++.h>
using namespace std; 
#define int long long
//if c cows can be placed at distance = x, 
//then definitely c cows can be placed at any distance < x
//we will try to place the cows at distance > x   
bool check(vector<int> pos, int numOfCows, int minDistance){
    int prevPos = 0;
    int cows = 1;  
    for(int i = 1; i < pos.size(); i++){
        if(pos[i] - pos[prevPos] >= minDistance){
            prevPos = i; 
            cows++; 
        }
    }
    if(cows < numOfCows) return false;
    return true;
}

signed main(){
    int t; 
    cin >> t; 
    while(t--){
        int n,c;
        cin >> n >> c; 
        vector<int> pos(n);
        for(int i = 0; i < n; i++) cin >> pos[i]; 
        sort(pos.begin(),pos.end()); 
        int low = pos[1] - pos[0]; 
        int high = pos[n-1] - pos[0]; 
        int ans = 0; 

    //linear search
        for(int dis = high; dis >= low; dis--){
            if(check(pos,c,dis)) {
                cout << "LS " << dis << "\n";
                break;
            }
        }

    //binary search
        while(low <= high){
            int mid = (low + high)/2; //min distance bw any 2 cows 
            if(check(pos,c,mid)){
                ans = max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1; 
            }
        }
        cout << "BS " << ans << "\n"; 
    }
}