#include <iostream>
#include "cannon.h"

Cannon::Cannon()
{
    ammo = MAX_AMMO;
    health = 100;
}

Cannon::Cannon(int ammo_ammount)
{
    if (ammo_ammount > MAX_AMMO)
    {
        ammo = MAX_AMMO;
    }
    else
    {
        ammo = ammo_ammount;
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
        std::cout << "Cannon shooting. Ammo: " << ammo  << std::endl;
    }
    else
    {
        std::cout << "No ammo" << std::endl;
    }
}

void Cannon::load_ammo(int ammo_amount)
{
    ammo += ammo_amount;
    if (ammo > MAX_AMMO)
    {
        ammo = MAX_AMMO;
    }
}
