# ACM-ICPC Repository

This repository contains C++ implementations of various graph algorithms and string algorithms, commonly used in competitive programming and ACM-ICPC contests.

## Graph Algorithms

The following graph algorithms are included in this repository:

- **2SAT Algorithm** (`2SAT.cpp`): Solves the 2-satisfiability problem.
- **2nd Best MST** (`2nd best MST.cpp`): Finds the second-best minimum spanning tree.
- **Articulation Point** (`Articular point O(n+m).cpp`): Finds articulation points in a graph in O(n+m) time.
- **Bellman-Ford Algorithm**:
  - **Single Source Shortest Path** (`Bellman-Ford Algorithm single source shortest path with negative weight edges & Cycle check.cpp`): Handles negative weight edges and checks for negative cycles.
  - **Shortest Path Faster Algorithm (SPFA)** (`Bellman-Ford-Shortest Path Faster Algorithm (SPFA).cpp`): Optimized version of Bellman-Ford.
- **Bipartite Graph Check** (`Bipartite graph check.cpp`): Checks whether a graph is bipartite.
- **Cycle Finding**:
  - **In Directed Graph (O(m))** (`Cycle Finding in O(m) in Directed Graph.cpp`).
  - **In Undirected Graph (O(m))** (`Cycle Finding in O(m) in unDirected Graph.cpp`).
- **Dijkstra's Algorithm** (`Dijkstra Algorithm single-source shortest paths problem.cpp`): Solves the single-source shortest paths problem.
- **Euler Cycle**:
  - **Directed Graph** (`Euler Cycle Directed Graph CSES(Teleporters path).cpp`): Finds Euler cycle in a directed graph.
  - **Undirected Graph** (`Euler Cycle unDirected Graph CSES(Mail Delivery).cpp`): Finds Euler cycle in an undirected graph.
  - **Euler Path (Directed)** (`Euler path directed.cpp`): Finds Euler path in directed graphs.
  - **Euler Path (Undirected)** (`Euler undirected.cpp`): Finds Euler path in undirected graphs.
- **Finding Bridges** (`Finding bridges in a graph in O(n+m).cpp`): Identifies bridges in a graph.
- **Floyd-Warshall Algorithm** (`Floyd-Warshall Algorithm.cpp`): Solves the all-pairs shortest path problem.
- **Graph Traversal**:
  - **BFS** (`Graph traversal BFS.cpp`): Breadth-first search.
  - **DFS** (`Graph traversal DFS.cpp`): Depth-first search.
- **Minimum Spanning Tree (MST)**:
  - **Kruskal's Algorithm** (`Krushkal MST.cpp`).
  - **Prim's Algorithm** (`MST prims set.cpp`).
- **LCA (Lowest Common Ancestor)**:
  - **Binary Lifting** (`LCA Binary lifting.cpp`).
  - **Tarjan's Offline Algorithm** (`LCA Tarjan's off line.cpp`).
  - **Tree Painting** (`LCA Tree painting.cpp`).
  - **FCB Algorithm** (`LCA-FCB.cpp`).
- **Min-Cost Max Flow**:
  - **With Negative Cycles** (`Min Cost Max Flow with Negative Cycles.cpp`).
  - **Standard** (`Min Cost Max Flow.cpp`).
- **RMQ with LCA** (`RMQ LCA.cpp`): Range minimum query using Lowest Common Ancestor.
- **Topological Sort** (`TopoSort.cpp`): Performs topological sorting on a directed acyclic graph (DAG).

## String Algorithms

The repository also contains implementations of essential string algorithms:

- **Hashing and Reverse Hashing** (`Hashing and Reverse Hashing.cpp`): Computes hash values for efficient string matching.
- **KMP Algorithm** (`KMP.cpp`): Knuth-Morris-Pratt pattern matching algorithm.

## Usage

These algorithms are implemented in C++ and are intended to be used for competitive programming purposes, especially in contests like ACM-ICPC. Each file contains a well-optimized version of the corresponding algorithm.

### Compilation and Execution

To compile and run the C++ files:

```bash
g++ filename.cpp -o outputfile
./outputfile
