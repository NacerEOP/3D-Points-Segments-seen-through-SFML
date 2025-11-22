#pragma once
#include "point.h"

class CLparcours
{
protected:
    CLpoint** tab;
    int tailleMax;
    int index;

public:
    virtual ~CLparcours() = default;

    virtual void ajouterPoint(CLpoint* p) = 0;
    virtual float calculDistance() = 0;
    virtual void message() = 0;
};


class CLparcours2D : public CLparcours
{
public:
    CLparcours2D(int taille);
    ~CLparcours2D() = default;

    void ajouterPoint(CLpoint* p) override;
    float calculDistance() override;
    void message() override;
};


class CLparcours3D : public CLparcours
{
public:
    CLparcours3D(int taille);
    ~CLparcours3D() = default;

    void ajouterPoint(CLpoint* p) override;
    float calculDistance() override;
    void message() override;
};
