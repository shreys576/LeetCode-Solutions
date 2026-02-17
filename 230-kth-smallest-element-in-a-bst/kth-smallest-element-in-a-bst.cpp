/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void Inorder(TreeNode* root, vector<int> &fin){
        if(root == NULL) return;
        Inorder(root -> left, fin);
        fin.push_back(root -> val);
        Inorder(root -> right, fin);
    }


    int kthSmallest(TreeNode* root, int k) {
        vector<int> fin;
        Inorder(root, fin);
        return fin[k - 1];
    }
};