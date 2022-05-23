#include <iostream>
#include "storage.h"

int main()
{

    Bullet regular = {"regular", 10};
    Payload p_payload = {regular, 40};

    Bullet penetr = {"penetration", 20};
    Payload p_penetr_payload = { penetr, 20};
    
    Storage storage = Storage();

    storage.fill_storage(p_payload);
    storage.fill_storage(p_penetr_payload);
  
    storage.show_storage();
    
    return 0;
}
