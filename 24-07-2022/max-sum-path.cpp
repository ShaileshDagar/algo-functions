//--- Problem Statement ---
/*Given a Binary Tree, find the maximum sum path from a leaf to root.*/

//--- Solution ---

void calc(Node* root, int sum, int& ans)
    {
        if(root==nullptr)
            return ;
        sum+=root->data;
        ans=max(ans, sum);
        calc(root->left, sum, ans);
        calc(root->right, sum, ans);
    }
    int maxPathSum(Node* root)
    {
        //code here
        int ans=INT_MIN;
        int sum=0;
        calc(root, sum, ans);
        return ans;
    }
