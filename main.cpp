#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct BinarySearchTree {
    BinarySearchTree* left = NULL;
    BinarySearchTree* right = NULL;
    int value;
    
};

BinarySearchTree* GetNewNode(int val);
BinarySearchTree* insert(BinarySearchTree* root, int val);
bool lookup(BinarySearchTree* root, int val);
void displayPreOrder(BinarySearchTree* root);
vector<int> DFSInOrder(BinarySearchTree* root, vector<int> *vec);
vector<int> DFSPostOrder(BinarySearchTree* root, vector<int> *vec);
vector<int> DFSPreOrder(BinarySearchTree* root, vector<int> *vec);
void display(vector<int> vec);
vector<int> breadthFirstSearch(BinarySearchTree* root);
vector<int> breadthFirstSearchRecursive(BinarySearchTree* root);

BinarySearchTree* GetNewNode(int val) {
    BinarySearchTree* newNode = new BinarySearchTree();
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BinarySearchTree* insert(BinarySearchTree* root, int val) {
    if(root == NULL) {
        root = GetNewNode(val);
    }
    else if(val <= root->value) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool lookup(BinarySearchTree* root, int val) {
    if (root == NULL) return false;
    if (root->value == val) return true;
    else if(val <= root->value) return lookup(root->left, val);
    else return lookup(root->right, val);
}

vector<int> breadthFirstSearch(BinarySearchTree* root) {
    BinarySearchTree* currentNode = root;
    vector<int> vec;
    list<BinarySearchTree*> queue;
    
    queue.push_back(currentNode);
    
    while (queue.size() > 0) {
        currentNode = queue.front();
        queue.pop_front();
        cout << currentNode->value << endl;
        vec.push_back(currentNode->value);
        if (currentNode->left) {
            queue.push_back(currentNode->left);
        }
        if (currentNode->right) {
            queue.push_back(currentNode->right);
        }
    }
    
    return vec;
}

vector<int> breadthFirstSearchRecursive(list<BinarySearchTree*> queue, vector<int> vec) {
    if (!queue.size()) {
        return vec;
    }
    
    BinarySearchTree* currentNode = queue.front();
    queue.pop_front();
    cout << currentNode->value << endl;
    vec.push_back(currentNode->value);
    if (currentNode->left) {
        queue.push_back(currentNode->left);
    }
    if (currentNode->right) {
        queue.push_back(currentNode->right);
    }
    
    return breadthFirstSearchRecursive(queue, vec);
}

vector<int> DFSInOrder(BinarySearchTree* root, vector<int>* vec) {
    
    if (root->left) {
        DFSInOrder(root->left, vec);
    }
    
    vec->push_back(root->value);
    
    if (root->right) {
        DFSInOrder(root->right, vec);
    }
    
    return *vec;
}

vector<int> DFSPreOrder(BinarySearchTree* root, vector<int>* vec) {
    
    vec->push_back(root->value);
    
    if (root->left) {
        DFSPreOrder(root->left, vec);
    }
    
    if (root->right) {
        DFSPreOrder(root->right, vec);
    }
    
    return *vec;
}

vector<int> DFSPostOrder(BinarySearchTree* root, vector<int> *vec) {
    
    if (root->left) {
        DFSPostOrder(root->left, vec);
    }
    
    if (root->right) {
        DFSPostOrder(root->right, vec);
    }
    
    vec->push_back(root->value);
    
    return *vec;
}


void display(vector<int> vec) {
    for (int item: vec)
        cout << item << " ";
    cout << endl;
}


void displayPreOrder(BinarySearchTree* root) {
    if (root == NULL)
        return;
    cout << "<" << root->value << ">" << " " << endl;
    
    displayPreOrder(root->left);
    
    displayPreOrder(root->right);
}

int main(){
    BinarySearchTree* root = NULL;
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 20);
    root = insert(root, 170);
    root = insert(root, 15);
    root = insert(root, 1);
    cout << lookup(root, 10) << " Found?" << endl;
    cout << lookup(root, 30) << " Found?" << endl;
    
    displayPreOrder(root);

    cout << endl;
    
    breadthFirstSearch(root);
    
    cout << endl;
    
    breadthFirstSearchRecursive({root}, {});
    
    cout << endl;
    
    vector<int> *vec = new vector<int>;
    cout << "InOrder" << endl; 
    display(DFSInOrder(root, vec));
    vec->clear();
    
    cout << endl;
    
    cout << "PreOrder" << endl; 
    display(DFSPreOrder(root, vec));
    vec->clear();
    
    cout << endl;
    
    cout << "PostOrder" << endl; 
    display(DFSPostOrder(root, vec));
    vec->clear();
    
    delete vec;
    
    return 0;
}