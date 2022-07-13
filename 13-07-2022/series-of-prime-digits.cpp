//--- Problem Statement ---
/*Given a number 'N'. The task is to find the Nth number whose each digit is a prime number i.e 2, 3, 5, 7.
In other words you have to find nth number of this sequence : 2, 3, 5, 7, 22, 23 ,.. and so on.*/

//--- Solution ---

int primeDigits(int n)
    {
        //code here
        int ans=0;
        int d = ceil(log2(3*n + 4)/2)-1;
        int map1[4] = {7,2,3,5};
        double pow4=pow(4,d-1);
        int sd1;
        int x;
        while(d>1)
        {
            sd1=4*((pow4-1)/3);
            x=ceil((n-sd1)/pow4);
            ans+=map1[x%4];
            pow4/=4;
            ans*=10;
            d--;
        }
        ans+=map1[n%4];
        return ans;
    }
