//TC: O(n) SC :O(n) in wost case where everything is stored in the queue at the beginning.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right=true;

        while(!q.empty()){
            int size=q.size();
            vector<int>ds(size);
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                int index = left_to_right?i:(size-i-1);
                ds[index]=root->val;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            left_to_right=!left_to_right;
                ans.push_back(ds);
       
        }
        return ans;
    }
};
