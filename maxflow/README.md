# Maxflow 

## Flow network 와 flow
**Flow network** *G = (V, E)* 는 각 간선 *(u, v)* ∈ *E* 이 음이 아닌 용량 *c(u, v)* ≥ 0 을 갖는 방향그래프이다. 또한 간선 *(u, v)* ∈ *E* 라면 반대 방향의 간선 *(v, u)* 는 존재하지 않는다고 가정한다. 편의상 간선 *(u, v)* ∉ *E* 에 대해 그 용량을 *c(u, v)* = 0 으로 정의하며, flow network에서는 자기 간선을 허용하지 않는다.  

Flow network는 특별한 두 정점 **source** s와 **sink** t을 갖는다. flow network에 포함된 각 정점은 source에서 sink로 가는 경로에 포함된다고 가정한다. 즉, 각 정점 v ∈ *V* 에 대하여 flow network는 s → v → t 인 경로를 포함한다. 그러므로 그래프는 연결되어 있고(connected), 시작 정점 s를 제외한 모든 정점은 최소 하나의 진입 간선을 갖는다. 즉 |*E*| ≥ |*V*| - 1 이다.

 이제 flow를 정의해보자. *G = (V, E)* 가 용량 함수 c를 가지는 flow network라고 하자. 이 flow network의 source를 s, sink를 t라고 하자. 그래프 *G*의 **flow**는 다음 두 조건을 만족하는 실숫값 함수 ƒ : V × V → R을 말한다.  

 **Capacity constraint:** 모든 정점 *u, v* ∈ *V* 에 대하여  
 <p align="center">
<img src="https://latex.codecogs.com/png.latex?0&space;\leq&space;f(u,&space;v)&space;\leq&space;c(u,&space;v)" title="0 \leq f(u, v) \leq c(u, v)" />
 </p>

 **Flow conservation:** 모든 정점 *u* ∈ *V* - {*s, t*} 에 대하여  

<p align="center">
<img src="https://latex.codecogs.com/png.latex?\sum_{v&space;\in&space;V}^{&space;}f(v,u)&space;=&space;\sum_{v&space;\in&space;V}^{&space;}f(u,v)" title="\sum_{v \in V}^{ }f(v,u) = \sum_{v \in V}^{ }f(u,v)" />
</p>

* 여기서 만약 (*u, v*) ∉ *E* 이면 ƒ(*u, v*) = 0이다.  

우리는 이러한 ƒ(*u, v*)를 정점 *u*에서 *v*로 가는 flow라고 한다. flow ƒ의 **value** |ƒ|는 다음과 같이 정의된다.

<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=\left&space;|&space;f&space;\right&space;|&space;=&space;\sum_{v\in&space;V}^{&space;}f(s,v)-\sum_{v\in&space;V}^{&space;}f(v,s)" target="_blank"><img src="https://latex.codecogs.com/png.latex?\left&space;|&space;f&space;\right&space;|&space;=&space;\sum_{v\in&space;V}^{&space;}f(s,v)-\sum_{v\in&space;V}^{&space;}f(v,s)" title="\left | f \right | = \sum_{v\in V}^{ }f(s,v)-\sum_{v\in V}^{ }f(v,s)" /></a>
</p>

즉, source로부터 나온 총 flow에서 source로 가는 flow를 뺀 값이다. 일반적으로 flow network에서는 source로 향하는 간선이 존재하지 않으므로 - 뒤의 값은 0이 된다.  

간단히 두가지 flow의 속성에 대해 되짚어보자. Capacity constraint는 한 정점에서 다른 정점으로의 flow는 반드시 음이 아닌 수이며 주어진 용량을 초과해서는 안된다. Flow conversion 특성은 source나 sink를 제외한 한 정점으로 들어오는 flow 합은 그 정점에서 나가는 flow 합과 같아야 한다. 간단히 말해, flow in equals flow out.

#### antiparallel 간선을 포함한 문제 모델링
우리는 flow network의 정의에서 간선 *(u, v)* ∈ *E* 라면 반대 방향의 간선 *(v, u)* 는 존재하지 않는다고 했다. 우리는 두 간선 *(u, v)*와 *(v, u)*를 반평행(antiparallel)이라고 한다. 즉 우리가 이러한 간선을 가진 문제를 flow network로 모델링하기 위해서는 이와 동치의 반평행 간선이 없는 네트워크로 변환시켜야 한다.  

변환 방법으로는 문제를 발생시킨 반평행 간선 중 하나 *(v, u)* 를 골라 하나의 정점을 추가함으로써 이를 두 간선 *(v, w)*, *(w, u)* 로 나누는 것이다. 그 후 이 두 간선의 용량을 기존 간선이었던 (*v, w*)의 용량으로 설정한다. 이렇게 하면 우리는 반평행 간선이 없는 네트워크를 얻을 수 있다.

