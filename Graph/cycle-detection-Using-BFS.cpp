#include<bits/stdc++.h>
using namespace std;

bool isContainsCycleBFS(int curr, int parent, vector<bool> &visited, vector<int> graph[]) {

  // for bfs traversal what we need to do is
  // make use of queue and you will ready to go

  queue<pair<int, int>> q;

  // put the current node in graph and mark it as visited
  q.push({curr, parent});
  visited[curr] = true;

  while(!q.empty()) {

    pair<int, int> currNodeRef = q.front();
    q.pop();

    int currNode = currNodeRef.first;
    int currNodeParent = currNodeRef.second;

    for(int x : graph[currNode]) {
      if(visited[x] == false) {

        visited[x] = true;
        q.push({x, currNode});
        // if not visited visit it first
        // and push into the queue
      } else if (x != currNodeParent) {
        // if already visited
        // so check if visited by current parent or some others
        //  node , if some other node return true as there is
        // cycle in the graph
        return true;
      }
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
       if (isContainsCycleBFS(i, -1, visited, graph))
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
