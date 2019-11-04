# Dynamic Programming

분할 정복(divide-and-conquer) 방법과 마찬가지로 ***Dynamic programming*** 역시 문제를 그보다 작은 부분 문제의 해결방안을 결합하는 방식으로 푸는 방법이다. 그러나 분할 정복법이 문제를 중복되지 않는(disjoint) 부분 문제로 나누는 것과 달리, Dynamic programming은 부분 문제가 중첩(overlap)될 때 적용한다. 중첩된 부분 문제를 계속 다시 계산하지 않고, 그 결과를 테이블에 저장하여 다시 참조한다.  

Dynamic programming은 주로 최적화 문제(optimization problem)를 해결하는데 쓰인다. 이런 문제에서는 문제가 여러가지 해결책을 가지며, 각 해결책은 특정한 값을 갖는다. 이 해결책 중에서 최적의 값(최대 혹은 최소)을 찾아내는 문제를 최적화 문제라고 하며, 그러한 값을 최적의 해(***optimal solution***)라 한다.

Dynamic programming 알고리즘을 사용할 때, 다음과 같은 단계를 거친다. 만약 optimal solution의 값만 필요하다면 마지막 단계는 생략할 수 있다.  

1. Optimal solution의 구조가 갖는 특징을 찾는다.
2. Optimal solution의 값을을 재귀적으로 정의한다.
3. (주로 bottom-up 방식으로) Optimal solution을 계산한다.
4. (Optional) 계산된 정보를 바탕으로 Optimal solution의 구조를 찾아낸다.

## 예제) 막대 자르기
막대의 총 길이 n과 막대의 길이별 가격 p<sub>i</sub>가 주어졌을 때, 막대를 어떻게 자르는 것이 가격을 최대로 할 수 있는지를 찾는 문제이다. 막대를 자르지 않은 가격이 최대일 수도 있으며, 막대를 자르는데에는 비용이 들지 않는다고 가정한다.  
만약 optimal solution으로 자르고 난 후의 각 막대 길이를 i<sub>k</sub>라고 할 때, *n = i<sub>1</sub> + i<sub>2</sub> + ... + i<sub>k</sub> ( 1 ≤ k ≤ n )* 이고, 각 막대의 가격의 합 *r<sub>n</sub> = p<sub>i<sub>1</sub></sub> + p<sub>i<sub>2</sub></sub> + ... + p<sub>i<sub>k</sub></sub>* 은 최대가 된다. 

| length i            | 1 | 2 | 3 | 4 | 5  | 6  | 7  | 8  | 9  | 10 |
|---------------------|---|---|---|---|----|----|----|----|----|----|
| price p<sub>i</sub> | 1 | 5 | 8 | 9 | 10 | 17 | 17 | 20 | 24 | 30 |

예를 들어 길이당 비용이 위 표와 같을 때, 길이가 4인 막대는 길이가 (4), (1, 3), (2, 2)인 막대로 자를 수 있고, 이 중에서 (2, 2)로 자를 때 가격이 10인 최대값을 갖는다. 길이 n이 주어졌을 때, 자를 수 있는 경우의 수는 모두 2<sup>n-1</sup>이다. n이 1에서 10까지 변화할 때, 최대 이익 r<sub>n</sub>은 다음과 같다.  

>r<sub>1</sub> = 1, 길이 1 (자르지 않음)  
>r<sub>2</sub> = 5, 길이 2 (자르지 않음)  
>r<sub>3</sub> = 8, 길이 3 (자르지 않음)   
>r<sub>4</sub> = 10, 길이 4 = 2 + 2  
>r<sub>5</sub> = 13, 길이 5 = 2 + 3  
>r<sub>6</sub> = 17, 길이 6 (자르지 않음)    
>r<sub>7</sub> = 18, 길이 7 = 1 + 6 or 2 + 2 + 3  
>r<sub>8</sub> = 22, 길이 8 = 2 + 6  
>r<sub>9</sub> = 25, 길이 9 = 3 + 6  
>r<sub>10</sub> = 30, 길이 10 = 10 (자르지 않음)

위 결과를 일반화하여, 최대 이익 r<sub>n</sub>을 다음과 같이 정의할 수 있다.
<p align="center">
r<sub>n</sub> = max(p<sub>n</sub>, r<sub>1</sub> + r<sub>n-1</sub>, r<sub>2</sub> + r<sub>n-2</sub>, ... , r<sub>n-1</sub> + r<sub>1</sub>)
</p>
여기서 p<sub>n</sub>은 길이가 n인 막대를 자르지 않고 그대로 갖고 있을 때의 가격을 말한다. 다른 n - 1개의 식은 막대를 길이 i와 n - i로 잘랐을 때의 최대 이익에 대응한다. 각 막대 r<sub>i</sub>와 r<sub>n-i</sub>를 계속  

어떤 i가 이익을 최대로 할지 아직 모르기 때문에, 모든 경우의 수를 다 살펴보아야 한다. 길이가 n일때의 최적 해를 알기 위해, 같은 문제이지만 그보다 길이가 작은 두 경우(i, n - i)의 최적 해를 알아야 한다. 이처럼 문제의 optimal solution이 그와 연관된 subproblem의 optimal solution을 포함하고 있는 경우, 이러한 문제를 최적의 부분 구조(***optimal substructure***)를 가지고 있다고 한다.

