#ifndef ROMAN_H
#define ROMAN_H

#include "livre.h"

class Roman : public Livre
{
public:
    Roman();
private:
    QString genre;
};

#endif // ROMAN_H
