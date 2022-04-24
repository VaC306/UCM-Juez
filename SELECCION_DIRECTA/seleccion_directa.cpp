//Rishi Pursnani Mirpuri
//ripursna@ucm.es
//seleccion directa
//visual studio

#include <iostream>
#include <fstream>

const int MAX = 100;

typedef int Lista[MAX];

struct Datos {

    Lista lista;
    int contador = 0;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(Datos &datos) {
    int lugar, numero;

    for (int i = 1; i < datos.contador; i++) {

        numero = datos.lista[i];
        lugar = 0;

        while (numero > datos.lista[lugar]&& lugar < i) {

            lugar++;
        }

        for (int j = i; j > lugar; j--) {

            datos.lista[j] = datos.lista[j-1];

        }

        datos.lista[lugar] = numero;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Datos datos;
    int num;
   
    std::cin >> num;
    while (num!=0){

        datos.lista[datos.contador]=num;
        datos.contador++;
        std::cin >> num;
    }
   
   resolver(datos);
   
   for (int i = 0; i < datos.contador; i++) {

       std::cout << datos.lista[i]<< " ";
   }
   std::cout <<"\n";
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out");
   auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
   int num;
   std::cin >> num;
   for (int i = 0; i < num; i++) {

       (resuelveCaso());
   }
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
   system("PAUSE");
#endif
   return 0;
}
