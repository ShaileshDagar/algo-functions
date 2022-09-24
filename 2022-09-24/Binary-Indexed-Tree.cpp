//--- Binary Indexed Tree Implementation ---

/*
Implementation: Time - O(nLogn)
GetSum Query: Time - O(Logn)
Update: Time - O(Logn)
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getsum(const int BITree[], int i)
{
    int sum=0;
    i++;
    while(i)
    {
        sum+=BITree[i];
        i-=i&(-i);
    }
    return sum;
}
void update(int BITree[], int arr[], int n, int i, int v)
{
    int d = v - arr[i];
    arr[i]=v;
    i++;
    while(i<=n)
    {
        BITree[i]+=d;
        i+=i&(-i);
    }
}
int main() {
	int n,v;
	cin>>n;
	int arr[n];
	int BITree[n+1];
	for(int i=0; i<=n; i++)
	    BITree[i]=0;
	for(int i=0; i<n; i++)
	{
	    arr[i]=0;
	    cin>>v;
	    update(BITree, arr, n, i, v);
	}
	for(int i=0; i<=n; i++)
	    cout<<BITree[i]<<" ";
	return 0;
}
