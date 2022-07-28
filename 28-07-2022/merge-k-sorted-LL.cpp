//--- Problem Statement ---
/*Given K sorted linked lists of different sizes.
The task is to merge them in such a way that after merging they will be a single sorted linked list.*/

//--- Solution ---

Node* merge(Node* h1, Node* h2)
{
    Node* m = new Node(0);
    Node* curr=m;
    while(h1 && h2)
    {
        if(h1->data<=h2->data)
        {
            curr->next=h1;
            h1=h1->next;
            curr=curr->next;
        }
        else
        {
            curr->next=h2;
            h2=h2->next;
            curr=curr->next;
        }
        if(h1==nullptr)
        {
            curr->next=h2;
        }
        else if(h2==nullptr)
        {
            curr->next=h1;
        }
    }
    curr=m;
    m=m->next;
    delete curr;
    return m;
}
//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int k)
{
    pair<int, Node*> p[k];
    Node* ans;
    Node* curr;
    int count;
    for(int i=0; i<k; i++)
    {
        p[i].second=arr[i];
        curr=arr[i];
        count=0;
        while(curr)
        {
            count++;
            curr=curr->next;
        }
        p[i].first=count;
    }
    sort(p, p+k);
    ans=p[0].second;
    for(int i=1; i<k; i++)
        ans = merge(ans, p[i].second);
    return ans;
}
