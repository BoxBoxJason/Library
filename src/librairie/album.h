#ifndef ALBUM_H
#define ALBUM_H

#include "livre.h"

class Album : public Livre
{
public:
    Album();
private:
    QString illustrations;
};

#endif // ALBUM_H
