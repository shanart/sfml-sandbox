#ifndef STORAGE_H_
#define STORAGE_H_
#include <iostream>
#include <vector>

/*

    Bullet regular = {"regular", 10};
    Payload p_payload = {regular, 40};

    Bullet penetr = {"penetration", 20};
    Payload p_penetr_payload = {penetr, 20};

    Storage storage = Storage();

    storage.fill_storage(p_payload);
    storage.fill_storage(p_penetr_payload);

    storage.show_storage();

*/

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
