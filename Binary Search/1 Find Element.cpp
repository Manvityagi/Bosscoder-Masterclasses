#include <bits/stdc++.h>
using namespace std;

bool linear_search(vector<int> arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return true;
    }
    return false;
}

bool binary_search(vector<int> arr, int num)
{
    int n = arr.size();
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (num == arr[mid])
        {
            return true;
        }
        else if (num > arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return false;
}

bool recursive_binary_search(vector<int> &arr, int num, int lo, int hi)
{
    if (lo > hi)
        return false;

    int mid = (lo + hi) >> 1;
    if (num == arr[mid])
    {
        return true;
    }
    else if (num > arr[mid])
    {
        if (recursive_binary_search(arr, num, mid + 1, hi))
            return true;
    }
    else
    {
        if (recursive_binary_search(arr, num, lo, mid - 1))
            return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int num;
    cin >> num;
    cout << linear_search(arr, num) << "\n";
    cout << binary_search(arr, num) << "\n";
    cout << recursive_binary_search(arr, num, 0, n - 1) << "\n";
    cout << binary_search(arr.begin(),arr.end(),num);
    return 0;
}