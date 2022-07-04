//-- Probleam Statement ---

/*Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day.
Arrival and departure time can never be the same for a train
but we can have arrival time of one train equal to departure time of the other.
At any given instance of time, same platform can not be used for both departure of a train and arrival of another train.
In such cases, we need different platforms.*/

//--- Solution ---

int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int t[2361]={0};
    	int ans;
    	for(int i=0; i<n; i++)
    	{
    	    if(arr[i]%100>59)
    	    {
    	        arr[i]+=40;
    	    }
    	    if(dep[i]%100>59)
    	        dep[i]+=40;
    	}
    	for(int i=0; i<n; i++)
    	{
    	    t[arr[i]]++;
    	    t[dep[i]+1]--;
    	}
    	ans=t[0];
    	for(int i=1; i<=2360; i++)
    	{
    	    t[i]+=t[i-1];
    	    ans=max(ans, t[i]);
    	}
    	return ans;
	}