#### 만약 Source와 Sink가 여러개라면?
Maxflow 문제에서 source와 sink 는 여러개가 될 수 있다. 우리는 이 문제를 두개의 정점 supersource와 supersink 및 간선을 추가하여 간단히 축소시킬 수 있다. 여러개의 source s<sub>i</sub>에 대해 supersource s에서 시작하는 간선 (s, s<sub>i</sub>) 을 추가하고 용량을 무한대로 설정한다. 마찬가지로 sink에 대해서도 supersink t에 대해 t로 향하는 간선 (t<sub>i</sub>, t) 을 추가하고 용량을 무한대로 설정한다. 

# Ford-Fulkerson method
Algorithm이 아니라 Method라고 부르는데에는 이유가 있다. 몇가지 구현 방법에 따라 실행 시간이 달라지는 여러가지 방법을 포함하고 있기 때문이다. Ford-Fulkerson method는 다른 flow algorithm과 구분되는 세가지 아이디어가 핵심이 된다.

1. Residual networks
2. Augmenting paths
3. Cuts  

Fork-Fulkerson method는 flow의 value를 반복해서 증가시킨다. 처음에는 모든 *u, v* ∈ *V* 에 대하여 ƒ(*u, v*) = 0, 즉 그래프 G의 flow value를 0으로 두고 시작한다. 매 반복마다 "residual network" G<sub>ƒ</sub>에서 "augmenting path"를 찾음으로써 G의 flow value를 증가시킨다. G<sub>ƒ</sub>의 augmenting path의 간선들을 알고 있으면, 우리는 쉽게 G의 특정한 간선을 식별하여 flow를 바꿀 수 있다.

## Residual Network
Residual network G<sub>ƒ</sub> 는 G의 간선의 flow를 어떻게 바꿀지를 나타내는 용량을 갖는 간선으로 구성되어 있다. flow network의 모든 간선은 (해당 간선의 용량) - (해당 간선의 flow) 만큼의 추가적인 flow를 허용할 수 있다. 만약 이 값이 양수이면 해당 간선을 G<sub>ƒ</sub>에 추가한다. 이 간선의 용량을 residual capacity(c<sub>ƒ</sub>)라 하고, 그 값은 c<sub>ƒ</sub>(*u, v*) = c(*u, v*) - ƒ(*u, v*) 이다. flow network G의 간선 중에서 추가 flow를 허용하는 간선은 오직 G<sub>ƒ</sub>에 포함된 간선 뿐이다. flow가 용량과 같은 간선은 c<sub>ƒ</sub>(*u, v*) = 0 이므로 G<sub>ƒ</sub>에 포함되지 않는다.  

 Residual network G<sub>ƒ</sub>에는 G에는 없는 간선이 포함될 수 있다. 알고리즘이 total flow를 증가시키는 방향으로 flow를 조정하면서, 특정 간선의 flow를 감소시킬 필요가 있는 경우가 발생하기 때문이다. flow network G에서 감소 가능한 positive flow ƒ(*u, v*)를 나타내기 위해, residual network G<sub>ƒ</sub>에 반대 방향의 간선 (*v, u*)를 추가하고 그 용량을 c<sub>ƒ</sub>(*v, u*) = ƒ(*u, v*) 로 둔다. 즉, 간선이 (*u, v*)의 반대 방향 flow를 허용하도록 만들어서, 최대 (*u, v*)의 flow를 모두 상쇄할 수 있도록 한다. 이러한 residual network의 반대방향 간선은 알고리즘이 간선을 따라 흐르는 flow를 반대방향으로 되돌려 보낼 수 있게 한다. flow를 되돌려보내는 것은 해당 간선의 flow를 감소시키는 것과 동일하다.  

**residual capacity** 를 정의하면 다음과 같다.  
<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=c_{f}=\begin{Bmatrix}&space;c(u,v)&space;-&space;f(u,v)&space;&&space;if&space;(u,v)&space;\in&space;E\\&space;f(v,u)&space;&&space;if&space;(u,v)&space;\in&space;E\\&space;0&space;&&space;otherwise&space;\end{Bmatrix}" target="_blank"><img src="https://latex.codecogs.com/png.latex?c_{f}=\begin{Bmatrix}&space;c(u,v)&space;-&space;f(u,v)&space;&&space;if&space;(u,v)&space;\in&space;E\\&space;f(v,u)&space;&&space;if&space;(u,v)&space;\in&space;E\\&space;0&space;&&space;otherwise&space;\end{Bmatrix}" title="c_{f}=\begin{Bmatrix} c(u,v) - f(u,v) & if (u,v) \in E\\ f(v,u) & if (u,v) \in E\\ 0 & otherwise \end{Bmatrix}" /></a>
</p>

