/**
 * Solution for "Extra Judicial Operation"
 * (1) partition into connected components (DFS), these can be handled separately
 * (2) as part of the partitioning process find all bridges (4.2.8 Competitive Programming 3)
 * (3) refine into "tightly" connected components w.r.t. non-bridge edges
 * (4) build "bridge-graph": vertices = tightly connected components, edges = bridges
 * (5) number of judges required = number of vertices in bridge-graph with at most one neighbor
 * g++ -g -O2 -static -std=gnu++11 -o extra extra.cpp
 */

#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

struct Edge
{
    int to;
    bool bridge;
    Edge(int to): to(to), bridge(false) {};
};

struct Vertex
{
    vector<Edge> neighbors;
    int component, dfs_parent, dfs_num, dfs_low;
    
    void addNeighbor(int to) { neighbors.push_back( Edge(to) ); }
};

typedef vector<Vertex> Graph;

int dfs_component(Graph &g, int v, int component, int dfs_num);

// DFS to initialize component, dfs_num and dfs_low
// returns number of connected components found
int dfs(Graph &g)
{
    // reset graph
    for ( int v = 0; v < g.size(); v++ )
        g[v].dfs_parent = g[v].dfs_num = g[v].dfs_low = 0;
    // dfs
    int component = 0;
    for ( int v = 0; v < g.size(); v++ )
        if ( g[v].dfs_num == 0 )
            dfs_component(g, v, component++, 1);
    return component;
}

// returns next dfs_num; ignores bridges
int dfs_component(Graph &g, int v, int component, int dfs_num)
{
    Vertex &vertex = g[v];
    vertex.component = component;
    vertex.dfs_low = vertex.dfs_num = dfs_num++;
    for ( int n = 0; n < vertex.neighbors.size(); n++ )
    {
        // skip bridges
        if ( vertex.neighbors[n].bridge )
            continue;
        int to = vertex.neighbors[n].to;
        // skip if we're coming from there
        if ( to == vertex.dfs_parent )
            continue;
        // DFS unless already visited
        if ( g[to].dfs_num == 0 )
        {
            g[to].dfs_parent = v;
            dfs_num = dfs_component(g, to, component, dfs_num);
        }
        // update dfs_low
        int dfs_low = g[to].dfs_low;
        if ( dfs_low < vertex.dfs_low )
            vertex.dfs_low = dfs_low;
    }
    return dfs_num;
}

void mark_bridges(Graph &g)
{
    for ( int v = 0; v < g.size(); v++ )
        for ( int n = 0; n < g[v].neighbors.size(); n++ )
        {
            int to = g[v].neighbors[n].to;
            if ( g[to].dfs_low > g[v].dfs_num || g[v].dfs_low > g[to].dfs_num )
                g[v].neighbors[n].bridge = true;
        }
}

// finds the degrees of components in the bridge-graph of g
// can do that without actually building the bridge-graph
void find_componentDegrees(Graph &g, vector<int> &cd)
{
    for ( int v = 0; v < g.size(); v++ )
    {
        Vertex &vertex = g[v];
        for ( int n = 0; n < vertex.neighbors.size(); n++ )
            if ( vertex.neighbors[n].bridge )
                cd[vertex.component]++;
    }
}

int main(int argc, char* argv[])
{
    Graph g;
    if ( argc > 1 && !strcmp(argv[1], "test") )
    {
        // generate test data
        int S = 100000;
        printf("%d\n", S);
        for ( int v = 0; v < S; v++ )
            printf("1 %d\n", (v+1) % S);
        return 0;
    }
    // scan input
    #pragma GCC diagnostic ignored "-Wunused-result"
    int S;
    scanf("%d", &S);
    g.resize(S);
    for ( int v = 0; v < S; v++ )
    {
        int nCount;
        scanf("%d", &nCount);
        for ( int n = 0; n < nCount; n++ )
        {
            int neighbor;
            scanf("%d", &neighbor);
            g[v].addNeighbor(neighbor);
            g[neighbor].addNeighbor(v);
        }
    }
    // solve
    dfs(g);
    mark_bridges(g);
    int components = dfs(g); // this time bridges are ignored
    vector<int> componentDegrees(components);
    find_componentDegrees(g, componentDegrees);
    int judges = 0;
    for ( int c = 0; c < componentDegrees.size(); c++ )
        if ( componentDegrees[c] < 2 )
            judges++;
    // print solution
    printf("%d\n", judges - 1);
}
