#pragma once
#include <string>

class Renderable {
    public:
    unsigned int nested_depth;

    Renderable() {
        nested_depth = 0;
    };
    ~Renderable() {};
    
    virtual std::string Render() = 0;
};

std::string GenerateTabs(unsigned int tabs);
