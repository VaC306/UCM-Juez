// Rishi Pursnani Mirpuri
// ripursna@ucm.es
// visual studio code
// sudoku

#include <iostream>
#include <fstream>

const int MAX_CASILLAS = 9;
const int MAX_REGIONES = 3;

typedef int tMatriz[MAX_CASILLAS][MAX_CASILLAS];
typedef int tNumeros[10];

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(tMatriz& matriz) {
   bool ok = false;
   int i = 0;
	int j = 0;
	int a = 0; //las filas del cuadrado
	int b = 0; //las columnas del cuadrado
	tNumeros filas = {0,0,0,0,0,0,0,0,0,0}; // esto se usa para comprobar las filas
	
	//Filas
	while (ok == false && i < MAX_CASILLAS)
	{
		while (ok == false && j < MAX_CASILLAS)
		{
			if (filas[matriz[i][j]] == 1)
			{
				ok = true;
			}
			else
			{
				filas[matriz[i][j]] = 1;
				j++;
			}
		}
		j = 0;
		i++;

		for (int k = 0; k < 10; k++)
		{
			filas[k] = 0;
		}
	}

	i = 0;
	j = 0;

	
	//Columnas
	while (ok == false && i < MAX_CASILLAS)
	{
		while (!ok && j < MAX_CASILLAS)
		{
			if (filas[matriz[j][i]] == 1)
			{
				ok = true;
			}
			else
			{
				filas[matriz[j][i]] = 1;
				j++;
			}
		}
		j = 0;
		i++;

		for (int k = 0; k < 10; k++)
		{
			filas[k] = 0;
		}
	}
	
	i = 0;
	j = 0;
	
	//Cuadrados
	while (ok == false && a < MAX_REGIONES)
	{
		while (ok == false && b < MAX_REGIONES)
		{
			while (ok == false && i < MAX_REGIONES)
			{
				while (ok == false && j < MAX_REGIONES)
				{
					if (filas[matriz[i + (MAX_REGIONES*a)][j + (MAX_REGIONES* b)]] == 1)
					{
						ok = true;
					}
					else
					{
						filas[matriz[i + (MAX_REGIONES * a)][j + (MAX_REGIONES * b)]] = 1;
						j++;
					}
				}
				j = 0;
				i++;
			}
			i = 0;
			b++;

			for (int x = 0; x < 10; x++)
			{
				filas[x] = 0;
			}		
		}
		a++;
	}

	if (ok)
	{
		return false;
	}
	else
	{
		return true;
	}
   return ok;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   tMatriz matriz;
	bool ok;
	for (int i = 0; i < MAX_CASILLAS; i++)//Cargar filas
	{
		for (int j = 0; j < MAX_CASILLAS; j++)
		{
			std::cin >> matriz[i][j];
		}
	}

	
	// Es necesario pasar el número de elementos que contiene la lista
	ok = resolver(matriz);

	if (ok)
	{
		std::cout << "SI" << "\n";
	}
	else
	{
		std::cout << "NO" << "\n";
	}
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("datos.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out");
   auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
   system("PAUSE");
#endif
   return 0;
}
