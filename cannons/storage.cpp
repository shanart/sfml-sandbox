#include <iostream>
#include "storage.h"

Storage::Storage()
{
    ammo = 0;
}

Storage::~Storage()
{
    std::cout << "remove storage" << std::endl;
}

void Storage::charging()
{
    ammo -= 10;
}

void Storage::show_storage() const
{
    std::cout << "Storage:\nTotal: " << ammo << std::endl;

    for (auto & element : payloads) {
        std::cout << "name: " << element.ammunition_type.name << std::endl;
        std::cout << "damage: " << element.ammunition_type.damage << std::endl;
        std::cout << "ammount: " << element.amount << std::endl;
    }
}

bool Storage::fill_storage(Payload p)
{
    // TODO: check amount ( return false if  storage is full (should return error instead of bool))
    payloads.push_back(p);
    ammo += p.amount;
    return true;
}