Flow network G의 간선에 대해 *(u, v)* ∈ *E* 라면 반대 방향의 간선 *(v, u)* 는 존재하지 않는다고 가정했으므로, 각 정점의 순서쌍 *(v, u)*에 대해 위 3가지 경우 중 정확히 하나에만 대응된다. 

이제 **residual network**를 정의해보자.
flow network G = (*V, E*)와 그 flow ƒ가 주어졌을 때, G의 residual network induced by ƒ, G<sub>ƒ</sub> 는 다음과 같다.
<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=G_{f}=(V,&space;E_{f}),&space;E_{f}&space;=&space;\begin{Bmatrix}&space;(u,&space;v)&space;\in&space;V&space;\times&space;V&space;:&space;c_{f}(u,&space;v)&space;>&space;0&space;\end{Bmatrix}" target="_blank"><img src="https://latex.codecogs.com/png.latex?G_{f}=(V,&space;E_{f}),&space;E_{f}&space;=&space;\begin{Bmatrix}&space;(u,&space;v)&space;\in&space;V&space;\times&space;V&space;:&space;c_{f}(u,&space;v)&space;>&space;0&space;\end{Bmatrix}" title="G_{f}=(V, E_{f}), E_{f} = \begin{Bmatrix} (u, v) \in V \times V : c_{f}(u, v) > 0 \end{Bmatrix}" /></a>
</p>

위에서 정의한 것 처럼, residual network의 각 간선 **residual edge** 는 0보다 큰 flow만 허용할 수 있다. residual network의 간선은 flow network G의 반대방향 간선도 가질 수 있으므로  
<p align="center">
|E<sub>ƒ</sub>| ≤ 2|E| 
</p>

Residual network의 flow는 우리에게 원본 flow network에서 어떤 flow를 추가할지에 대한 로드맵을 제공해준다. 만약 ƒ가 G의 flow이고 ƒ'이 대응하는 G<sub>ƒ</sub>의 flow라면 ƒ↑ƒ'를 flow의  **augmentation**이라 하고 다음을 만족하는 함수 V × V → R 를 말한다. 

