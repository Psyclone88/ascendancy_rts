#pragma once
#include <cmath>
#include <cstdint>
struct Vec2{ float x,y; };
struct Vec3{ float x,y,z; };
struct Rect{ float x,y,w,h; };
inline Vec2 v2(float x,float y){return {x,y};}
inline Vec2 v2add(Vec2 a,Vec2 b){return {a.x+b.x,a.y+b.y};}
inline Vec2 v2sub(Vec2 a,Vec2 b){return {a.x-b.x,a.y-b.y};}
inline Vec2 v2mul(Vec2 a,float s){return {a.x*s,a.y*s};}
inline float v2dot(Vec2 a,Vec2 b){return a.x*b.x+a.y*b.y;}
inline float v2len2(Vec2 a){return v2dot(a,a);}
inline float v2len(Vec2 a){return std::sqrt(v2len2(a));}
inline Vec2 v2norm(Vec2 a){float l=v2len(a); return l>0? v2mul(a,1.0f/l):a;}
