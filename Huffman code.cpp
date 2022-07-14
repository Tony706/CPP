#include <iostream> 
#include <algorithm>
#include <queue> 
using namespace std;
class Node
{
	public:
	    int freq;
	    Node* left;
	    Node* right;
	    Node(int frequency)
			{
	        freq = frequency;
	        left = right = NULL;
	    	}
};
	
class Compare
{
	public:
	    bool operator()(Node* f, Node* g)
			{
			return f->freq > g->freq;
			}
};	
int printValue(Node* root, int top)
{   
    static int total = 0;
    if (root->left) 
        printValue(root->left,  top + 1);
    if (root->right) 
        printValue(root->right, top + 1);
    if (!root->left && !root->right)
        total += top  * root->freq;
    return total;
}
int main()
{
    int size;
    cin >> size;
    int freq[size];
    
	for (int w = 0; w < size; w++)
		{
        cin >> freq[w];
    	}	
    sort(freq, freq + size);
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int w = 0; w < size; w++)
		{
        Node* newNode = new Node(freq[w]);
        pq.push(newNode);
    	}	
    while (pq.size() != 1)
		{
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* node = new Node(left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    	}	
    Node* root = pq.top();
    cout<<printValue(root,  0)<<endl;
}

