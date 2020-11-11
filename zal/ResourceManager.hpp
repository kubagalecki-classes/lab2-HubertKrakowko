#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    Resource* R;
    ResourceManager()
    {
        R = new Resource;
        
    }

    ResourceManager(const ResourceManager& Rm) : R(Rm.R)
    {

        R = new Resource{*Rm.R};

       
    }

    ResourceManager& operator=(const ResourceManager& Rm)
    {
        if (&Rm == this) {
           
        }
        else {
            R = nullptr;
            R = new Resource{*Rm.R};
           
        }
        return *this;
    }

    ResourceManager(ResourceManager&& Rm)
    {
        R    = Rm.R;
        Rm.R = nullptr;
        delete Rm.R;
        
    }

    ResourceManager& operator=(ResourceManager&& Rm)
    {
        if (&Rm == this) {
            
        }
        else {
            delete R;
            R = Rm.R;
            
            Rm.R = nullptr;
        }
        return *this;
    }

    double get()
    {
        
        return R->get();
    }
    ~ResourceManager() { delete R; }
};