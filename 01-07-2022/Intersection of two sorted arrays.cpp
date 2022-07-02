//--- Problem Discription ---
/*
The intersection of two arrays contains the elements common to both the arrays.
The intersection should not count duplicate elements.
Given two sorted arrays arr1[] and arr2[] of sizes N and M respectively. Find their intersection.*/

vector<int> printIntersection(int a[], int b[], int n, int m) 
    { 
        //Your code here
        vector<int> ans;
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                ans.push_back(a[i]);
                do
                {
                    i++;
                }while(i<n && a[i]==a[i-1]);
                do
                {
                    j++;
                }while(j<m && b[j]==b[j-1]);
            }
            else if(a[i]<b[j])
            {
                do
                {
                    i++;
                }while(i<n && a[i]<b[j]);
            }
            else
            {
                do
                {
                    j++;
                }while(j<m && b[j]<a[i]);
            }
        }
        if(ans.empty())
            ans.push_back(-1);
        return ans;
    }
