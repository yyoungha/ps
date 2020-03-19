# The Bellman-Ford Algorithm

***Bellman-Ford 알고리즘*** 은 negative weight edge를 가질 수 있는 그래프의 Single-source Shortest-paths 문제를 해결하는 방법이다.  

 ## relaxation
 이 알고리즘은 ***relaxation***이라는 기술을 사용한다. 여기서는 각 정점 v ∈ V 에 대하여 source s에서 v로 가는 shortest path가 갖는 weight 값의 upper bound를 나타내는 v.d 값을 기록해둔다. 이 v.d 값을 ***shortest-path estimate***라고 한다. 또한 정점 v의 predecessor 값을 나타내기 위해 v.π를 사용한다. 이들의 초기화는 다음 코드로 Θ(V) 시간 내에 수행이 가능하다.

```c
INITIALIZE-SINGLE-SOURCE(G, s)
1   for each vertex v ∈ G.V
2       v.d = ∞
3       v.π = NULL
4   s.d = 0
```

간선 (u, v)를 ***relaxing*** 하는 과정은 v로 가는 shortest path 값을 더 줄일 수 있는지를 검사하면서, 만약 더 줄일 수 있으면 v.d 와 v.π 를 갱신한다. 아래 코드는 O(1) 시간에 간선 (u, v)에 relaxation을 수행한다.

```c
RELAX(u, v, w)
1   if v.d > u.d + w(u, v)
2       v.d = u.d + w(u, v)
3       v.π = u
```

Dijkstra's algorithm은 directeds acyclic graph의 각 간선당 정확히 1번 relax를 수행한다. Bellman-Ford algorithm은 각 간선에 (|V| - 1)회만큼 relax를 수행한다.

## Bellman-Ford 
1) Weighted directed graph *G = (V, E)* 
2) Source s 
3) weight function w : E → R

 위 세가지 입력이 주어졌을 때, Bellman-Ford 알고리즘은 source에서 도달가능한 negtaive-weight cycle이 존재하는지에 대한 boolean 값을 반환한다. 이런 cycle이 존재하지 않는다면, 이 알고리즘은 Shortest-paths와 그 weight를 나타낸다.

```c
BELLMAN-FORD(G, w, s)
1   INITIALIZE_SINGLE_SOURCE(G, s)
2   for i = 1 to |G.V| - 1
3       for each edge (u, v) ∈ G.E
4           relax(u, v, w)
5   for each edge (u, v) ∈ G.E
6       if v.d > u.d + w(u, v)
7           return false;
8   return true;
```

Bellman-Ford 알고리즘은 계속해서 edge를 relax 하면서 source s에서 각 정점 v ∈ V 에 대한 shortest paths의 weight 추정치 v.d 값을 감소시켜 나가면서 실제 값을 찾는다.  

Bellman-Ford 알고리즘의 시간복잡도는 O(VE)이다. 

# Single-source shortest paths in directed acyclic graphs

 weighted DAG(directed acyclic graph) G = (V, E)의 각 정점을 위상정렬한 뒤, 그 순서에 따라 간선을 relax 하여 single source s에서의 shortest paths를 O(V+E) 시간에 계산할 수 있다.  

 알고리즘은 먼저 정점들의 선형 순서를 찾기 위해 위상 정렬을 하는 것에서부터 시작한다. 간선 (u, v)가 DAG G에 포함되어 있다면, u가 v에 선행하게 된다. 위상 정렬된 순서대로 각 정점에 대해 하나의 pass를 만든 뒤, 각 정점을 처리하면서 해당 정점에서 출발하는 간선에 relax를 수행한다.  
 ```c
 DAG-SHORTEST-PATHS(G, w, s)
 1  topologically sort the vertices of G
 2  INITIALIZE-SINGLE-SOURCE(G, s)
 3  for each vertex u, taken in topologically sorted order
 4      for each vertex v ∈ G.Adj[u]
 5           RELAX(u, v, w)
 ```


