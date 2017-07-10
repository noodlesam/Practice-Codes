//Serialize and deserialize binary tree

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
        if (root == NULL) {
            return "# ";
        }
        return to_string(root -> val) + " " + serialize(root -> left) + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream in(data);
        return deserialize_helper(in);
    }
    
    TreeNode *deserialize_helper(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root -> left = deserialize_helper(in);
        root -> right = deserialize_helper(in);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
