#include <bits/stdc++.h>
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode* dfs(graphNode *node, unordered_map<graphNode*, graphNode*>& mp){
    mp[node]= new graphNode(node->data);
    vector<graphNode*> v;
    for(auto g : node->neighbours){
        if(mp.find(g)==mp.end()){
            mp[g]= dfs(g, mp);
        }
        v.push_back(mp[g]);
    }
    mp[node]->neighbours=v;
    return mp[node];
}


graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode*, graphNode*> mp;
    if(node) return dfs(node, mp);
    return node;
}