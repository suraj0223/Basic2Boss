#include<bits/stdc++.h>
using namespace std;

bool isContainsCycleDFS(int curr, int parent, vector<bool> &visited, vector<int> graph[]) {

  // mark the current element visited
  visited[curr] = true;

  // for neighbour in graph[currentElement]
  for(int neighbour : graph[curr]) {
    if(visited[neighbour] == false) {
      // i.e neighbour of current parent is not visited
        if(isContainsCycleDFS(neighbour, curr, visited, graph))
          return true;
    } else if (neighbour != parent){
      // if neighbour of cuurent parent is already visited
      // so check the parent of neighbour is current's parent or someone else
      // if someone else then there is a cycle
      return true;
    }
  }
  return false;
}

bool isCycle(int vertex,  vector<int> graph[]) {
  // declared a visited array
  vector<bool> visited(vertex, false);

  for(int i = 0; i < vertex; i++) {
    if(!visited[i]) {
      // if not visited current element
      // call the dfs call here
      // -1 because its parent of any node
       if (isContainsCycleDFS(i, -1, visited, graph))
          return true;
    }
  }
  return false;
}

int main() {
  // code to detect cycle in the graph
  // 1. usign dfs traversal

  int v, e;
  // vertices and edges

  cin >> v >> e;

  // make a graph
  vector<int> graph[v];
  // its a array of vector
  // you can also use vector<vector<int>>

  for(int i = 0; i < e; i++) {
    // total edges
    // input in the form of u, v
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    // if graph is directed

    /*
    if graph is not directed then used a
    graph[v].push_back(u);
    */
  }

  bool _isCycle = isCycle(v, graph);
  cout << (_isCycle ? "True" : "False");

  return 0;
}
