#ifndef CANNON_H_
#define CANNON_H_

#include "storage.h"

class Cannon
{
private:
    enum
    {
        MAX_AMMO = 10,
        MAX_HEALTH = 100
    };
    
    int ammo;
    int health;

public:
    Cannon();
    Cannon(Payload payload);

    // send event about self desctruction to "subscribers"
    ~Cannon();

    // send damage to target. Damage is equal to damage in Bullet from Payload
    // you store in canon.
    void shoot();

    // To load the cannon you have to send to loader
    // your current amount of bullets you have and loader will
    // fill the canon to MAX_AMMO.
    void load_ammo(Payload payload);

    // receive damage from enemy. If health is equal or lower then 0 - call destructor 
    void hit();
    
};

#endif // CANNON_H_
