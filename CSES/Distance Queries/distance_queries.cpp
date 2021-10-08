//This a soution to question of distance queries .Your can read the question here 
//https://cses.fi/problemset/task/1135
//done this with binary tree lifting and LCA calculationu using DFS

//sample test case tree
/*5 nodes 1,2,3,4,5

        (1,-1)
        /     \
      (2,1)   (3,1)
              /    \
            (4,2)  (5,2)

    Queries are 
    between 1 3  distance is 1
    between 2 5  distance is 3
    between 1 4  distance is 2
*/

#include <bits/stdc++.h>
const int MAX_N=200005;
const int LOG=20;//maximum hieght of tree possible 

using namespace std;

using ll=long long;

vector<int> edges[MAX_N];//storing the nodes in form of adjacency list

int depth[MAX_N];// finding depth with respect to the root node

int up[MAX_N][LOG];//up[i][j] is the 2^j-th ancestor above the node i with i=1...N, j=0...ceil(log(N))

//complete process takes O(nlogn) to precalculate depth of each node
void dfs(int a,int parent)
{
  for(int b:edges[a])//traversing all the linked nodes to a particular node
  {
    if(b==parent)//ignoring if a node is parent means it is already calculated
      continue;
  

  depth[b]=depth[a]+1;//depth of child is depth of parent + 1 always
  up[b][0]=a;//0th parent of b is always a then as 1st,2nd,3rd changes... then parent change moves above 'a'

  for(int j=1;j<LOG;j++)
  {
    up[b][j]=up[up[b][j-1]][j-1];//up[node 2][1](2's 1st parent is same as) up[(node)1][0] (node 1's 0th parent that is -1 and up[(node)2][0] 2nd node's just above parent is 1 as seen in statement above for loop)
  }

  dfs(b,a);//recurssive calling by replacing parent of 2 to 1 dfs(2,1)
  }
   // dfs(b,a);
}


int get_lca(int child,int parent)
{
if(depth[child]<=depth[parent])// child depth always more than parent's depth ,therefore the case inside if statement not possible so swap parent child
  swap(child,parent);

  int k=depth[child]-depth[parent];             

  for(int j=LOG-1;j>=0;j--)
  {
    if(k&(1<<j))
      child=up[child][j]; //moving the pointer on child node which is more deep that parent node on opposite part of tree so that both pointerns can start from same level and move above till the parent does not match
  }

  if(child==parent)
    return child; // if already child is found equal to parent then return that because this is the LCA we are looking for

    //other wise keep on moving up till we get  from 19th parent to 0th parent and in between if both are found same then no replacing of child or parent with common branch above because we have got that node which is point of intersection of both from bottom

  for(int j=LOG-1;j>=0;j--)
  {
    if(up[child][j]!=up[parent][j])
    {
      child=up[child][j];
      parent=up[parent][j];
    }
  }

  return up[child][0];// return the self value as this the value at 0th parent / value of self-parent 
}

int main()
{
  ios_base::sync_with_stdio();
  cin.tie(NULL);
  cout.tie(NULL);

  int n,q;
  scanf("%d %d",&n,&q);

  for(int i=0;i<n-1;i++)
  {
    int a,b;
    scanf("%d %d",&a,&b);

    edges[a].push_back(b);
    edges[b].push_back(a);//inserting inteo adjacency list the nodes to keep track of edges 


  }

  dfs(1,-1);//finding the heights of ech node from root node (1) and assuming it as top node it's parent -1

  while(q--)
  {
    int a,b;
    scanf("%d %d",&a,&b);

    int lca=get_lca(a,b);

    int answer=depth[a]-depth[lca]+depth[b]-depth[lca];//dp calculated depth of lca subtracted from left subtree node and right sub tree node 

    cout<<answer<<"\n";
  }
}