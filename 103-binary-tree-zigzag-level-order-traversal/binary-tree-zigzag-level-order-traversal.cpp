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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> fin;
        if(root == NULL) return fin;
        bool flag = false;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>levelElements;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                levelElements.push_back(frontNode -> val);
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }
            if(flag){
                reverse(levelElements.begin(), levelElements.end());
            }
            fin.push_back(levelElements);
            flag = !flag;

        }
        return fin;
    }
};