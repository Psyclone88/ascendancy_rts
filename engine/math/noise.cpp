#include "noise.h"
#include <cmath>
static int perm[512]; static bool init=false;
static void initperm(){
    int p[256]; for(int i=0;i<256;++i)p[i]=i;
    unsigned s=1337u;
    auto rnd=[&](){ s^=s<<13; s^=s>>17; s^=s<<5; return s; };
    for(int i=255;i>0;--i){ int j=rnd()% (i+1); int t=p[i]; p[i]=p[j]; p[j]=t; }
    for(int i=0;i<512;++i) perm[i]=p[i&255];
    init=true;
}
static float grad(int h, float x, float y){ switch(h&3){case 0:return x+y;case 1:return -x+y;case 2:return x-y;default:return -x-y;} }
float noise2(float x, float y){
    if(!init) initperm();
    int X=(int)floorf(x)&255, Y=(int)floorf(y)&255;
    x-=floorf(x); y-=floorf(y);
    float u=x*x*x*(x*(x*6-15)+10);
    float v=y*y*y*(y*(y*6-15)+10);
    int aa=perm[X+perm[Y]], ab=perm[X+perm[Y+1]], ba=perm[X+1+perm[Y]], bb=perm[X+1+perm[Y+1]];
    float res = std::lerp(std::lerp(grad(aa,x,y), grad(ba,x-1,y), u),
                          std::lerp(grad(ab,x,y-1), grad(bb,x-1,y-1), u), v);
    return res*0.7071f;
}
float fbm2(float x, float y, int oct){
    float v=0, a=0.5f; for(int i=0;i<oct;++i){ v+=a*noise2(x,y); x*=2; y*=2; a*=0.5f;} return v;
}
