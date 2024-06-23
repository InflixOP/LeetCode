/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s="";
        string null = "null";
        if(!root) return s;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp!=NULL){
            s+=to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
            }
            else{
                s+= null + ",";
            }
        }
        return s;
    }
    string next_element(string& s){
        char c =s[0];
        string ans;

        while(c!=','){
            ans.push_back(c);
            s.erase(s.begin());
            c=s[0];
        }
        s.erase(s.begin());
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        queue<TreeNode*> q;
        string temp=next_element(data);
        TreeNode* root = new TreeNode(stoi(temp));
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            string left = next_element(data);
            string right=next_element(data);
            if(left=="null") x->left=NULL;
            else{
                TreeNode* l = new TreeNode(stoi(left));
                x->left=l;
                q.push(l);
            }
            if(right=="null") x->right=NULL;
            else{
                TreeNode* r = new TreeNode(stoi(right));
                x->right=r;
                q.push(r);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root))