//--- Problem Statement ---
/*Given Pointer/Reference to the head of a doubly linked list of N nodes,
the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.*/

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
            h1->prev = curr;
            h1=h1->next;
            curr=curr->next;
        }
        else
        {
            curr->next=h2;
            h2->prev = curr;
            h2=h2->next;
            curr=curr->next;
        }
        if(h1==nullptr)
        {
            curr->next=h2;
            h2->prev=curr;
        }
        else if(h2==nullptr)
        {
            curr->next=h1;
            h1->prev=curr;
        }
    }
    m=m->next;
    delete m->prev;
    m->prev=nullptr;
    return m;
}
//Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head)
{
	int n=0;
    Node* curr=head;
    Node* s;
    while(curr)
    {
        n++;
        curr=curr->next;
    }
    if(n<2)
        return head;
    int k = (n+1)/2;
    curr=head;
    int count=1;
    while(count!=k)
    {
        count++;
        curr=curr->next;
    }
    s=curr->next;
    curr->next=nullptr;
    s->prev=nullptr;
    return merge(sortDoubly(head), sortDoubly(s));
}
