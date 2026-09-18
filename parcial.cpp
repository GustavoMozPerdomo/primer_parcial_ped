#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct PuntoTrayectoria {
    int identificador;
    string nombreDescripcion;
    double coordenadas[3];
    double distanciaOrigen;
    string clasificacion;
};
int numPuntos;

void registrarPunto(PuntoTrayectoria &punto) {
    cout << "Ingrese identificador: ";
    cin >> punto.identificador;
    cout << "Ingrese nombre o descripcion: ";
    cin.ignore();
    getline(cin, punto.nombreDescripcion);
    cout<<"Ingresar coordenada X:";
    cin>> punto.coordenadas[0];
    cout<<"Ingresar coordenadas en Y:";
    cin>> punto.coordenadas[1];
    cout<<"Ingresar coordenadas en Z:";
    cin>> punto.coordenadas[2];
}
float calcularDistancia(PuntoTrayectoria *punto){
    float distancia;

    distancia = sqrt(((*punto).coordenadas[0] * (*punto).coordenadas[0]) +((*punto).coordenadas[1] * (*punto).coordenadas[1]) +((*punto).coordenadas[2] * (*punto).coordenadas[2]));

    (*punto).distanciaOrigen = distancia;

    return distancia;
}
void clasificarPunto(PuntoTrayectoria &punto){
    if(punto.distanciaOrigen <= 5){
        punto.clasificacion = "CERCANO";
    } else if(punto.distanciaOrigen <=10){
        punto.clasificacion = "INTERMEDIO";
    } else if(punto.distanciaOrigen<= 20){
        punto.clasificacion = "LEJANO";
    } else {
        punto.clasificacion = "EXTREMO";
      
    }
}
PuntoTrayectoria* obtenerPuntoMasAlejado(PuntoTrayectoria puntos[], int cantidad) {
    PuntoTrayectoria *puntoMasAlejado = &puntos[0];

    for (int i = 1; i < cantidad; i++) {
        if (puntos[i].distanciaOrigen > (*puntoMasAlejado).distanciaOrigen) {
            puntoMasAlejado = &puntos[i];
        }
    }

    return puntoMasAlejado;
}
int main() {
    PuntoTrayectoria puntos[10];
    PuntoTrayectoria *punteroPunto;
    cout << "Ingrese el numero de puntos: ";
    cin >> numPuntos;
    for (int i = 0; i < numPuntos; i++) {
        registrarPunto(puntos[i]);
    }

    punteroPunto = puntos;

    for (int i = 0; i < numPuntos; i++) {
        cout << "Distancia al origen: " << calcularDistancia(punteroPunto) << endl;
        clasificarPunto(*punteroPunto);
        cout << "Clasificacion: " << (*punteroPunto).clasificacion << endl;
        punteroPunto++;
    }

    PuntoTrayectoria *puntoMasAlejado = obtenerPuntoMasAlejado(puntos, numPuntos);

    cout << "\n------------------------------" << endl<<"PUNTO MAS ALEJADO"<<endl;
    cout<<"ID: "<<(*puntoMasAlejado).identificador<<endl;
    cout<<"Nombre: "<<(*puntoMasAlejado).nombreDescripcion<<endl;
    cout<<"Coordenada X: "<<(*puntoMasAlejado).coordenadas[0]<<endl;
    cout<<"Coordenada Y: "<<(*puntoMasAlejado).coordenadas[1]<<endl;
    cout<<"Coordenada Z: "<<(*puntoMasAlejado).coordenadas[2]<<endl;
    cout<<"Distancia respecto al origen: "<<(*puntoMasAlejado).distanciaOrigen<<endl;
    cout<<"Clasificacion: "<<(*puntoMasAlejado).clasificacion<<endl;

    return 0;
}
