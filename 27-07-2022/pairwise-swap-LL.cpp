//--- Problem Statement ---
/*Given a linked list of N positive integers.
You need to swap elements pairwise.*/

//--- Solution ---

struct Node* pairwise_swap(struct Node* head)
{
    Node* f = new Node(0);
    f->next=head;
    head=f;
    Node* p1=head;
    Node* t1=p1->next;
    Node* p2=t1;
    Node* t2=p2->next;
    Node* t1next;
    while(t1 && t2)
    {
        //swap
        p2->next=t1;
        p1->next=t2;
        t1next=t1->next;
        t1->next=t2->next;
        t2->next=t1next;
        
        //update
        p1=t1;
        t1=t1->next;
        p2=t1;
        if(p2)
            t2=p2->next;
    }
    head=head->next;
    delete f;
    return head;
}
