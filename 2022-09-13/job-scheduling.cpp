//--- Problem Statement ---

/*Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.*/

//--- Solution ---

class myComparator
{
public:
    int operator() (const Job& j1, const Job& j2)
    {
        return j1.profit>j2.profit;
    }
};

static bool mycomp(const Job& j1, const Job& j2)
{
    if(j1.dead==j2.dead)
        return j1.profit>j2.profit;
    else
        return j1.dead<j2.dead;
}
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    priority_queue<Job, vector<Job>, myComparator> sjpq;
    int t=0, pt=0;
    sort(arr, arr+n, mycomp);
    for(int i=0; i<n; i++)
    {
        if(arr[i].dead>t)
        {
            sjpq.push(arr[i]);
            pt+=arr[i].profit;
            t++;
        }
        else
        {
            if(arr[i].profit>sjpq.top().profit)
            {
                pt+=(arr[i].profit-sjpq.top().profit);
                sjpq.pop();
                sjpq.push(arr[i]);
            }
        }
    }
    return {t, pt};
} 
