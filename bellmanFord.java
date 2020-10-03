// Bellman Ford in Java

class CreateGraph {

  // Graph Creation
  class EdgeCreation {
    int s, d, w;

    EdgeCreation() {
      s = d = w = 0;
    }
  };

  int V, E;
  EdgeCreation edge[];

  // Creates a graph with V vertices and E edges
  CreateGraph(int v, int e) {
    V = v;
    E = e;
    edge = new EdgeCreation[e];
    for (int i = 0; i < e; ++i)
      edge[i] = new EdgeCreation();
  }

  void BellmanFord(CreateGraph graph, int s) {
    int V = graph.V, E = graph.E;
    int dist[] = new int[V];

    // Step 1: fill the dist and predecessor array
    for (int i = 0; i < V; ++i)
      dist[i] = Integer.MAX_VALUE;

    // Mark the source vertex
    dist[s] = 0;

    // Step 2: relax edges |V| - 1 times
    for (int i = 1; i < V; ++i) {
      for (int j = 0; j < E; ++j) {
        // Get the edge data
        int u = graph.edge[j].s;
        int v = graph.edge[j].d;
        int w = graph.edge[j].w;
        if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v])
          dist[v] = dist[u] + w;
      }
    }

    // Step 3: detect negative cycle
    // if value changes then we have a negative cycle in the graph
    // and we cannot find the shortest distances
    for (int j = 0; j < E; ++j) {
      int u = graph.edge[j].s;
      int v = graph.edge[j].d;
      int w = graph.edge[j].w;
      if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
        System.out.println("CreateGraph contains negative cycle");
        return;
      }
    }

    // No negative cycle
    // Print the distance and predecessor array
    printSolution(dist, V);
  }

  // Print the solution
  void printSolution(int dist[], int V) {
    System.out.println("Vertex Distance from Source");
    for (int i = 0; i < V; ++i)
      System.out.println(i + "\t\t" + dist[i]);
  }

  public static void main(String[] args) {
    int V = 5; // Total vertices
    int E = 8; // Total Edges

    CreateGraph graph = new CreateGraph(V, E);

    
    graph.edge[0].s = 0;
    graph.edge[0].d = 2;
    graph.edge[0].w = 2;

    
    graph.edge[1].s = 0;
    graph.edge[1].d = 1;
    graph.edge[1].w = 5;

    
    graph.edge[2].s = 2;
    graph.edge[2].d = 6;
    graph.edge[2].w = 2;

    
    graph.edge[3].s = 8;
    graph.edge[3].d = 4;
    graph.edge[3].w = 9;

   
    graph.edge[4].s = 	;
    graph.edge[4].d = 9;
    graph.edge[4].w = 1;

    graph.BellmanFord(graph, 0);
  }
}