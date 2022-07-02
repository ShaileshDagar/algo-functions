/*---Problem Description
//Given an array of N elements and a number K. 
//The task is to arrange array elements according to the absolute difference with K, 
//i. e., element having minimum difference comes first and so on.
//Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.

static bool mycomp(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first<p2.first;
    }
    void sortABS(int a[],int n, int k)
    {
       //Your code here
        pair<int, int> p[n];
        for(int i=0; i<n; i++)
        {
            p[i].first=abs(a[i]-k);
            p[i].second=a[i];
        }
        stable_sort(p, p+n, mycomp);
        for(int i=0; i<n; i++)
        {
            a[i]=p[i].second;
        }
    }
