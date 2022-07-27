//--- Prtoblem Statement ---
/*Given two decimal numbers represented by two linked lists of size N and M respectively.
The task is to return a linked list that represents the sum of these two numbers.
For example, the number 190 will be represented by the linked list,
1->9->0->null, similarly 25 by 2->5->null.
Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null.
You are required to return the head of the linked list 2->1->5->null.*/

//--- Solution ---

void reverse(Node*& head)
    {
        Node* curr1=head;
        Node* curr2=head;
        int len=0;
        while(curr1)
        {
            len++;
            curr1=curr1->next;
        }
        curr1=head;
        if(len<=1)
            return ;
        else
        {
            while(curr1!=nullptr)
            {
                if(curr1->next == nullptr)
                {
                    curr1->next = curr2;
                    curr2=curr1;
                    curr1=nullptr;
                }
                else
                {
                    Node* temp = curr1;
                    swap(curr1, curr1->next->next);
                    swap(curr2, temp->next);
                }
            }
            head->next = curr1;
            head = curr2;
        }
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        reverse(first);
        reverse(second);
        Node* f=first;
        Node* s=second;
        Node* ans = new Node(0);
        Node* curr=ans;
        Node* temp;
        int x;
        int c=0;
        while(f!=nullptr && s!=nullptr)
        {
            x = f->data + s->data + c;
            curr->next = new Node(x%10);
            c=x/10;
            curr=curr->next;
            f=f->next;
            s=s->next;
            if(f==nullptr)
            {
                while(s)
                {
                    x = s->data + c;
                    curr->next = new Node(x%10);
                    c=x/10;
                    curr=curr->next;
                    s=s->next;
                }
            }
            else if(s==nullptr)
            {
                while(f)
                {
                    x = f->data + c;
                    curr->next = new Node(x%10);
                    c=x/10;
                    curr=curr->next;
                    f=f->next;
                }
            }
        }
        if(c!=0)
            curr->next = new Node(c);
        temp = ans;
        ans=ans->next;
        delete temp;
        reverse(ans);
        return ans;
    }
