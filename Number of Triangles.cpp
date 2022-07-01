//--- Problem Discription ---
/*
Given an unsorted array arr[] of n positive integers.
Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.*/

int findNumberOfTriangles(int a[], int n)
    {
        // code here
        int ans=0;
        sort(a, a+n);
        for(int i=n-1; i>=2; i--)
        {
            int j=i-1, k=0;
            while(j>k)
            {
                if(a[j]+a[k]>a[i])
                {
                    ans+=j-k;
                    j--;
                }
                else
                    k++;
            }
        }
        return ans;
    }