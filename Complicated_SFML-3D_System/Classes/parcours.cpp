#include "parcours.h"
#include <iostream>
#include <cmath>

using namespace std;



CLparcours2D::CLparcours2D(int taille)
{
    tailleMax = taille;
    index = 0;
    tab = new CLpoint*[tailleMax];
}

void CLparcours2D::ajouterPoint(CLpoint* p)
{
    if (index < tailleMax)
    {
        tab[index++] = p;
    }
}

float CLparcours2D::calculDistance()
{
    float d = 0.0f;

    for (int i = 0; i < index - 1; i++)
    {
        float dx = tab[i+1]->getX() - tab[i]->getX();
        float dy = tab[i+1]->getY() - tab[i]->getY();
        d += sqrt(dx * dx + dy * dy);
    }

    return d;
}

void CLparcours2D::message()
{
    cout << "Parcours 2D contenant " << index << " points." << endl;
}



CLparcours3D::CLparcours3D(int taille)
{
    tailleMax = taille;
    index = 0;
    tab = new CLpoint*[tailleMax];
}

void CLparcours3D::ajouterPoint(CLpoint* p)
{
    if (index < tailleMax)
    {
        tab[index++] = p;
    }
}

float CLparcours3D::calculDistance()
{
    float d = 0.0f;

    for (int i = 0; i < index - 1; i++)
    {
        float dx = tab[i+1]->getX() - tab[i]->getX();
        float dy = tab[i+1]->getY() - tab[i]->getY();

        // Cast only if the point is actually 3D
        CLpoint3D* a = dynamic_cast<CLpoint3D*>(tab[i]);
        CLpoint3D* b = dynamic_cast<CLpoint3D*>(tab[i+1]);

        if (a && b)
        {
            float dz = b->getZ() - a->getZ();
            d += sqrt(dx * dx + dy * dy + dz * dz);
        }
        else
        {
            // fallback if one point is 2D
            d += sqrt(dx * dx + dy * dy);
        }
    }

    return d;
}

void CLparcours3D::message()
{
    cout << "Parcours 3D contenant " << index << " points." << endl;
}
