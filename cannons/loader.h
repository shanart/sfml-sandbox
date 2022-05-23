#ifndef LOADER_H_
#defing LOADER_H_

class Loader
{
private:
    enum
    {
        MAX_CAPACITY = 100;
    };
    int capacity;
    // TODO: weapon type;
    
public:
    void upload();
    void reload(int amount);
  
};


#endif // LOADER_H_
