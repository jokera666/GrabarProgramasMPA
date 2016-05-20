/*############################################################################
# Nombre de la practica: Grabación de programas								 #
# Realizada por: Nestor Dobrinov Edrev										 #
# Grado: Grado en Ingeniería Informática en Tecnologías de la Información    #
# Asignatura: Metodología de la Programación y Algoritmia	                 #
# Fecha: 12/05/2016														     #
#                                           Universidad Miguel Hernández     #
############################################################################## */

#include <iostream>
#include <fstream>  // libreria para abrir leer y escribir en fichero
#include <stdlib.h> // rand y system
#include <iomanip> //setprecision(3)<<fixed Es para mostrar los decimales en el cout

using namespace std;


int *ReservarMemoriaVectorInt(int n)
{
    int *V = new int[n+1];
    if(V == NULL)
    {
        cout<<"Error al reservar la memoria."<<endl;
        system("PAUSE");
        exit(-1);
    }
    return V;

}


float *ReservarMemoriaVector(int n)
{
    float *V = new float[n+1];
    if(V == NULL)
    {
        cout<<"Error al reservar la memoria."<<endl;
        system("PAUSE");
        exit(-1);
    }
    return V;

}

void ImprimirMatriz(float **M, int n)
{
    int i;
    int j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=1; j++)
        {
            cout<<" "<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void InicializarVector(float *V, int n)
{
    int i;

    for(i=1; i<=n; i++)
    {
        V[i] = 0;
    }
}

void InicializarVectorProgramas(float **M, float *V, int *numV, int n)
{
    int i;
    int j;

    for(i=1; i<=n; i++)
    {
        // Enumeración de los programas
        numV[i] = i;

        for(j=1; j<=1; j++)
        {
            //Pesos de cada uno de los programa
            V[i] = M[i][j];
        }
    }
}

void ImprimirVector(float *V, int n)
{
    int i;

    for(i=1; i<=n; i++)
    {
        cout<<" "<<V[i];
    }
    cout<<endl;
}


void Intercambiar(float &izq, float &der,int &izqI, int &derI)
{
    float temp;
    int tempI;

    if(izq > der)
    {
        temp = izq;
        izq = der;
        der = temp;
    }

    if(izqI > derI)
    {
        tempI = izqI;
        izqI = derI;
        derI = tempI;
    }
}


void Combinar2(float *V, float *Vaux, int *numV, int *numVaux, int izq, int centro, int der)
{
    int i,j, i1, i2;
    i = izq;
    i1 = izq;
    i2 = centro + 1;

    while((i1<=centro) && (i2<=der))
    {
        if(V[i1]<V[i2])
        {
            Vaux[i] = V[i1];
            numVaux[i] = numV[i1];
            i1++;
        }
        else
        {
            Vaux[i] = V[i2];
            numVaux[i] = numV[i2];
            i2++;
        }

        i++;
    }

    if(i1 > centro)
    {
        for(j=i; j<=der; j++)
        {
            Vaux[j] = V[i2];
            numVaux[j] = numV[i2];
            i2++;
        }
    }
    else
    {
        for(j=i; j<=der; j++)
        {
            Vaux[j] = V[i1];
            numVaux[j] = numV[i1];
            i1++;
        }
    }

    for(j=izq; j<=der; j++)
    {
        V[j] = Vaux[j];
        numV[j] = numVaux[j];
    }

}

void InicializarMergesort2(int &izq, int &der, int n)
{
    //izq es el primer elemento del vector
    izq = 1;
    //derecha es el ultimo elemento del vector
    der = n; // tamaño del problema
}


//El vector se ordenara de menor a mayor mediante el algoritmo: Mergesort 2
void OrdenarVectorProgramas(float *V, float *Vaux, int *numV, int *numVaux, int izq, int der)
{
    int centro;

    if((der-izq+1) <= 2) // "<=" en caso de que el vector es de tamaño impar
    {
        Intercambiar(V[izq],V[der],numV[izq],numV[der]);
    }

    else
    {
        centro = (izq + der) / 2;
        OrdenarVectorProgramas(V, Vaux, numV, numVaux, izq, centro);
        OrdenarVectorProgramas(V, Vaux, numV, numVaux, centro+1, der);
        Combinar2(V, Vaux, numV, numVaux, izq, centro, der);
    }
}

// vector ordenado , vector desordenado
int *PosicionesProgramas(float *VPP, float *AVPP, int n)
{
    int i,j;
    int *vAux;
    vAux = ReservarMemoriaVectorInt(n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(VPP[i] == AVPP[j])
            {
                vAux[i] = j;
            }
        }
    }
    return vAux;
}

void ImprimirProgramas(float *V, int *numV, int n)
{
    int i;
    int totalProgramas=0;

    for(i=1; i<=n; i++)
    {
        //(char)167 De esta manera se escriben los caracteres ASCII
        // segun el numero de caracter. En este caso 167 es 'º' para la numeración
        if(V[i]!=0)
        {
            cout<<"\tPrograma n"<<(char)167<<" "<<numV[i]<<" de capacidad "<<V[i]<<"GB."<<endl;
            totalProgramas++;
        }
    }
    cout<<endl;
    cout<<"\tNumero total de programas: "<<totalProgramas<<endl<<endl;
}


