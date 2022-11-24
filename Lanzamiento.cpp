/* David Grisales Posada
 * Universidad EAFIT 2022*/
#include <iostream>
#include "Lanzamiento.h"
#include "parcial2.h"
#define grav 9.81
using namespace std;
Lanzamiento::Lanzamiento(){
    float temp=0;
    int ang=0;
    int vel=0;
    while (temp>=126 || temp <=49){
    ang=aleatorio(0,85);
    vel=aleatorio(25,55);
    temp=this->getDistancia(vel,ang);
    }
    temp=(int)(temp*100);
    this->distance=temp/100;
    this->angulo=ang;
    this->velocidad=(round(vel*100))/100;
}
float Lanzamiento::getDistancia(int velocidad, int angulo){
	float variable=((velocidad*velocidad)/grav)*seno(2*angulo);
	return variable;
}
string Lanzamiento::toString(){
	string temp=std::to_string(this->distance);
	string cadena="\nSiguiente lanzamiento\n"
				"---------------------\n"
				"Velocidad inicial: "+std::to_string(this->velocidad)+
				"\nÁngulo: "+std::to_string(this->angulo)+
				"°\nDistancia: "+temp.substr(0, temp.find(".")+3)+
				"\n---------------------";
	return cadena;
}
void Lanzamiento::imprimirLista(){
	Lanzamiento* current=this;
	while (current){
		cout<<current->toString();
		current=current->siguiente;
	}
}
void Lanzamiento::siguienteLanzamiento(Lanzamiento* lanzamiento){
	Lanzamiento* current=this;
    while (current->siguiente){
    	current=current->siguiente;
    }
    current->siguiente=lanzamiento;

}
Lanzamiento::~Lanzamiento(){
}
void Lanzamiento::deletearObjetos(){
	if (this){
		this->siguiente->deletearObjetos();
		delete this;
	}
}

int main(){
Lanzamiento* objeto1=new Lanzamiento();
Lanzamiento* nuevo;
for (int i=1;i<10;i++){
	nuevo=new Lanzamiento();
	objeto1->siguienteLanzamiento(nuevo);
}
objeto1->imprimirLista();
cout<<"\nEstos objetos se autodestruirán en 3, 2, 1..."<<endl;
cout<<"Boom!!!";
objeto1->deletearObjetos();
cout<<"\nLos objetos se autodestruyeron.";
}
/*Al programar el código pude darme cuenta que conforme la máquina se ejecute se harán cada vez más lentos sus disparos,
 * como posible solución para esto sugiero que cada cierta creación de objetos (podría ser incluso un solo objeto) la máquina
 * elimine sus objetos de la memoria, para que así la lista enlazada no tarde demasiado en agregar los nuevos objetos
 *  (teniendo en cuenta que su complejidad es lineal).
 *
 *  Además de eso noté que el programa creaba objetos con los mismos datos a la hora de ejecutarlos, me atrevería a pensar
 *  que se debe al método time empleado en el archivo parcial2.h.
 */
