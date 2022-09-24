//--- Segment Tree Implementation ---

/*
Constructing Segment Tree: Time - Theta(n) | Space - Theta(n)
Range Query: Time - O(Logn)
Update Query: Time - O(Logn)
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cST(const int arr[], int tree[], int s, int e, int id)
{
    if(s==e)
    {
        tree[id] = arr[s];
        return tree[id];
    }
    int mid = (s+e)/2;
    tree[id] = cST(arr, tree, s, mid, 2*id + 1)
                + cST(arr, tree, mid+1, e, 2*id + 2);
    return tree[id];
}
int range(const int tree[], const int qs, const int qe, int ts, int te, int id)
{
    int mid = (ts+te)/2;
    if(qs == ts && qe == te)
        return tree[id];
    else if(qe<=mid)
        return range(tree, qs, qe, ts, mid, 2*id+1);
    else if(qs>mid)
        return range(tree, qs, qe, mid+1, te, 2*id+2);
    else
        return range(tree, qs, mid, ts, mid, 2*id+1)
                + range(tree, mid+1, qe, mid+1, te, 2*id+2);
}
void update(int tree[], int ts, int te, int id, const int ui, const int diff)
{
    tree[id]+=diff;
    int mid = (ts+te)/2;
    if(ts == te)
        return ;
    else if(ui<=mid)
        update(tree, ts, mid, 2*id+1, ui, diff);
    else
        update(tree, mid+1, te, 2*id+2, ui, diff);
}
int main() {
	int n;
	cin>>n;
	int size = pow(2, ceil(log2(n)) + 1) - 1;
	int arr[n];
	int tree[4*n];
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	for(int i=0; i<size; i++)
	    tree[i]=-1;
	cST(arr, tree, 0, n-1, 0);
	for(int i=0; i<size; i++)
	    cout<<tree[i]<<" ";
	int qs, qe;
	cin>>qs>>qe;
	cout<<endl<<range(tree, qs, qe, 0, n-1, 0)<<endl;
	int uv, ui;
	cin>>ui>>uv;
	update(tree, 0, n-1, 0, ui, uv-arr[ui]);
	for(int i=0; i<size; i++)
	    cout<<tree[i]<<" ";
	return 0;
}
