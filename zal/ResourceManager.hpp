#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    Resource* R;
    ResourceManager(): R{} {}
    ~ResourceManager() {delete R;}

    ResourceManager(const ResourceManager& rm)
    {
    Resource* G;
    G=rm.r;
    R=G;
    }
    
    

    ResourceManager& operator=(const ResourceManager& Rm)
    {
        if(&Rm==this)
        {

        }
        else if{
          R=nullptr;
          R=Rm.R;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& Rm)
    {
        R = Rm.r;
        Rm.r = nullptr;
    }

   // ResourceManager& operator=(ResourceManager&& rm) {}

    double get() {return R->get();}




};