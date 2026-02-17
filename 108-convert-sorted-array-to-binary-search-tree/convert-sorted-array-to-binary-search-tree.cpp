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

    TreeNode* makeBST(TreeNode* root, vector<int> &nums, int l, int r){
        if(l > r) return NULL;
        int mid = (l + r)/2;
        TreeNode* newnode = new TreeNode(nums[mid]);
        root = newnode;
        root -> left = makeBST(root -> left, nums, l, mid - 1);
        root -> right = makeBST(root -> right, nums, mid + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //find mid element -> (l + r) / 2
        //make nums[mid] the curr ndode
        // recursively build -
        //LST -> nums[l]....... mid - 1
        //RST -> nums[mid + 1].......r
        //return
        int l = 0;
        int r = nums.size() - 1;
        TreeNode* root = new TreeNode(0);
        root = makeBST(root, nums, l, r);
        return root;

    }
};