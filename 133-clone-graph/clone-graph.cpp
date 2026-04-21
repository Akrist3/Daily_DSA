/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mpp;
    Node* dfs(Node* node){
        if(mpp.count(node)) return mpp[node];

        Node* clone = new Node(node->val);
        mpp[node]=clone;
        for(auto it : node->neighbors){
            clone->neighbors.push_back(dfs(it));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return dfs(node);
    }
};