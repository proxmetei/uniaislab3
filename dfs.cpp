#include <iostream>
#include <list>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
    int globcount;
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex, int fin, int count);
};
 
// Инициализация графа
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
    globcount =0;
}
 
// Добавление ребер
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}
 
// Алгоритм
void Graph::DFS(int vertex, int fin, int count=0) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];
 
  cout << vertex << " ";
 
  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
      if (!visited[*i]){
      count++;
          if(*i == fin){
              globcount = count;
          }
      DFS(*i,fin,count);
      }
}
 
int main() {
  Graph g(4);
  g.addEdge(0, 2);
  g.addEdge(3, 1);
  g.addEdge(1, 3);
    int s,f;
    cout<<"Insert s and f"<<endl;
    cin>> s>>f;
  g.DFS(s,f);
    cout <<endl<<"Длина равна: "<<g.globcount<<endl;
  return 0;
}
