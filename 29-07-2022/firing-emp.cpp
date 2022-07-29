//--- Problem Statement ---
/*Geek is the founder of Geek Constructions. He always maintains a black-list of potential employees which can be fired at any moment.
The company has N employees (including Geek), and each employee is assigned a distinct rank (1 <= rank <= N) at the time of joining.
The company has a hierarchical  management such that each employee always has one immediate senior. 
Geek has a strange and unfair way of evaluating an employees performance.
He sums the employee's rank and the number of seniors the employee has. If it is a prime number,
the employee is put up on the black-list.
Given an array arr[] in order of the rank of company employees.
For rank i, arr[i] represents the rank of the immediate senior of the employee with the ith rank.
If geek's rank is i, then arr[i] is always equal to 0 as there is no one senior to him.
Find out the number of Black-Listed employees.
Note: The black-list can not contain Geeks name as he is the founder of the company and he is the one that makes the list.*/

//--- Solution ---

void sieve(bool* prime, int n)
{

    memset(prime, true, n+1);

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int find_actual(vector<int>& actual, const vector<int>& given, int i)
{
    if(actual[i]>=0)
        return actual[i];
    else
    {
        actual[i]=1+find_actual(actual, given, given[i]);
        return actual[i];
    }
}
int firingEmployees(vector<int> &given, int n){
    vector<int> actual(n, INT_MIN);
    bool prime[2*n];
    sieve(prime, 2*n-1);
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(!given[i])
            actual[i]=0;
        given[i]--;
    }
    for(int i=0; i<n; i++)
    {
        actual[i] = find_actual(actual, given, i);
        if(actual[i] && prime[actual[i]+i+1])
            count++;
    }
    return count;
}
