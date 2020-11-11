#pragma once

#include "Resource.hpp"

class ResourceManager
{
 public:
    Resource* R;
    ResourceManager() : R{} { cout << "1tworzenie" << endl; }

    ResourceManager(const ResourceManager& Rm)
    {
        Resource* G;
        G = Rm.R;
        R = G;
        G = nullptr;
        delete G;
        //cout << "2kopiuje" << endl;
    }

    ResourceManager& operator=(const ResourceManager& Rm)
    {
        if (&Rm == this) {
        }
        else {
            R = nullptr;
            Resource* G;
            G = Rm.R;
            R = G;
           // cout << "3kopiuje=" << endl;
            G = nullptr;
            delete G;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& Rm)
    {
        R    = Rm.R;
        Rm.R = nullptr;
        delete Rm.R;
        //cout << "przeniesienie" << endl;
    }

    ResourceManager& operator=(ResourceManager&& Rm)
    {
        R = Rm.R;
       // cout << "kopia przeniesienia" << endl;
        Rm.R = nullptr;
        delete Rm.R;
        return *this;
    }

    double get()
    {
        //cout << "k";
        return R->get();
    }
    ~ResourceManager() { delete R; }

};