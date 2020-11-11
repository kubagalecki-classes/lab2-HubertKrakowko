#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    Resource* R;
    ResourceManager(): R{} {}
    ~ResourceManager() {delete R;}

    ResourceManager(const ResourceManager& Rm)
    {
    Resource* G;
    G=Rm.R;
    R=G;
    delete G;
    }
    
    

    ResourceManager& operator=(const ResourceManager& Rm)
    {
        if(&Rm==this)
        {

        }
        else{
          R=nullptr;
          R=Rm.R;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& Rm)
    {
        R = Rm.R;
        Rm.R = nullptr;
    }

   ResourceManager& operator=(ResourceManager&& rm) {}

    double get() {return R->get();}




};