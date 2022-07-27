//--- Problem Statement ---
/*Given a linked list of N nodes.
The task is to check if the linked list has a loop.
Linked list can contain self loop.*/

//--- Solution ---

bool detectLoop(Node* head)
    {
        Node* p1=head;
        Node* p2=head->next;
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
