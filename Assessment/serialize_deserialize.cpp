#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream temp;
        ToString(root, temp);
        return temp.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream temp(data);
        return ToStructure(temp);
    }

private:
    // Serialize helper function
    void ToString(TreeNode* root, ostringstream& temp) {
        if (root == nullptr) {
            temp << "N ";
            return;
        }
        temp << root->val << " ";
        ToString(root->left, temp);
        ToString(root->right, temp);
    }

    // Deserialize helper function
    TreeNode* ToStructure(istringstream& temp) {
        string value = "";
        temp >> value;
        if (value == "N") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(value));
        root->left = ToStructure(temp);
        root->right = ToStructure(temp);
        return root;
    }
};

// Example usage in main function
int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Create a codec object
    Codec codec;

    // Serialize the tree
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the serialized string
    TreeNode* deserialized = codec.deserialize(serialized);

    // Output the reconstructed tree (in serialized form for verification)
    string reserialized = codec.serialize(deserialized);
    cout << "Reserialized tree: " << reserialized << endl;

    return 0;
}
