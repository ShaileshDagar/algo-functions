//--- Problem Statement ---
/*Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node*/

//--- Solution ---

void answer(struct Node* root, int& sum)
    {
        if(root==nullptr)
            return ;
        if(root->right)
            answer(root->right, sum);
        sum+=root->data;
        root->data=sum-(root->data);
        if(root->left)
            answer(root->left, sum);
        return ;
    }
    void transformTree(struct Node *root)
    {
        //code here
        int sum=0;
        answer(root, sum);
    }
