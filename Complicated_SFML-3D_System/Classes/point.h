#pragma once


class CLpoint
{
protected:
    float x;
    float y;
public:
    CLpoint();
    CLpoint(float x, float y);
    virtual ~CLpoint() = default;
    virtual void afficherCoordo();
    virtual float getX();
    virtual float getY();
};


class CLpoint3D: public CLpoint
{
private:
    float z;
public:
    CLpoint3D();
    CLpoint3D(float x, float y, float z);
    ~CLpoint3D()=default;
    void afficherCoordo() override; 
    float getZ();
};