//Para 1 columna y 5 filas
float** ReservarMemoriaMatriz(int n)
{
    float **matrizAux = new float*[1];
    for(int i=1; i<=n; i++)
    {
        matrizAux[i] = new float[n];
    }
    return matrizAux;
}


float** LeerFichero(int &tam)
{
   char nombrefichero[50] = "programas.txt";  // nombre del fichero de entrada
   //char nombrefichero[50];  // nombre del fichero de entrada
   char dato[10];                             // palabra que se lee del fichero
   ifstream f;                                // variable del tipo fichero
   float **matriz;                            // matriz de adyacencia de los programas
   int i,j;

   //cout << "Introduce el nombre del fichero con el grafo: ";
   //cin >> nombrefichero;
   //cin.get();
   cout<<endl;
   f.open(nombrefichero);
   if (!f)
   {
      cout << "Fallo al abrir el fichero " << nombrefichero << endl;
      cout << "Verifique la ruta de acceso y el nombre." << endl;
      tam = 0;
      return (NULL);
   }
   f >> tam;                 // leemos el tamanyo del grafo (n vertices)
                             //es la primera linea del fichero
                             // reservamos memoria

//   matriz = new float* [1];
//   for (i=1;i<=tam;i++)
//   {
//      matriz[i]= new float [tam+1];
//   }
   matriz = ReservarMemoriaMatriz(tam);


                             // leemos la matriz
    for (i=1; i<=tam; i++)
    {
      for (j=1; j <=1 ; j++)
      {
        f >> dato;
        matriz[i][j] = atof(dato);
      }
    }


   if (!f)
   {
      cout << "Fallo en la lectura del fichero " << nombrefichero << endl;
      cout << "Verifique el contenido del fichero." << endl;
      tam = 0;
      return (NULL);
   }

   return (matriz);
}

void MaxNumProgramas(float *VPP, float *Vsolucion, float espacioLibre, int n)
{
    float suma = 0;
    float x = 0;
    int aux = 1;
    int aux2 = 1;
    float espacioLibrePrecision = 0;
    float precision = 0.00001;

    //Variable de precision para compara los numeros con coma flotante (float, double)
    espacioLibrePrecision = espacioLibre + precision;

    if(espacioLibre==0)
    {
        cout<<"\t\tNo hay espacio libre en la memoria."<<endl<<endl;
    }
    else
    {

        while( suma<=espacioLibrePrecision && aux<=n  )
        {
            x = VPP[aux];
            //cout<<" x: "<<x<<endl;
            suma = suma + x;
            //cout<<"suma es: "<<suma<<endl;
            if(suma<=espacioLibrePrecision)
            {
                Vsolucion[aux2] = x;
                aux2++;
            }
        aux++;

        }
    }


}

void CalcularEspacio(float *V, int n, float espacioLibre)
{
    int i;
    float espacioOcupado = 0;

    float espacioLibrePrecision = 0;
    float precision = 0.00001;

    //Variable de precision para compara los numeros con coma flotante (float, double)
    espacioLibrePrecision = espacioLibre + precision;


    for(i=1; i<=n; i++)
    {
        espacioOcupado = espacioOcupado + V[i];
    }
    espacioOcupado = espacioOcupado + precision;
    cout<<setprecision(2)<<fixed<<"\tEl espacio ocupado en la memoria es de: "<<espacioOcupado<<" GB."<<endl<<endl;
    cout<<setprecision(2)<<fixed<<"\tEl espacio libre en la memoria es de: "<<espacioLibrePrecision-espacioOcupado<<" GB."<<endl;
}

void LiberarMemoria (float **M, float *V)
{
    delete[] M;
    delete[] V;
}

