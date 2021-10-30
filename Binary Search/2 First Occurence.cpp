#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> arr, int num){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == num) return i;
    }
    return -1;
}

int binary_search(vector<int> arr, int num){
    int lo = 0, hi = arr.size()-1;
    int ans = hi+1;
    while(lo <= hi){
        int mid = (lo+hi) >> 1;
        if(num == arr[mid]){
            ans = min(ans,mid);
            hi = mid-1;
        } else if(num > arr[mid]){
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int num;
    cin >> num;
    cout << linear_search(arr,num) << "\n";
    cout << binary_search(arr,num);
    return 0;
}