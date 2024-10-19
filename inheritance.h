#include <iostream>
using namespace std;

class Transformer {
public:
    Transformer(int energon, int dmg);

    void run();
    void attack();
    void recharge();
    int getlevel() const;
    int getDamage() const;
protected:
    int energonLevel;
    int damage;
};

class FlyingTransformer : public Transformer {
public:
    FlyingTransformer(int energon, int dmg, int height);

    void fly();
    int getHeight() const;
    private:
    int flightHeight;
};
