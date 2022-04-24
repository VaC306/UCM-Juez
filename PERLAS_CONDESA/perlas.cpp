// Rishi Pursnani Mirpuri
// ripursna@ucm.es
// visual studio
// perlas de la condesa

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PERLAS = 1000;

typedef int Lista[MAX_PERLAS];

struct Collar {

    Lista lista;
    bool ok = true;
    int contador = 0;
};

void ordenarPerlas(Collar& datos) {
    int localizacion, num;

    for (int i = 1; i < datos.contador; i++) {
        localizacion = 0;
        num = datos.lista[i];
        

        while (num > datos.lista[localizacion] && localizacion < i) 
        {

            localizacion++;
        }

        for (int j = i; j > localizacion; j--) 
        {

            datos.lista[j] = datos.lista[j - 1];

        }

        datos.lista[localizacion] = num;
    }
}

Collar resolver(Collar datos) {

    if ((datos.contador % 2) == 0) 
    {
        datos.ok = false;
        return datos;
    }
    else 
    {
        ordenarPerlas(datos);
    }

    for (int i = 0; i < datos.contador - 2; i = i+2)
    {

        if (datos.lista[i] != datos.lista[i + 1]) {

            datos.ok = false;
        }
    }
    return datos;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Collar datos;
    int a, num = 0;

    cin >> a;
    while (a != 0) 
    {

        datos.lista[num] = a;
        cin >> a;
        num++;
        datos.contador++;
    }

    if (datos.contador == 0) 
    {

        return false;
    }

    datos = resolver(datos);

    if (!datos.ok) 
    {

        cout << "NO" << endl;
    }

    else {

        for (int i = 0; i < datos.contador - 2; i = i + 2) 
        {

            cout << datos.lista[i] << " ";
        }

        cout << datos.lista[datos.contador - 1] << " ";

        for (int i = datos.contador - 2; i >= 0; i = i - 2) 
        {

            cout << datos.lista[i];

            if (i != 1) {

                cout << " ";
            }
            else {

                cout << endl;
            }
        }

    }

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