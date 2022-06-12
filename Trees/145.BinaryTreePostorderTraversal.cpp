// Recursive 

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public: 
    void postOrder(TreeNode* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        
        postOrder(root -> left, res);
        postOrder(root -> right, res);
        res.push_back(root -> val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};

// Iterative PostOrder Traversal using 2 Stacks

// Time complexity: O(N)
// Space complexity: O(2N)

class Solution {
public: 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == NULL) {
            return postOrder;
        }
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        
        st1.push(root);
        
        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root -> left != NULL) {
                st1.push(root -> left);
            }
            if (root -> right != NULL) {
                st1.push(root -> right);
            }
        }
        
        while (!st2.empty()) {
            postOrder.push_back(st2.top() -> val);
            st2.pop();
        }
        return postOrder;
    }     
};


// Iterative PostOrder Traversal using 1 stack

// Time complexity: O(2N)
// Space complexity: O(N)

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {

        vector<int> postOrder;
        if (root == NULL)
            return postOrder;

        stack<TreeNode *> st;
        while (root != NULL || !st.empty())
        {
            if (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else
                    root = temp;
            }
        }
        return postOrder;
    }
};