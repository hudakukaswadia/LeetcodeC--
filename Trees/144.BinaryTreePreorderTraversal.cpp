// Time complexity: O(n)
// Space complexity: O(n)

// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if (root == NULL) {
            return preOrder;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* topNode = s.top();
            preOrder.push_back(topNode -> val);
            s.pop();
            if (topNode -> right != NULL) {
                s.push(topNode -> right);
            }
            
            if(topNode -> left != NULL) {
                s.push(topNode -> left);
            }
        }
        return preOrder;
    }            
};

// Recursive

class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        
        res.push_back(root -> val);
        preOrder(root -> left, res);
        preOrder(root -> right, res);    
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }            
};