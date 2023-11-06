#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:

    ResourceManager()
    {
        resource = new Rsc();
    }

    double get()
    {
        return resource->get();
    }

    ResourceManager(const ResourceManager& other)
    {
        resource = new Rsc(*other.resource); 
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        delete resource;
        resource = other.resource;
        other.resource = nullptr;
        return *this;
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        delete resource;
        resource = new Rsc(*other.resource);
        return *this;
    }

    ResourceManager(ResourceManager&& other)
    {
        resource = other.resource;
        other.resource = nullptr;
    }

    ~ResourceManager()
    {
        if(resource != nullptr)
        {
            delete resource;
        }
    }

    


private:
    Rsc* resource;
};
