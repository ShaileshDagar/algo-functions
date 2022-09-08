//--- Problem Statement ---

/*Given N activities with their start and finish day given in array start[ ] and end[ ].
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.*/

//--- Solution ---

int activitySelection(vector<int> start, vector<int> end, int n)
{
    int count=1;
    int last=0;
    pair<int, int> p[n];
    for(int i=0; i<n; i++)
    {
        p[i].first=start[i];
        p[i].second=end[i];
    }
    sort(p, p+n);
    for(int i=1; i<n; i++)
    {
        if(p[i].first<=p[last].second)
        {
            if(p[i].second<p[last].second)
                last=i;
        }
        else
        {
            count++;
            last=i;
        }
    }
    return count;
}