<p align="center">
(ƒ↑ƒ')(<i>u,v</i>) = ƒ(<i>u,v</i>) + ƒ'(<i>u,v</i>) - ƒ'(<i>v,u</i>) if (<i>u,v</i>) ∈ E, 0 otherwise
</p>

이러한 정의를 이해하기 위해 residual network의 정의를 생각해보자. 우리는 간선 (*u, v*)의 flow를 ƒ'(*u,v*)만큼 증가시키고 ƒ'(*v,u*)만큼 감소시켰다. 왜냐하면 residual network에서 반대방향으로 flow를 흘려보내는 것은 original network에서의 flow 감소를 나타내기 때문이다. 이렇게 residual network에서 반대방향으로 flow를 흘려보내는 것을 **cancellation** 이라고 한다.

### Augmenting paths
Flow network G = (*V, E*)와 flow ƒ가 주어졌을 때, **augmenting path** p는 residual network G<sub>ƒ</sub>의 s에서 t로가는 단순 경로(simple path)이다. residual network의 정의에 의해 우리는 capacity constraint를 준수하면서 augmenting path의 한 간선 (*u, v*)의 flow를 최대 c<sub>ƒ</sub>(*u, v*) 까지 증가시킬 수 있다.

augmenting path p에서 우리가 증가시킬 수 있는 flow의 최대 용량을 p의 **residual capacity**라고 하며, 다음과 같이 표시할 수 있다.
<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=c_{f}(p)&space;=&space;min(c_{f}(u,&space;v)&space;:&space;(u,&space;v)\,is\,on\,p)" target="_blank"><img src="https://latex.codecogs.com/png.latex?c_{f}(p)&space;=&space;min(c_{f}(u,&space;v)&space;:&space;(u,&space;v)\,is\,on\,p)" title="c_{f}(p) = min(c_{f}(u, v) : (u, v)\,is\,on\,p)" /></a>
</p>

### Cuts of flow networks
Ford-Fulkerson method는 maximum flow를 찾을 때까지 반복해서 augmenting path를 따라 flow를 증가시킨다. maximum flow를 찾았다는 것을 어떻게 알 수 있을까? max-flow min-cut theorem에 의하면 residual network가 더이상 augmenting path를 가지지 않을 때 flow가 maximum이라고 한다. 이를 살펴보기에 앞서, 먼저 flow network에서 cut이 무엇인지에 대해 알아보자.  

Flow network G = (*V, E*)의 **cut** (*S, T*)은  *s* ∈ *S* 이고 *t* ∈ *T* 를 만족하는 *V*의 분할 *S*와 *T*(*T* = *V* - *S*)를 말한다. 만약 ƒ가 flow라면 **net flow** ƒ(*S, T*) across the cut(*S, T*)는 다음과 같이 정의된다.
<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=f(S,&space;T)&space;=&space;\sum_{u\in&space;S}^{&space;}\sum_{v\in&space;T}^{&space;}f(u,v)&space;-&space;\sum_{u\in&space;S}^{&space;}\sum_{v\in&space;T}^{&space;}f(v,u)" target="_blank"><img src="https://latex.codecogs.com/png.latex?f(S,&space;T)&space;=&space;\sum_{u\in&space;S}^{&space;}\sum_{v\in&space;T}^{&space;}f(u,v)&space;-&space;\sum_{u\in&space;S}^{&space;}\sum_{v\in&space;T}^{&space;}f(v,u)" title="f(S, T) = \sum_{u\in S}^{ }\sum_{v\in T}^{ }f(u,v) - \sum_{u\in S}^{ }\sum_{v\in T}^{ }f(v,u)" /></a>
</p>

그리고 cut(*S, T*)의 **capacity**는 다음과 같다.
<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=c(S,&space;T)&space;=&space;\sum_{u\in&space;S}^{&space;}\sum_{v\in&space;T}^{&space;}c(u,v)" target="_blank"><img src="https://latex.codecogs.com/png.latex?c(S,&space;T)&space;=&space;\sum_{u\in&space;S}^{&space;}\sum_{v\in&space;T}^{&space;}c(u,v)" title="c(S, T) = \sum_{u\in S}^{ }\sum_{v\in T}^{ }c(u,v)" /></a>
</p>

주어진 network의 **minimum cut**이란 network의 모든 cut 중에서 capacity가 가장 작은 cut을 말한다.  

여기서 cut의 flow와 capacity의 정의가 약간 다름에 주목할 필요가 있다. capacity에서는 *S*에서 *T*로 가는 모든 간선을 포함하되, 반대방향 간선은 무시한다. 하지만 flow에서는 *S*에서 *T*로 가는 모든 flow의 합에서 반대방향으로 가는 모든 flow의 합을 빼야 한다. 

여기서 몇가지 정리를 소개한다.
- Lemma: flow network G의 flow를 ƒ라 하자. (*S, T*)를 G의 cut 중 하나라고 하면, ƒ(*S, T*) = |ƒ| 이다. 즉 어떤 cut의 net flow 값은 flow의 value와 같다. 증명은 |ƒ|의 정의와 flow conservation 식을 이용한다.
- Corollary: flow network G에서 어떤 flow ƒ의 value는 G의 어떤 cut의 capacity를 upper bound로 가진다. 증명은 위 Lemma와 capacity constraint 식으로 가능하다.  

위 corollary는 G의 모든 cut에 대해 만족한다. 즉, maximum flow의 value 상한이 minimum cut의 capacity임을 알려준다. 
- Theorem: Max-flow min-cut theorem  
만약 ƒ가 flow network G = (*V, E*)의 flow라면, 다음 세가지 조건은 동등하다.
  - ƒ 는 G의 maximum flow이다.
  - Residual network G<sub>ƒ</sub>는 augmenting path를 가지지 않는다.
  - G의 cut (*S, T*)에 대하여 |ƒ| = c(*S, T*)

## Ford-Fulkerson algorithm
Ford-Fulkerson method에서 매번 반복할 때 마다 flow ƒ를 조정하기 위해 *몇가지* augmenting path p를 찾는다. ƒ를 (ƒ↑ƒ<sub>p</sub>)로 대체하여, 새로운 flow 값 |ƒ|+|ƒ<sub>p</sub>|을 얻는다.  Ford-Fulkerson method의 의사코드는 아래와 같다. 이 알고리즘은 주어진 flow network G의 maximum flow를 계산한다. 

````
FORD-FULKERSON(G = (V, E), s, t)
1  for each edge (u, v) ∈ E
2    (u, v).ƒ = 0
3  while(∃ a path p from s to t in residual network)
4    cƒ(p) = min(cƒ(u, v) : (u, v) is in p)
5    for each edge (u, v) in p
6      if( (u, v) ∈ E )
7        (u, v).ƒ = (u, v).ƒ + cƒ(p)
8      else 
9        (u, v).ƒ = (u, v).ƒ - cƒ(p)
````

### Ford-Fulkerson algorithm 분석
Ford-Fulkerson 알고리즘의 실행 시간은 `line 3`에서 augmenting path p를 어떻게 찾느냐에 따라 달라진다. 이 경로를 잘못 고른다면 알고리즘은 무한 루프에 빠질 수도 있다. 만약 우리가 BFS를 이용하여 augmenting path를 찾는다면, 알고리즘은 Polynomial 시간 내에 끝난다.

# Reference
- <a href="https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844"> Introduction to Algorithm </a>