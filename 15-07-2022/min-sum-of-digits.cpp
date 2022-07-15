//--- Problem Statement ---
/*Given an array of digits (values are from 0 to 9),
find the minimum possible sum of two numbers formed from digits of the array.
All digits of given array must be used to form the two numbers.*/

//--- Solution ---
long long int minSum(int arr[], int n)
    {
        // Your code goes here
        long long int a=0;
        long long int b=0;
        bool aturn=true;
        sort(arr, arr+n);
        for(int i=0; i<n; i++)
        {
            if(aturn)
            {
                a+=arr[i];
                if(i<n-2)
                    a*=10;
            }
            else
            {
                b+=arr[i];
                if(i<n-2)
                    b*=10;
            }
            aturn=!aturn;
        }
        return a+b;
    }
