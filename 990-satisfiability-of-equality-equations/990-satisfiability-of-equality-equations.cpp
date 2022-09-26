class Solution {
public:

    vector<int>parent;
    vector<int>siz;
    int findParent(int node)
    {
        if (node == parent[node])
            return node;//head node

        return parent[node] = findParent(parent[node]);
    }
    void dsu(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);

        if (siz[a] > siz[b]) //attach to larger tree and b is larger at all times
            swap(a, b);

        parent[a] = b;
        siz[b] += siz[a];
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        siz.resize(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        //satisfy all equal conditions in dsu and then verify each notequal cases with dsu find
        for (auto i : equations)
        {
            if (i[1] == '=' and i[2] == '=')
            {
                dsu(i[0] - 'a', i[3] - 'a');
            }
        }
        for (auto i : equations)
        {
            if (i[1] == '!' and i[2] == '=')
            {
                if (findParent(i[0] - 'a') == findParent(i[3] - 'a'))return false;
            }
        }
        return true;
    }
};