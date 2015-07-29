#include <map>
#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> result;
        if (!graph.size())
            return result;

        map<DirectedGraphNode*, int> visited;
        for (int i = 0; i < (int)graph.size(); i++) {
            for (int j = 0; j < (int)graph[i]->neighbors.size(); j++) {
                if (visited.find(graph[i]->neighbors[j]) == visited.end())
                    visited[graph[i]->neighbors[j]] = 1;
                else
                    visited[graph[i]->neighbors[j]]++;
            }
        }

        for (int i = 0; i < (int)graph.size(); i++) {
            if (visited.find(graph[i]) == visited.end()) {
                dfs(graph[i], visited, result);
            }
        }

        return result;
    }

private:
    void dfs(
        DirectedGraphNode* node,
        map<DirectedGraphNode*, int>& visited,
        vector<DirectedGraphNode*>& result
    ) {
        result.push_back(node);
        visited[node]--;
        
        for (int i = 0; i < (int)node->neighbors.size(); i++) {
            visited[node->neighbors[i]]--;
            if (visited[node->neighbors[i]] == 0)
                dfs(node->neighbors[i], visited, result);
        }
    }

};
