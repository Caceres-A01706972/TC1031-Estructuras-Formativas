/*
funciones.h

Alumno: Ricardo Andres Caceres Villibord A01706972
*/

#include <iostream>

using namespace std;

class Funciones{
    
    public:
        Funciones();
        int sumaIterativa(int n);
        int sumaRecursiva(int n);
        int sumaDirecta(int n);

};

Funciones::Funciones(){}


/*  Analisis de Complejidad:

*/
int Funciones::sumaIterativa(int n){
    int resultado = 0;
    for (int i=1; i<=n; i++){
        resultado += i;
    }
    return resultado;
}


/*  Analisis de Complejidad:

*/
int Funciones::sumaRecursiva(int n){
    if (n == 1){
        return 1;
    } else {
        return (n + sumaRecursiva(n-1));
    }
}


/*  Analisis de Complejidad:

*/
int Funciones::sumaDirecta(int n){ 
    return (n*(n+1)/2);
}
