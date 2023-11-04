#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource() {}

    double get() {
        return resource.get();
    }

    ResourceManager(const ResourceManager& other) : resource(other.resource) {}


    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }

    ~ResourceManager() {}

private:
    Resource resource;
};