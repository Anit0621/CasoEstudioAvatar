#ifndef AVATAR_H
#define AVATAR_H

#include "Personaje.h"

class Avatar : public Personaje {
public:
    Avatar();
    void mover(char direction) override; // Método override como en el ejemplo del profesor
};

#endif // AVATAR_H