#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <typeindex>

using Entity = uint32_t;

struct IStore{ virtual ~IStore()=default; virtual void erase(Entity)=0; };
template<typename T>
struct Store : IStore{
    std::unordered_map<Entity,T> data;
    void erase(Entity e) override { data.erase(e); }
    T* get(Entity e){ auto it=data.find(e); return it==data.end()?nullptr:&it->second; }
    T& emplace(Entity e,const T& v=T{}){ return data.emplace(e,v).first->second; }
};

struct ECS {
    Entity next=1;
    std::vector<IStore*> stores;
    template<typename T> Store<T>& store(){
        static Store<T>* s=nullptr;
        if(!s){ s=new Store<T>(); stores.push_back(s); }
        return *s;
    }
    Entity create(){ return next++; }
    void destroy(Entity e){ for(auto*s:stores) s->erase(e); }
};
extern ECS g_ecs;
