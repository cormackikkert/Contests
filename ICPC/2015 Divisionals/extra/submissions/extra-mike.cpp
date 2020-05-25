//
//  extra_sol1.cpp
//
//  Problem setter's code for "Extra Judicical Operation" SPPC Regional 2016
//
//  Basic idea is that if the graph is viewed as a tree of edge bi-connected
//  components, separated by bridges, a server is needed (only) at each leaf
//
//  Find the bridges by a DFS. (Use non-recursive one as not sure about stack
//  space available on judging machine.) Then, not allowing bridges to be
//  crossed, form BFS forest of edge bi-connected components, with leaves
//  being the components from which only one bridge can be seen.
//
//  Note: Originally thought of solving all this in a single DFS, but decided
//  to break it up into the two pass approach.

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int n_sites;
vector<vector<pii> > adjs; // pair is to vertex and edge number for bridgeness
int n_edges; // In sense of number of undirected edges
vector<bool> is_bridge;

vector<bool> bfs_seen;

int n_leaves;

// single bfs stuff
int n_bridges_seen; // Number of bridges seen on this
void bfs(int v)
{
    queue<int> q;
    q.push(v);
    bfs_seen[v] = true;
    
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        int n = (int)adjs[here].size();
        for(int i = 0; i < n; i++)
        {
            pii edge = adjs[here][i];
            if(is_bridge[edge.second])
            {
                n_bridges_seen++;
            }
            else if(!bfs_seen[edge.first])
            {
                q.push(edge.first);
                bfs_seen[edge.first] = true;
            }
        }
    }
}

int main()
{
    // read graph
    cin >> n_sites;
    adjs = vector<vector<pii> >(n_sites);
    n_edges = 0;
    for(int i = 0; i < n_sites; i++)
    {
        int n_tos;
        cin >> n_tos;
        for(int j = 0; j < n_tos; j++)
        {
            int to;
            cin >> to;
            adjs[i].push_back(make_pair(to, n_edges));
            adjs[to].push_back(make_pair(i, n_edges));
            n_edges++;
        }
    }
    
    // non-recursive dfs, surfeit of DSs
    is_bridge = vector<bool>(n_edges);
    vector<bool> dfs_seen = vector<bool>(n_sites);
    vector<int> parent(n_sites); // came from
    vector<int> pre(n_sites); // pre-order numbers
    vector<int> best(n_sites, n_sites); // best (i.e. lowest pre) seen from here
    stack<pii> stk; // pair is vertex and current adj list place

    int pre_num = 0;
    
    stk.push(make_pair(0, -1));
    dfs_seen[0] = true;
    pre[0] = pre_num++;
    best[0] = pre[0];
    
    while(!stk.empty())
    {
        int here = stk.top().first;
        int & current = stk.top().second; // reference so as to update
        current++;
        if(current < (int) adjs[here].size())
        {
            int to = adjs[here][current].first;
            if(!dfs_seen[to])
            {
                stk.push(make_pair(to, -1));
                parent[to] = here;
                dfs_seen[to] = true;
                pre[to] = pre_num++;
                best[to] = pre[to];
            }
            else
            {
                if((to != parent[here]) && (best[here] > pre[to]))
                {
                    best[here] = pre[to];
                }
            }
        }
        else
        {
            stk.pop();
            if(!stk.empty())
            {
                int above = stk.top().first;
                if(pre[above] < best[here])
                {
                    is_bridge[adjs[above][stk.top().second].second] = true;
                }
                if(best[above] > best[here])
                {
                    best[above] = best[here];
                }
            }
        }
    }
    
    // Repeated BFSs
    bfs_seen = vector<bool>(n_sites);
    for(int start = 0; start < n_sites; start++)
    {
        if(!bfs_seen[start])
        {
            n_bridges_seen = 0;
            bfs(start);
            if(n_bridges_seen < 2) n_leaves++;
        }
    }
    
    cout << (n_leaves - 1) << endl;

    return 0;
}
