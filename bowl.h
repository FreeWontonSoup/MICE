#ifndef bowl_h
#define bowl_h
#include <iostream>
#include "container.h"

class Bowl : public Container
{
private:
    enum sizes{small,medium,large};
    sizes size;
public:
    Bowl(std::vector<Scoop> s, int n, sizes si) : Container(s,n), size{si} {}
};

#endif
