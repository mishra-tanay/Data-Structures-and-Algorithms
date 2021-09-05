/** Problem Link : https://leetcode.com/problems/count-complete-tree-nodes/
  * Category: Medium
  */
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
    TreeNode* getNode(int val, TreeNode* root,int height){
        val--;
        for(int h = height-1;h>=0 ; h--){
            root = ((val >> h) & 1) == 1 ? root->right : root->left;
            if(root == nullptr){
                break;
            }
        }
        return root;
    }
    int countNodes(TreeNode* root) {
        int left_height = 0;
        int right_height = 0;
        TreeNode* curr = root;
        while(curr){
            left_height++;
            curr = curr->left;
        }
        curr = root;
        while(curr){
            right_height++;
            curr = curr->right;
        }
        long long int ans = pow(2,right_height)-1;
        
        if(right_height == left_height){
            return ans;
        } else{
            long long int low = 1;
            long long int high = pow(2,left_height-1);
            long long int last_level_nodes = 0;
            while(low <=high){
                int mid = (low + high)/2;
                auto node = getNode(mid,root,right_height);
                if(node == nullptr){
                    high = mid-1;
                } else{
                    last_level_nodes = mid;
                    low = mid+1;
                }
            }
            return ans + last_level_nodes;
        }
    }
};
