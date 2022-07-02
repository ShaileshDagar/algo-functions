//--- Problem Description ---

/*Given two arrays X and Y of positive integers,
find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.*/

long long countPairs(int x[], int y[], int m, int n)
    {
       //Your code here
        sort(x, x+m);
        sort(y, y+n);
        long long sum=0;
        int count1y=0, count2y=0;
        for(int i=0; i<n; i++)
        {
            if(y[i]==1)
                count1y++;
            else if(y[i]==2)
                count2y++;
            else
                break;
        }
        for(int i=0; i<m; i++)
        {
            if(x[i]==1)
                continue;
            else if(x[i]==2)
            {
                sum+=count1y;
                sum+=((y+n)-upper_bound(y, y+n, 4));
            }
            else if(x[i]==3)
            {
                sum+=count1y+count2y;
                sum+=((y+n)-upper_bound(y, y+n, 3));
            }
            else
            {
                sum+=count1y;
                sum+=((y+n)-upper_bound(y, y+n, x[i]));
            }
        }
        return sum;
    }
