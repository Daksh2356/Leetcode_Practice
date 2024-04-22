/*
Question : 1917. Find If Path Exists in Graph
Date : 21-04-24
Problem Difficulty level : Easy
Related Topics : Depth First Search, Breadth First Search, Union Find, Graph 

Problem Statement:

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are 

represented as a 2D integer array 'edges', where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 

Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 
Constraints:
1 <= n <= 2 * 10^5
0 <= edges.length <= 2 * 10^5
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.

*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // create an adjacency list for all vertices
        //it gives us a good representation of give graph with edges and vertices

        vector<vector<int>> adjList(n);

        for(const auto& edge :edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // bi directional edge
        }

        vector<bool>visited(n, false);  // to keep visited status of vertices

        return dfs(adjList, visited, source, destination);

    }

    bool dfs(vector<vector<int>>& adjList, vector<bool>& visited, int curr, int dest){

        if(curr == dest)  // check if current vertex is the destination vertex
            return true;

        visited[curr] = true;  // mark current vertex as visited 

        for(int neighbour : adjList[curr]) // check for neighbouring vertices of current vertex
        {
            if(!visited[neighbour]){  // if the curr neighbour is never visited, explore it
                if(dfs(adjList, visited, neighbour, dest))
                    return true;
            }
        }

        return false;  //if no valid path is found from current vertex, return false

        // time complexity = O(E)
        // space complexity = O( V + E )
        // where E is number of edges and v is number of vertices of graph
    }
};