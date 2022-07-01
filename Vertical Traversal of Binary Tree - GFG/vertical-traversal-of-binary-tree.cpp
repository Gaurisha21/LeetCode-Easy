// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void width(Node *root, vector<int> &minMax, int l)
    {
        if(root==NULL)
            return;
        minMax[0] = min(l,minMax[0]);
        minMax[1] = max(l,minMax[1]);
        width(root->left,minMax, l-1);
        width(root->right,minMax, l+1);
    }
    
    vector<int> verticalOrder(Node *root)
    {
        vector<int> minMax = {INT_MAX,INT_MIN};
        width(root,minMax,0);
        int sn = minMax[1]-minMax[0]+1;
        vector<vector<int>> ans(sn);
        queue<pair<Node*,int>> q;
        q.push({root,abs(minMax[0])});
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0; i<s; i++)
            {
                pair<Node*,int> node = q.front();
                q.pop();
                ans[node.second].push_back(node.first->data);
                if(node.first->left!=NULL)
                    q.push({node.first->left,node.second-1});
                if(node.first->right!=NULL)
                    q.push({node.first->right,node.second+1});
            }
        }
        vector<int> nums;
        for(vector<int> arr : ans)
        {
            for(int ele : arr)
                nums.push_back(ele);
        }
        return nums;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


  // } Driver Code Ends