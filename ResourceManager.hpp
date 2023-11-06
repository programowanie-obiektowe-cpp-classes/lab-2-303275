#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:

    ResourceManager()
    {
        rsc = new Resource();
    }

    double get()
    {
        return rsc->get();
    }

    ResourceManager(const ResourceManager& other)
    {
        rsc = new Resource(*other.rsc); 
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        delete rsc;
        rsc = other.rsc;
        other.rsc = nullptr;
        return *this;
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        delete rsc;
        rsc = new Resource(*other.rsc);
        return *this;
    }

    ResourceManager(ResourceManager&& other)
    {
        rsc = other.rsc;
        other.rsc = nullptr;
    }

    ~ResourceManager()
    {
        if(rsc != nullptr)
        {
            delete rsc;
        }
    }

    


private:
    Resource* rsc;
};
