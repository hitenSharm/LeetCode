
class Solution {
public:
    unordered_map<Node*,Node*>o2n;
    
    Node* cloning(Node* old)
    {
        if(!old)return old;
        Node* res=new Node(old->val);
        o2n[old]=res;
        for(auto i:old->neighbors)
        {
            if(o2n.find(i)!=o2n.end())
            {
               res->neighbors.push_back(o2n[i]);
            }
            else
                res->neighbors.push_back(cloning(i));
        }
        return res;
    }
    
    Node* cloneGraph(Node* node) {
        return cloning(node);
    }
};