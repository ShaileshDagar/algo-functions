//--- Problem Statement ---

/*Geek lost the password of his super locker. 
He remembers the number of digits N as well as the sum S of all the digits of his password. 
He know that his password is the largest number of N digits that can be made with given sum S. 
As he is busy doing his homework, help him retrieving his password.*/

//--- Solution ---

string largestNumber(int n, int sum)
{
    // Your code here
    string ans;
    int c = ceil(sum/9.0);
    int sz;
    char ch;
    if(c>n)
        return "-1";
    while(sum>=9)
    {
        ans+="9";
        sum-=9;
    }
    if(sum)
    {
        ch='0'+sum;
        ans+=ch;
    }
    sz=ans.size();
    while(sz++<n)
        ans+="0";
    return ans;
}
