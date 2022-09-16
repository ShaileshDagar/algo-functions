//--- Problem Statement ---

/*There are given N ropes of different lengths, 
we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. 
The task is to connect the ropes with minimum cost.*/

//--- Solution ---

long long minCost(long long arr[], long long n) {
  long long ans=0;
  long long cost;
  priority_queue<long long, vector<long long>, greater<long>> pq(arr, arr+n);
  while(pq.size()>1)
  {
      cost=pq.top();
      pq.pop();
      cost+=pq.top();
      pq.pop();
      ans+=cost;
      pq.push(cost);
  }
  return ans;
}
