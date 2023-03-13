# maximal-clique-in-the-Hamming-graph
 Task: The Hamming distance dist(u, v) between two binary vectors v= (v1,...,vn) and 
w= (w1,...,wn)is the number of indices k such that vk ≠ wk. A fundamental question 
in coding theory is to determine the number A(n, d) = max|{ S ⊂ {0,1}^n |dist(u, v) ≥ 
d for all distinct u, v ∈ S }|, the maximal number of binary vectors of length n that one 
can find such that any two distinct vectors have a Hamming distance ≥d. For example, 
A(5,4) = 2. The Hamming graph H(n, d)= (V, E) is the graph with 2^n vertices V given 
by binary strings of length n. We have (u, v) ∈ E if and only if dist(u, v) ≥ d. The 
number A(n, d) coincides with the size of a maximal clique in H(n,d). Find an 
implement "efficient" algorithms to compute the maximal clique in the Hamming 
graph (but note that the problem to compute maximal cliques is NP-hard) in c++.

1)The Hamming distance between two binary vectors is the number of indices at which 
the two vectors differ.
2)The goal is to find the maximal number of binary vectors of length n such that any 
two distinct vectors have a Hamming distance of at least d. This number is denoted as 
A(n,d).
3)One way to approach this problem is to consider the Hamming graph, H(n,d), which 
has 2^n vertices (one for each binary string of length n) and an edge between two 
vertices if the Hamming distance between the corresponding binary vectors is at least 
d. The problem of finding A(n,d) is then equivalent to finding the size of a maximal 
clique in H(n,d).
4)The task is to implement an efficient algorithm to compute the maximal clique in the 
Hamming graph. However, it is important to note that the problem of finding maximal 
cliques is NP-hard, meaning that it is unlikely that there exists an algorithm that can 
solve this problem efficiently for all cases.

TIME COMPLEXITY
The generateBinary function generates all possible binary combinations of a given size, 
which takes O(2^n) time, where n is the size of the binary vectors. 
The findMaximalClique function performs a breadth-first and depth- first search over all 
combinations, which takes O(V + E) time, where V is the number of combinations and E 
is the number of edges in the graph. In this case, each combination is a vertex and there is 
an edge between two combinations if their Hamming distance is at least the minimum 
distance.
Since there are 2^n combinations and each combination is connected to at least n other 
combinations (assuming the minimum distance is 1), the total number of edges is at least 
2^n * n. As a result, the time complexity of the findMaximalClique function is O(2^n * 
n).
Combining the time complexity of the two functions, the overall time complexity of the 
code is O(2^n * n). This means that the running time of the code will increase 
exponentially as the size of the binary vectors increases. For example, if the size of the
binary vectors is 8, the running time will be O(256 * 8) = O(2048), which is relatively 
fast. However, if the size of the binary vectors is 16, the running time will be O(65536 * 
16) = O(1048576), which is significantly slower.
The time complexity of recursive backtracking algorithm is O(3^N * N), where N is the size 
of the binary vectors.
The main bottleneck in the time complexity is the recursive call to find_clique. In each 
recursive call, the function must loop through all the elements in the possible_vertices 
vector to find the node with the maximum number of connections, which takes O(3^N) 
time. It must also update the possible_vertices vector by looping through all its elements, 
which also takes O(3^N) time. Therefore, the time complexity of a single recursive call is 
O(3^N).
Since the recursion continues until the possible_vertices vector becomes empty, and the 
size of the possible_vertices vector decreases by at least 1 in each recursive call, the 
recursion will make at most O(3^N) recursive calls. Therefore, the overall time 
complexity of the find_clique function is O(3^N * 3^N) = O(3^(2*N)).
In addition to the recursive calls, the find_clique function also makes O(N) calls to the 
connection_count function in each recursive call. The connection_count function also 
takes O(N) time, so the total time complexity of the connection_count function is O(3^N 
* N).
Therefore, the overall time complexity of the code is O(3^(2*N) + 3^N * N) = O(3^N * 
(3 + N)). Since 3^N grows much faster than N, the time complexity can be simplified to 
O(3^N * N).
