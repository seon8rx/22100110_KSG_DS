#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:    
    int val;
    TreeNode *left, *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* maketree(int array[], int size) {
    if (array == NULL) return NULL;
    
    TreeNode* root = new TreeNode(array[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while (i < size) {
        TreeNode* curr = que.front();
        que.pop();
        if (i < size) {
            if(array[i]!=0){
                curr->left = new TreeNode(array[i++]);
                que.push(curr->left);
            }else{
                curr->left = nullptr;
                i++;
            }
        }
        if (i < size) {
            if(array[i]!=0){
                curr->right = new TreeNode(array[i++]);
                que.push(curr->right);
            }else{
                curr->right = nullptr;
                i++;
            }
        }
    }
    return root;
}

void printInorder(TreeNode* treenode){
    if(treenode == nullptr) return;
    printInorder(treenode->left);
    cout << treenode->val << " ";
    printInorder(treenode->right);
}

void printPreorder(TreeNode* treenode){
    if(treenode == nullptr) return;
    cout << treenode->val << " ";
    printPreorder(treenode->left);
    printPreorder(treenode->right);
}

void printPostorder(TreeNode* treenode){
    if(treenode == nullptr) return;
    printPostorder(treenode->left);
    printPostorder(treenode->right);
    cout << treenode->val << " ";
}

int main(){
    int size, mode;
    cin >> size >> mode;

    int array[size];

    for(int i=0; i<size; i++){
        cin >> array[i];
    }

    TreeNode* result = maketree(array, size);
    if(mode == 1){
        cout << "preorder traversal: ";
        printPreorder(result);
    }else if(mode == 2){
        cout << "postorder traversal: ";
        printPostorder(result);
    }


    return 0;
}