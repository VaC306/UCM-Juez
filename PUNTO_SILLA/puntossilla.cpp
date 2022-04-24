// Rishi Pursnani Mirpuri
// ripursna@ucm.es
// Visual studio code
// puntos silla

#include <iostream>
#include <fstream> 
#include<string>

const int MAXFC = 100;
typedef int tMatriz [MAXFC][MAXFC];

struct Datos
{
    tMatriz matriz;
    int f;
    int c;
    int max = 0;
    int min = 0;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resolver( Datos& datos);
bool mayorFila(Datos& datos, int fila);
int mayorColumna(Datos& datos, int columna);
bool menorFila(Datos& datos, int fila);
int menorColumna(Datos& datos, int columna);


bool resuelveCaso() {
   Datos datos;
   // leer los datos de la entrada
   
    std::cin>>datos.f>>datos.c;
   if (datos.f == 0 && datos.c == 0)  // fin de la entrada
      return false;
    for(int i = 0; i < datos.f; i++)
    {
        for(int j = 0; j < datos.c; j++)
        {
            std::cin>>datos.matriz[i][j];
        }
    }
   
    bool ok = resolver(datos);
   
   // escribir sol
   if(!ok)
   {
       std::cout<<"NO"<<"\n";
   }
   else
   {
       std::cout<<"SI"<<"\n";
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

bool resolver( Datos& datos) {
    
   bool resultado=false;
   int contador=0;

   while(!resultado && contador<datos.f){

      if (mayorFila(datos, contador) ||  menorFila(datos, contador)){

         resultado=true;
         return resultado;
      }
      contador++;
   }

   return resultado;
}

bool mayorFila(Datos& datos, int fila){
   int maxFilas=datos.matriz[fila][0];
   int minColumnas=-99999;
   bool resultado=false;

   for(int i=0; i<datos.c; i++){

      if(datos.matriz[fila][i]>=maxFilas){
         
         if(datos.matriz[fila][i]>maxFilas){

            resultado=false;
            maxFilas=datos.matriz[fila][i];
         }

         minColumnas =menorColumna(datos, i);

         if(minColumnas==maxFilas){

            resultado=true;
         }
      }
   }
   return resultado;
}

bool menorFila(Datos& datos, int fila){
   int minFilas=datos.matriz[fila][0] ;
   int maxColumnas=-99999;
   bool resultado=false;

   for(int i=0; i<datos.c; i++){

      if(datos.matriz[fila][i]<=minFilas){
         
         if(datos.matriz[fila][i]<minFilas){
            
            resultado=false;
            minFilas=datos.matriz[fila][i];
         }

         maxColumnas =mayorColumna(datos, i);

         if(minFilas==maxColumnas){

            resultado=true;
         }
      }
   }
   return resultado;
}


int mayorColumna(Datos& datos, int columna){
   int max=datos.matriz[0][columna];

   for(int i=0; i<datos.f; i++){

      if(datos.matriz[i][columna]>max){

         max=datos.matriz[i][columna];
      }
   }
   return max;
}

int menorColumna(Datos& datos, int columna){
   int min=datos.matriz[0][columna];

   for(int i=0; i<datos.f; i++){

      if(datos.matriz[i][columna]<min){

         min=datos.matriz[i][columna];
      }
   }
   return min;
}