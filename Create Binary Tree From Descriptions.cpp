class Solution {
    public:
        TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
            unordered_map<int, TreeNode*> hash, notroot;
            for (auto& it : descriptions) {
                int parent = it[0], child = it[1], isLeft = it[2];
                TreeNode* temp, *leftchild;
                if(hash.find(parent) != hash.end()){
                    temp = hash[parent];
                }
                else {
                    temp = new TreeNode(parent);
                    hash[parent] = temp;
                }
                
                if(hash.find(child) != hash.end()){
                    leftchild = hash[child];
                }
                else {
                    leftchild = new TreeNode(child);
                    hash[child] = leftchild;
                }
                if(isLeft) temp->left = leftchild;
                else temp->right = leftchild;
    
                // root issue
                notroot[child] = leftchild;
            }
            for(auto &itr:hash){
                if(notroot.find(itr.first) == notroot.end()) return hash[itr.first];
            }
            return nullptr;
        }
    };