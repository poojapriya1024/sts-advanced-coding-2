#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isLeaf(Node* root)
    {
        
        if(root == nullptr)
            return false;
            
        if(root->left == nullptr && root->right == nullptr)
            return true;
        
        return false;
    }
    void getLeftNodes(Node* root, vector<int>& solution)
    {
        //return if it is a leaf node
        if(isLeaf(root))
            return;
            
        solution.push_back(root->data);
        
        if(root->left != nullptr)
            getLeftNodes(root->left, solution);
        else if(root->right != nullptr)
            getLeftNodes(root->right, solution);
            
    }
    
    void inOrderTraversal(Node* root, vector<int>& solution)
    {   
        if(root == nullptr)
            return;
            
        if(isLeaf(root))
        {
            solution.push_back(root->data);
            return;
        }
         
        inOrderTraversal(root->left, solution);
        inOrderTraversal(root->right, solution);
        
    }
    
    void printArray(vector<int> arr)
    {
        for(auto &i: arr)
            cout<<i<<" ";
            
        cout<<endl;
    }
    
    void getRightNodes(Node* root, vector<int>& solution)
    {
        if(isLeaf(root))
            return;
            
        solution.push_back(root->data);
        
        if(root->right != nullptr)
            getRightNodes(root->right, solution);
        else if(root->left != nullptr)
            getRightNodes(root->left, solution);
            
    }

vector <int> boundary(Node *root)
{  
        vector<int> solution;
        solution.push_back(root->data);
        
        if(isLeaf(root))
            return solution;
        
        if(root->left != nullptr)
            getLeftNodes(root->left, solution);
            
        inOrderTraversal(root, solution);
        
        vector<int> rightNodes;
        if(root->right != nullptr)
            getRightNodes(root->right, rightNodes);
            
        if(rightNodes.empty())
            return solution;
            
        for(auto it = rightNodes.rbegin(); it!=rightNodes.rend(); it++)
            solution.push_back(*it);
            
        return solution;
        
        
}
int main()
{
    Node* root = new Node(2);
    Node* leftNode = new Node(4);
    Node* rightNode = new Node(8);
    rightNode->right = new Node(15);

    leftNode->left = new Node(16);
    leftNode->right = new Node(3);

    leftNode->right->left = new Node(9);
    leftNode->right->right = new Node(12);

    root->left = leftNode;
    root->right = rightNode;

    vector<int> solution = boundary(root);
    printArray(solution);

    return 0;
}