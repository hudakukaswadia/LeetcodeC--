// Time complexity: O(n)
// Space complexity: O(n)

// Iterative

class Solution {
public:    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;
        while(true) {
            if(node != NULL) {
                st.push(node);
                node = node -> left;
            }
            else {
                if (st.empty() == true) {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node -> val);
                node = node -> right;
            }
        }
        return inorder;
    }
};


// Recursive

class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &res){
        if (root == NULL) {
            return;
        }
        inOrder(root -> left, res);
        res.push_back(root -> val);
        inOrder(root -> right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};