void pausa()
{
    cout<<"\t\tPulsa la tecla ENTER para volver al menu...";
    cin.get();
}
int main()
{

    char opcion;
    int numProgramas;
    float tamUsb = 0;

    float   **getFichero;
    float   *vectorPesosProgramas;
    int     *numeracionProgramas;
    float   *Vsolucion;

    //variables necesarias para el Mergesort 2
    int izq;// el primer elemento del vector
    int der; // ultimo elemento del vector

    // vector necesario para el Mergesort 2
    float   *auxVectorProgramas;
    int     *auxNumeracionProgramas;



        do
        {

            system("CLS");
            //cin.clear();
            //fflush( stdin ); //Borrar el buffer

            cout<<"\t\t\t     ---> GRABACION DE PROGRAMAS <--- "<<endl<<endl;

            cout<<"\t\t#########################################################"<<endl;
            cout<<"\t\t#                                                       #"<<endl;
            cout<<"\t\t#        1.- Obtener lista de programas.                #"<<endl;
            cout<<"\t\t#        2.- Capacidad disponible en la memoria.        #"<<endl;
            cout<<"\t\t#        3.- Grabar maximo numero de programas.         #"<<endl;
            cout<<"\t\t#        4.- Grabar maximo de capacidad.                #"<<endl;
            cout<<"\t\t#        5.- Salir.                                     #"<<endl;
            cout<<"\t\t#                                                       #"<<endl;
            cout<<"\t\t#########################################################"<<endl<<endl;

            cout<<"\t\tIntroduce tu opcion: ";

            cin>>opcion;
            cin.get();

            switch(opcion)
            {
                case '1':
                    system("CLS");
                    // Hay que liberar memoria despues de cada opcion papra que al volver
                    //a entrar en ella otra vez se quede colgado el programa. Porque nada mas
                    //entrar en la opcion estamos reservando memoria.
                    LiberarMemoria(getFichero,vectorPesosProgramas);
                    cout<<endl;
                    cout<<"\t\t     ---> 1.- Obtener lista de programas. <--- "<<endl<<endl;


                    getFichero = LeerFichero(numProgramas);
                    if (getFichero == NULL)
                    {
                        cout << "Fallo en la lectura del fichero." << endl;
                        system("PAUSE");
                        return -1;
                    }

                    vectorPesosProgramas = ReservarMemoriaVector(numProgramas);
                    numeracionProgramas  = ReservarMemoriaVectorInt(numProgramas);
                    InicializarVectorProgramas(getFichero,vectorPesosProgramas,numeracionProgramas,numProgramas);
                    ImprimirProgramas(vectorPesosProgramas,numeracionProgramas,numProgramas);
                    pausa();
                break;

                case '2':

                    system("CLS");
                    LiberarMemoria(getFichero,vectorPesosProgramas);
                    cout<<endl;
                    cout<<"\t\t     ---> 2.- Capacidad disponible de la memoria <--- "<<endl<<endl;
                    cout<<"Introduce la capacidad disponible de la memoria USB:  ";
                    cin>>tamUsb;
                    cout<<endl;
                    cin.get();

                    pausa();
                break;

                case '3':
                    system("CLS");

                    LiberarMemoria(getFichero,vectorPesosProgramas);

                    cout<<endl;
                    cout<<"\t\t     ---> 3.- Grabar maximo numero de programas <--- "<<endl<<endl;

                    getFichero = LeerFichero(numProgramas);
                    if (getFichero == NULL)
                    {
                        cout << "Fallo en la lectura del fichero." << endl;
                        system("PAUSE");
                        return -1;
                    }


                    vectorPesosProgramas    = ReservarMemoriaVector(numProgramas);
                    auxVectorProgramas      = ReservarMemoriaVector(numProgramas);
                    numeracionProgramas     = ReservarMemoriaVectorInt(numProgramas);
                    auxNumeracionProgramas  = ReservarMemoriaVectorInt(numProgramas);


                    InicializarVectorProgramas(getFichero,vectorPesosProgramas,numeracionProgramas,numProgramas);

                    InicializarMergesort2(izq,der,numProgramas);
                    OrdenarVectorProgramas(vectorPesosProgramas, auxVectorProgramas,numeracionProgramas,auxNumeracionProgramas,izq,der);

                    /*Al descomentar la siguiente linea se mostraran todos los programas ordenados con su numeracion correspondiente*/
                    //ImprimirProgramas(vectorPesosProgramas,numeracionProgramas,numProgramas);

                    Vsolucion = ReservarMemoriaVector(numProgramas);
                    InicializarVector(Vsolucion,numProgramas);
                    MaxNumProgramas(vectorPesosProgramas,Vsolucion,tamUsb,numProgramas);

                    cout<<"\tLos programas insertados en la memoria con espacio libre de "<<tamUsb<<" GB son:"<<endl<<endl;
                    ImprimirProgramas(Vsolucion,numeracionProgramas,numProgramas);
                    CalcularEspacio(Vsolucion,numProgramas,tamUsb);
                    cout<<endl;
                    pausa();
                break;

                case '4':
                    system("CLS");
                    LiberarMemoria(getFichero,vectorPesosProgramas);
                    cout<<endl;
                    cout<<"\t\t     ---> 4.- Grabar maximo capacidad <--- "<<endl<<endl;
                    cout<<"\t\t !!! ESTE APARTADO AUN ESTA EN OBRAS !!!\a"<<endl<<endl;
                    pausa();
                break;

                case '5':
                    cout<<endl;
                    cout<<"\t\tAdios. Nos vemos en la proxima. :]"<<endl;
                    return 1;
                break;

                default:
                    cout<<endl;
                    cout<<"\t\t\t Opcion incorrecta. Vuelva a intentarlo.\a";
                    cin.get();
                break;

            }
        }while(opcion!='5');


    //system("PAUSE"); // Para parar el programa ejecutado desde el .EXE

    return 0;
}
