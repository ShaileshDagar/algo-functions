//--- Problem Statement ---
/*Given a singly linked list of size N of integers.
The task is to check if the given linked list is palindrome or not.*/

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
    bool isPalindrome(Node *head)
    {
        bool ans=true;
        int n=0;
        Node* temp=head;
        Node* f=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        temp=head;
        int k = (n+3)/2;
        int count=1;
        while(count!=k)
        {
            count++;
            temp=temp->next;
        }
        reverse(temp);
        k=n/2;
        count=0;
        while(count<k)
        {
            if(f->data!=temp->data)
            {
                ans=false;
                break;
            }
            f=f->next;
            temp=temp->next;
            count++;
        }
        return ans;
    }
