#ifndef STORAGE_H_
#define STORAGE_H_
#include <iostream>
#include <vector>

typedef struct
{
    std::string name;
    int damage;
} Bullet;

typedef struct
{
    Bullet ammunition_type;
    int amount;
} Payload;

class Storage
{
private:
    enum
    {
        MAX_CAPACITY = 100
    };
    std::vector<Payload> payloads;
    int ammo;

public:
    Storage();
    ~Storage();
    void charging();
    void show_storage() const;
    bool fill_storage(Payload p);
};

#endif // STORAGE_H_
