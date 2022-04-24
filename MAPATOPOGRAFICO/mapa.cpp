// Autor/a: Rishi Pursnani Mirpuri
// email: ripursna@ucm.es
// Visual Studio
// Máxima cota de un mapa topográfico

#include <iostream>
#include <fstream>

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

typedef int tMatriz[MAX_FILAS][MAX_COLUMNAS];

struct Solucion
{
    int max = -9999;
    int posx = 0;
    int posy = 0;
};

struct Datos
{
    tMatriz matriz;
    Solucion msol;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
Solucion resolver(Datos& datos, int& filas, int& columnas) {
    Solucion sol;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (datos.matriz[i][j] > datos.msol.max)
            {
                datos.msol.max = datos.matriz[i][j];
                datos.msol.posx = i;
                datos.msol.posy = j;
            }

        }
    }

    return datos.msol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Datos datos;
    int filas, columnas;
    // leer los datos de la entrada
    std::cin >> filas;
    std::cin >> columnas;


    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            std::cin >> datos.matriz[i][j];
        }
    }
    if (!std::cin)
    {
        // fin de la entrada
        return false;
    }
    Solucion sol = resolver(datos, filas, columnas);

    // escribir sol
    std::cout << datos.msol.max << " " << datos.msol.posx << " " << datos.msol.posy << "\n";
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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}