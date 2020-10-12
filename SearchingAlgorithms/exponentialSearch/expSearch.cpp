#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int l, int r, int x) { 
	if (r >= l) { 
		int mid = l + (r - l)/2; 

		if (arr[mid] == x) 
			return mid; 

		if (arr[mid] > x) 
			return binarySearch(arr, l, mid-1, x); 

		return binarySearch(arr, mid+1, r, x); 
	} 

	return -1; 
}  

int exponentialSearch(int arr[], int n, int x) { 
	if (arr[0] == x) 
		return 0; 

	int i = 1; 
	while (i < n && arr[i] <= x) 
		i = i*2; 

	return binarySearch(arr, i/2, min(i, n), x); 
} 

int main() { 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;

    int res = exponentialSearch(arr, n, x); 
    if(res == -1)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at index"<<res;

    return 0; 
} 
