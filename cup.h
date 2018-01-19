#ifndef cup_h
#define cup_h
#include <iostream>
#include "container.h"

class Cup : public Container
{
private:
    enum sizes{tall,grande,venti,trenta};
    sizes size;
public:
    Cup(std::vector<Scoop> s, int n, sizes si) : Container(s,n), size{si} {}
};

#endif
