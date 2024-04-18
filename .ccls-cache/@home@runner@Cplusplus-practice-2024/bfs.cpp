#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, int start){
  int n = graph.size();
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";
    for(int i = 0; i<n; ++i){
      if(graph[node][i] && !visited[i]){
        q.push(i);
        visited[i] = true;
        
      }
      
    }
    
  }
  cout << endl;
}

int main(){
  // hard code the graph
  vector<vector<int>> graph = {{0,1,1,0,0,0},{1,0,0,1,1,0}, {1,0,0,0,0,1}, {0,1,0,0,1,0}, {0,1,0,1,0,1}, {0,0,1,0,1,0}};
  bfs(graph, 0);
  return 0;
    
}