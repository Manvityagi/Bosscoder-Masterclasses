#include <bits/stdc++.h>
using namespace std;

/*

Lower Bound of x in an array = First Element >= x
Upper bound of x in an array = First Element > x


1. Iterators are used to point at the memory addresses
   of STL containers OR An iterator is an object
   that points to an element inside the container. 
2. begin() :- This function is used to return the 
   beginning position of the container.
3. end() :- This function is used to return the 
   after end position of the container. 

https://stackoverflow.com/questions/31128055/what-is-difference-between-iterators-and-pointers

*/

int lower_bound(vector<int> &arr, int x)
{
    int n = arr.size();
    int lo = 0, hi = n-1;
    int ans = n; //if lb doesnt exist, we gotta return n

    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] >= x){
            ans = min(ans,mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    return ans;
}

int upper_bound(vector<int> &arr, int x){
    int n = arr.size();
    int lo = 0, hi = n-1;
    int ans = n; //if lb doesnt exist, we gotta return n

    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] > x){
            ans = min(ans,mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << "Lower bound\n";
    cout << lower_bound(arr, x) << "\n";
    vector<int>::iterator low = lower_bound(arr.begin(), arr.end(), x);
    int lb = low - arr.begin();
    cout << lb << "\n";

    cout << "Upper bound\n";
    cout << upper_bound(arr, x) << "\n";
    cout << upper_bound(arr.begin(),arr.end(),x) - arr.begin() << "\n"; 

    return 0;
}