#ifndef Lanzamiento_h
#define Lanzamiento_h
#include <string>
using namespace std;
class Lanzamiento
{
private:
    int velocidad;
    int angulo;
    float distance;
    Lanzamiento* siguiente=nullptr;
public:
    Lanzamiento();
    ~Lanzamiento();
    float getDistancia(int,int);
    string toString();
    void siguienteLanzamiento(Lanzamiento*);
    Lanzamiento* getSiguiente(){return this->siguiente;}
    int getVelocidad(){return this->velocidad;}
    void imprimirLista();
    void deletearObjetos();
};

#endif
