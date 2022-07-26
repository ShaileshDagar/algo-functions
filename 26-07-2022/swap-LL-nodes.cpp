//--- Problem Statement ---
/*Given a singly linked list of size N, and an integer K.
You need to swap the Kth node from the beginning and Kth node from the end of the linked list.
Swap the nodes through the links. Do not change the content of the nodes.*/

//--- Solution ---

Node *swapkthnode(Node* head, int n, int k)
{
    if(k>n || n+1==2*k)
        return head;
    Node* f = new Node(0);
    f->next=head;
    head=f;
    Node* p1=head;
    Node* p2=head;
    Node* t1;
    Node* t2;
    int count=1;
    while(count!=k)
    {
        p1=p1->next;
        count++;
    }
    t1=p1->next;
    k=n+1-k;
    count=1;
    while(count!=k)
    {
        p2=p2->next;
        count++;
    }
    t2=p2->next;
    p2->next=t1;
    p1->next=t2;
    Node* t1next=t1->next;
    t1->next=t2->next;
    t2->next=t1next;
    t1next=head;
    head=head->next;
    delete t1next;
    return head;
}
