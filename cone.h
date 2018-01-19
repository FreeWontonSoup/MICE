#ifndef cone_h
#define cone_h
#include <iostream>
#include "container.h"

class Cone : public Container
{
private:
    enum ctype{sugar,waffle};
    ctype coneType;
public:
    Cone(std::vector<Scoop> s, int n, ctype c) : Container(s,n), coneType{c} {}
};

#endif
