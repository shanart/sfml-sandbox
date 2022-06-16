#include <iostream>
#include "cannon.h"

Cannon::Cannon()
{
    ammo = MAX_AMMO;
    health = 100;
}

Cannon::Cannon(Payload payload)
{
    // TODO: Check bulet types before load
    if (payload.amount > MAX_AMMO)
    {
        ammo = MAX_AMMO;
    }
    else
    {
        ammo = payload.amount;
    }
}

Cannon::~Cannon()
{
    std::cout << "Cannon destructor" << std::endl;
}

void Cannon::shoot()
{
    if (ammo > 0)
    {
        ammo -= 1;
        std::cout << "Cannon shooting. Ammo: " << ammo << std::endl;
    }
    else
    {
        std::cout << "No ammo" << std::endl;
    }
}

void Cannon::load_ammo(Payload payload)
{
    ammo += payload.amount;
    if (ammo > MAX_AMMO)
    {
        ammo = MAX_AMMO;
    }
}
