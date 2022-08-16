//--- Problem Statement ---

/*A(X) for positive integer X is the sum of factorials of its digits. 
For example, A(154) = 1! + 5! + 4!= 145.
Given a number N, find the minimum number X such that A(X) = N. 
You have to return a list of digits which represent the number X.*/

//--- Solution ---

vector<int> FactDigit(int n)
{
    vector<int> ans;
    vector<int> fact;
    fact.push_back(1);
    for(int i=2; i<10; i++)
        fact.push_back(i*fact.back());
    vector<int>::iterator itr;
    while(n)
    {
        itr = lower_bound(fact.begin(), fact.end(), n);
        if(itr==fact.end() || *itr>n)
            itr--;
        ans.push_back(itr-fact.begin()+1);
        n-=*itr;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
