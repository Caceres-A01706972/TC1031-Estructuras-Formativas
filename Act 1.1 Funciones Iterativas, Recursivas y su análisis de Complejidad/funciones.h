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
El ciclo for hace la suma durante n iteraciones, donde n es el valor ingresado,
entonces la variable i va desde 1 hasta n. Con un incremento de 1 en 1. Entonces podemos decir que tiene una complejisdad de O(n).
*/
int Funciones::sumaIterativa(int n){
    int resultado = 0;
    for (int i=1; i<=n; i++){
        resultado += i;
    }
    return resultado;
}


/*  Analisis de Complejidad:
Se llamara a si mismo n veces, donde n es el valor ingresado en la funcion para hacer la suma de los numeros desde n hasta 0. 
Podemos decir que la Complejidad es de O(n).
*/
int Funciones::sumaRecursiva(int n){
    if (n == 1){
        return 1;
    } else {
        return (n + sumaRecursiva(n-1));
    }
}


/*  Analisis de Complejidad:
El analisis de complejidad de este algoritmo es O(1), tiempo constante, porque no recorre ningun ciclo. No importa el valor de n,
siempre va a ser un paso.
*/
int Funciones::sumaDirecta(int n){ 
    return (n*(n+1)/2);
}
