#include "path.h"
#include <queue>
#include <cmath>
struct Node{int x,y; float f,g; int px,py;};
struct Cmp{bool operator()(const Node&a,const Node&b)const{return a.f>b.f;}};

Path astar(const Grid& g,int sx,int sy,int tx,int ty){
    std::priority_queue<Node,std::vector<Node>,Cmp> open;
    std::vector<float> best(g.w*g.h,1e9f);
    std::vector<int> parent(g.w*g.h,-1);
    auto id=[&](int x,int y){return y*g.w+x;};
    auto h=[&](int x,int y){return std::abs(tx-x)+std::abs(ty-y);};
    open.push({sx,sy,(float)h(sx,sy),0,-1,-1});
    best[id(sx,sy)]=0;
    int found=-1;
    while(!open.empty()){
        Node n=open.top(); open.pop();
        if(n.x==tx && n.y==ty){ found=id(n.x,n.y); parent[found]= (n.py>=0? id(n.px,n.py):-1); break; }
        const int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto& d:dirs){
            int nx=n.x+d[0], ny=n.y+d[1];
            if(!g.passable(nx,ny)) continue;
            float ng=n.g + g.cost[ny*g.w+nx];
            int nid=id(nx,ny);
            if(ng<best[nid]){ best[nid]=ng; parent[nid]=id(n.x,n.y); open.push({nx,ny,ng+h(nx,ny),ng,n.x,n.y}); }
        }
    }
    Path p;
    int cur=found;
    while(cur!=-1){ int x=cur%g.w, y=cur/g.w; p.pts.push_back({(float)x,(float)y}); cur=parent[cur]; }
    std::reverse(p.pts.begin(),p.pts.end());
    return p;
}
