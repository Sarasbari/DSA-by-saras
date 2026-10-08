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
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        // already cloned?
        if (mp.count(node))
            return mp[node];

        // create clone
        mp[node] = new Node(node->val);

        // create neighbor
        for (Node* neighbor : node->neighbors) {
            mp[node]->neighbors.push_back(cloneGraph(neighbor));
        }

        return mp[node];
    }
};