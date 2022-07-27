//--- Problem Statement ---
/*Given a singly linked list of size N. The task is to left-shift the linked list by k nodes,
where k is a given positive integer smaller than or equal to length of the linked list.*/

//--- Solution ---

Node* rotate(Node* head, int k)
    {
        int n=1;
        Node* curr=head;
        while(curr->next!=nullptr)
        {
            curr=curr->next;
            n++;
        }
        if(k==n)
            return head;
        int count=1;
        Node* temp=head;
        while(count!=k)
        {
            temp=temp->next;
            count++;
        }
        curr->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
