#include <iostream>
#include <string>

using namespace std;

class Personality 
{
protected:
    int hp;
    int strength;
    int iq;

    Personality(int hp = 0, int strength = 0, int iq = 0)
    {
        this->hp = hp;
        this->strength = strength;
        this->iq = iq;
    }

    ~Personality()
    {
        hp = 0;
        strength = 0;
        iq = 0;
    }
    
public:
    virtual string specificity() = 0;

    int basic_hp()
    {
        return hp;
    }

    int basic_strength()
    {
        return strength;
    }

    int basic_iq()
    {
        return iq;
    }
};

class AttackingTitan : public Personality
{
public:
    AttackingTitan(int hp = 0, int strength = 0, int iq = 0) : Personality(hp, strength, iq)
    {};

    string specificity() 
    {
        return "vision  of future";
    }
};

class ArmoredTitan : public Personality
{
public:
    ArmoredTitan(int hp = 0, int strength = 0, int iq = 0) : Personality(hp, strength, iq)
    {};

    string specificity()
    {
        return "Body armor";
    }
};

class FemaleTitan : public Personality
{
public:
    FemaleTitan(int hp, int strength, int iq) : Personality(hp, strength, iq)
    {};

    string specificity()
    {
        return "close fight";
    }
};

class ColossalTitan : public Personality
{
public:
    ColossalTitan(int hp, int strength, int iq) : Personality(hp, strength, iq)
    {};

    string specificity()
    {
        return "huge size";
    }
};

class CarrierTitan : public Personality
{
public:
    CarrierTitan(int hp, int strength, int iq) : Personality(hp, strength, iq)
    {};

    string specificity()
    {
        return "maneuverability and small size";
    }
};

class Titan
{
public:
    void features(Personality *personality)
    {
        cout << personality->specificity() << endl;
    }

    void BasicSpecs(Personality *personality)
    {
        cout << personality->basic_hp() << endl << personality->basic_strength() << endl << personality->basic_iq() << endl;
    }
};

int main(int argc, char *argv[])
{
    AttackingTitan atc(2300, 1700, 133);
    ArmoredTitan arm(5000, 3500, 100);
    FemaleTitan fem(1500, 1000, 140);
    ColossalTitan col(10000, 3000, 85);
    CarrierTitan car(700, 500, 150);
    Titan T;
    
    T.features(&atc);
    T.BasicSpecs(&atc);

    T.features(&arm);
    T.BasicSpecs(&arm);

    T.features(&fem);
    T.BasicSpecs(&fem);

    T.features(&col);
    T.BasicSpecs(&col);
    
    T.features(&car);
    T.BasicSpecs(&car);

    return EXIT_SUCCESS;
} 