//--- Problem Statement ---
/*Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to the node at position X.
If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present.*/

//--- Solution ---

bool detectLoop(Node* head, Node*& p1, Node*& p2)
    {
        while(p2 && p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
            if(p2)
                p2=p2->next;
        }
        if(p2==nullptr)
            return false;
        return true;
    }
int countNodesinLoop(struct Node *head)
{
    int ans=0;
    Node* p1=head;
    Node* p2=head->next;
    if(detectLoop(head, p1, p2))
    {
        ans++;
        p1=p1->next;
        while(p1!=p2)
        {
            p1=p1->next;
            ans++;
        }
    }
    return ans;
}
    void removeLoop(Node* head)
    {
        int x = countNodesinLoop(head);
        if(x==0)
            return ;
        Node* f=head;
        Node* l=head;
        int count=1;
        while(count!=x)
        {
            l=l->next;
            count++;
        }
        while(l->next!=f)
        {
            f=f->next;
            l=l->next;
        }
        l->next=nullptr;
        return ;
    }
