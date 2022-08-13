//--- Problem Statement ---

/*You have infinite capacity for petrol.
Each unit of distance consumes one unit of petrol. Starting with 0 units of petrol.
You have to find the petrol pump from which you have to start your journey to reach all pretol pumps.
Return -1 if no such petrol pump exists.*/

//--- Solution ---

int solve(int* p, int* d, int n)
{
    int pet=0;
    int k, i=0, j=0;
    bool crossed=false;
    while(i<n)
    {
        pet+=p[j] - d[j];
        k=(j+1)%n;
        crossed=crossed+(j+1)/n;
        if(pet<0)
        {
            if(crossed)
                break;
            else
            {
                i=j+1;
                pet=0;
            }
        }
        else
        {
            if(crossed && k==i)
                return i;
        }
        j=k;
    }
    return -1;
}