문제를 더 간단히 해보자. 막대를 길이 i와 n - i로 잘랐을 때, 길이 i인 부분은 자르지 않고 길이 n - i인 부분만 계속 자른다면, 다음과 같이 간단한 식으로 모든 경우의 수를 다 따져볼 수 있다.
<p align="center">
r<sub>n</sub> = max<sub>1 ≤ i ≤ n</sub> (p<sub>i</sub>, r<sub>n-i</sub>)
</p>

### Top-down 재귀 알고리즘
바로 위 식을 재귀적 방법으로 구현하면 다음과 같다
```cpp
int CUT_ROD(int *p, int n)
{
    if (n == 0) return 0;
    q = -INT_INF;
    for (int i = 1; i <= n; i++)
        q = max(q, p[i] + CUT_ROD(p, n - i));
    return q;
}
```
이제 문제를 해결했다 생각하고 신나게 코드를 돌린다면, 뭔가 이상할 것이다. n이 조금만 커지더라도 프로그램이 끝나기까지 너무나 오랜 시간이 걸린다. 느린 실행속도의 이유는 무엇일까?  
문제는 같은 함수를 같은 매개변수로 계속해서 반복 호출함에 있다. 즉, 중복된 부분 문제를 이미 해결했음에도 불구하고 또 다시 계산을 하는 것이다. T(n) 이 입력값 n에 대한 CUT_ROD 함수의 호출 횟수라고 할 때, 다음과 같은 식이 성립한다.
<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=T(n)&space;=&space;1&space;&plus;&space;\sum_{j&space;=&space;0}^{n-1}T(j)" target="_blank"><img src="https://latex.codecogs.com/png.latex?T(n)&space;=&space;1&space;&plus;&space;\sum_{j&space;=&space;0}^{n-1}T(j)" title="T(n) = 1 + \sum_{j = 0}^{n-1}T(j)" /></a>
</p>
이 알고리즘의 시간복잡도는 O(2<sup>n</sup>)이다. 이는 어찌보면 당연한데, recursion tree를 그려보면 자를 수 있는 모든 경우의 수 2<sup>n-1</sup>가지를 전부 다 계산하고 있음을 알 수 있다.

### Dynamic programming 알고리즘
위에서 재귀로 작성한 CUT_ROD 함수를 Dynamic programming을 이용하여 더 효율적으로 개선해보자. 똑같은 부분 문제를 반복해서 푸는것이 문제였으므로, 이를 한번만 풀고 그 결과를 저장해두는 방식으로 해결할 수 있다. 나중에 해당 부분 문제의 답이 필요한 경우 다시 계산하지 않고 저장해 둔 계산결과를 참조한다.  

#### 시간복잡도
 이런 방법은 계산 속도를 향상시키는 대신 계산 결과를 저장해 둘 추가 메모리 공간을 필요로 한다(***time-memory trade-off***). 이렇게 하면 기존의 exponential-time O(2<sup>n</sup>) 으로 풀 수 있던 문제가 polynomial-time O(n<sup>2</sup>) 내에 해결가능하게 된다.

 #### 구현 방식
 Dynamic programming에는 크게 두 가지 구현 방식이 있다. 
 1. ***Top-down with memoization***  
 이 방식은 일반적인 재귀 방식과 유사하지만, 각 부분 문제의 결과를 저장(주로 배열이나 해시테이블에)하는 방식이다. 그러므로 처음에 해당 부분 문제가 이미 해결되었는지 확인해야 한다. 만약 해결되었다면 저장된 결과를 참조하고, 그렇지 않다면 일반적인 방식으로 결과를 계산한다.
 ```cpp
 int MEMOIZED_CUT_ROD_AUX(int *p, int n, int* r)
 {
    if (r[n] >= 0) return r[n];
    if (n == 0)
        q = 0;
    else if (q == -INT_INF)
        for (int i = 1; i <= n; i++)
            q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n - i, r));
    r[n] = q;
    return q;
 }
 ```
 2. ***Bottom-up method***  
 이 접근 방식은 문제의 크기를 중요하게 생각한다. 특정 문제를 해결할 때, 그보다 더 작은 부분 문제의 solution이 필요한 경우에 해당한다. 부분 문제를 크기 순서로 오름차순 정렬한 뒤 다음, 작은 것을 먼저 순서대로 처리한 뒤 본 문제를 해결한다.  
 ```cpp
 int BOTTOM_UP_CUT_ROD(int *p, int n)
 {
    int r* = new int[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        q = -INT_INF;
        for (int i = 1; i <= j; i++)
            q = max(q, p[i] + r[j - i]);
        r[j] = q;
    }
    return r[n];
 }
 ```

 두 방식 모두 같은 시간복잡도를 가지지만, 2번의 경우 함수 재귀호출의 오버헤드가 없기 때문에 1번 방식과 비교해서 조금 더 나은 성능을 보인다.

 #### Subproblem graph
 Dynamic programming 문제를 생각할 때, 어떻게 각 부분 문제가 하위 문제와 서로 연관이 되어있는지에 대한 이해가 필요하다. 이를 쉽게 하기 위해 Subproblem graph를 활용할 수 있다. 이 그래프는 방향 그래프로, 각 정점은 부분 문제를 나타내고 부분 문제 v를 푸는데 u의 solution이 직접적으로 필요하다면 간선 (u, v)를 가진다.