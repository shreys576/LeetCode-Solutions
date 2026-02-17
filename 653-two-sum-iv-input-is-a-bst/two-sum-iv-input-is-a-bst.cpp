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

    bool findTarget(TreeNode* root, int k) {
        vector<int> fin;
        Inorder(root, fin);
        int l = 0;
        int r = fin.size() - 1;
        while(l < r){
            int sum = fin[l] + fin[r];
            if(sum == k) return true;
            else if(sum > k) r--;
            else l++;
        }
        return false;
    }
};