//--- Problem Statement ---

/*Given an array arr[](0-based indexing) of N integers which is closer sorted (defined below) and an element x.
The task is to find the index of element x if it is present. If not present, then print -1.
Closer Sorted: The first array is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e, maybe to the arr[i+1] or arr[i-1].*/

//--- Solution ---

int binary_search(int a[], int n, int x)
    {
        int l=0, h=n-1;
        int mid;
        while(l<h)
        {
            mid=(l+h)/2;
            if(a[mid]==x)
                return mid;
            else if(mid-1>=0 && a[mid-1]==x)
                return mid-1;
            else if(mid+1<n && a[mid+1]==x)
                return mid+1;
            else if(a[mid]>x)
                h=mid-1;
            else if(a[mid]<x)
                l=mid+1;
        }
        return mid;
    }
    int closer(int arr[],int n, int x)
    {
        //Your code here
        int pos = binary_search(arr,n,x);
        if(arr[pos]==x)
            return pos;
        else
            return -1;
    }
