#ifndef THEATRE_H
#define THEATRE_H

#include "livre.h"

class Theatre : public Livre
{
public:
    Theatre();
private:
    int siecle;

};

#endif // THEATRE_H
