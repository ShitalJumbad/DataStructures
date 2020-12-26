# DataStructures

**********************************************************************************************************************************************
https://leetcode.com/problems/course-schedule/

Q. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.


***********************************************************************************************************************************************

BUILD Order

TIME COMPLEXITY  ->  O(V+D) --> V is number of vertices, D is number of dependency pair

#Solution1

DFS/Topological Sort

a->e
b->a->e->h
c->a
d->g
e->0
f->c->a->b
g->0
h->0

dfs(a)					a,e
	dfs(e)				e
dfs(b)					b,a,e
	dfs(a) … return
	dfs(e) … return
	dfs(h)				h,b,a,e
dfs(c)					c,h,b,a,e
	dfs(a) … return
dfs(d)					d,g,c,h,b,a,e
	dfs(g)				g,c,h,b,a,e
dfs(e)  … return 
dfs(f)					f,d,g,c,h,b,a,e
	dfs(c) … return
	dfs(a) … return
	dfs(b) … return
dfs(g) …. return 
dfs(h) … return 

works fine
Now what if there is cycle

0->1
1->2
2->0

dfs(0)
	dfs(1)
		dfs(2)
			dfs(0) return false


Not a Cycle

0->1->2
1->2
2->NULL

dfs(0)					0,1,2
	dfs(1)				1,2
		dfs(2)			2
	dfs(2)  … return 


Here a cycle can happen while doing DFS on a node, we might run back into the same path. 
We need a signal in that case indicating that I am still processing this node and not completed it.
If we such signal we return FLSE that we cant get build order or topological sort out of it.

Defining a states of visited array
0--> Not visted
1--> Done visiting(COMPLETED)
2-->Still processing the node(PARTIALLY VISITED)

CAN refer this on page 193 cracking the coding interview


#Solution2
edges : [[0,1],[1,2],[0,2]]


2->NULL

0->-1
1->-1
2->0


output: [0,1,2]

edges:[[0,1],[2,0],[1,2]]

graph
0->1->2
1->2
2->0

vector count
[1,1,1]
 CAN refer this on page 189 cracking the coding interview
