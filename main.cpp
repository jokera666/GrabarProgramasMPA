#include <iostream>
#include <fstream>  // libreria para abrir leer y escribir en fichero
#include <stdlib.h> // rand y system
#include <cstdlib>

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

void InicializarVectorProgramas(float **M, float *V, int n)
{
    int i;
    int j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=1; j++)
        {
            V[i]    = M[i][j];
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


void Intercambiar(float &izq, float &der)
{
    float temp;

    if(izq > der)
    {
        temp = izq;
        izq = der;
        der= temp;
    }
}


void Combinar2(float *V, float *Vaux, int izq, int centro, int der)
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
            i1++;
        }
        else
        {
            Vaux[i] = V[i2];
            i2++;
        }

        i++;
    }

    if(i1 > centro)
    {
        for(j=i; j<=der; j++)
        {
            Vaux[j] = V[i2];
            i2++;
        }
    }
    else
    {
        for(j=i; j<=der; j++)
        {
            Vaux[j] = V[i1];
            i1++;
        }
    }

    for(j=izq; j<=der; j++)
    {
        V[j] = Vaux[j];
    }

}



//El vector se ordenara de menor a mayor mediante el algoritmo: Mergesort 2
void OrdenarVectorProgramas(float *V, float *Vaux, int izq, int der)
{
    int centro;

    if((der-izq+1) <= 2) // "<=" en caso de que el vector es de tama�o impar
    {
        Intercambiar(V[izq],V[der]);
    }

    else
    {
        centro = (izq + der) / 2;
        OrdenarVectorProgramas(V, Vaux, izq, centro);
        OrdenarVectorProgramas(V, Vaux, centro+1, der);
        Combinar2(V, Vaux, izq, centro, der);
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

void ImprimirProgramas(float *V, int *Vposiciones, int n, int option)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(option==1)
        {
            //(char)167 De esta manera se escriben los caracteres ASCII
            // segun el numero de caracter. En este caso 167 es '�' para la numeraci�n
            cout<<"\tPrograma n"<<(char)167<<" "<<i<<" de capacidad "<<V[i]<<"GB"<<endl;
        }
        else if(option==3)
        {
            //(char)167 De esta manera se escriben los caracteres ASCII
            // segun el numero de caracter. En este caso 167 es '�' para la numeraci�n
            cout<<"\tPrograma n"<<(char)167<<" "<<Vposiciones[i]<<" de capacidad "<<V[i]<<"GB"<<endl;
        }

    }
    cout<<endl;
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

    if(espacioLibre==0)
    {
        cout<<"No hay espacio libre en la memoria."<<endl;
    }
    else
    {
        cout<<"El espacio libre en la memoria es: "<<espacioLibre<<" GB."<<endl;
        while( ( suma<=espacioLibre ) && ( aux<=n ) )
        {
            x = VPP[aux];
            cout<<" x: "<<x<<endl;
            suma = suma + x;
            cout<<"suma es: "<<suma<<endl;
            if(suma<=espacioLibre)
            {
                //cout<<"aux2 in: "<<aux2<<endl;
                cout<<"Entrooo---->"<<endl<<endl;
                Vsolucion[aux2] = x;
                aux2++;
            }
        //cout<<"aux: "<<aux<<endl;
        aux++;

        }
        ImprimirVector(Vsolucion,n);
    }


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
    float **getFichero;
    float *vectorPesosProgramas;
    float *auxVectorPesosProgramas;
    int *VectorPosiciones;
    float *Vsolucion;

    //variables necesarias para el Mergesort 2
    int izq = 1;
    int der = 5;

    // vector necesario para el Mergesort 2
    float *auxVectorProgramas;



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
                    InicializarVectorProgramas(getFichero,vectorPesosProgramas,numProgramas);
                    ImprimirProgramas(vectorPesosProgramas,VectorPosiciones,numProgramas,1);

                    //ImprimirVector(vectorPesosProgramas,numProgramas);
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
                    auxVectorPesosProgramas = ReservarMemoriaVector(numProgramas);
                    auxVectorProgramas      = ReservarMemoriaVector(numProgramas);
                    Vsolucion               = ReservarMemoriaVector(numProgramas);

                    InicializarVectorProgramas(getFichero,vectorPesosProgramas,numProgramas);
                    InicializarVector(Vsolucion,numProgramas);

                    //auxVectorPesosProgramas es para sacar el orden de los programas
                    InicializarVectorProgramas(getFichero,auxVectorPesosProgramas,numProgramas);
                    ImprimirProgramas(vectorPesosProgramas,VectorPosiciones,numProgramas,1);
                    cout<<endl;

                    OrdenarVectorProgramas(vectorPesosProgramas, auxVectorProgramas,izq,der);

                    VectorPosiciones = ReservarMemoriaVectorInt(numProgramas);
                    VectorPosiciones = PosicionesProgramas(vectorPesosProgramas,auxVectorPesosProgramas,numProgramas);


                    ImprimirProgramas(vectorPesosProgramas,VectorPosiciones,numProgramas,3);

                    MaxNumProgramas(vectorPesosProgramas,Vsolucion,tamUsb,numProgramas);
                    //ImprimirVector(Vsolucion,numProgramas);
                    cout<<endl;
                    //ImprimirProgramas(auxVectorPesosProgramas,numProgramas);
                    cout<<endl;
                   // ImprimirVector(VectorPosiciones,numProgramas);


                    //cout<<"tam 3:"<<tamUsb<<endl;
                    pausa();
                break;

                case '4':
                    system("CLS");
                    //LiberarMemoria(getFichero,vectorPesosProgramas);
                    cout<<endl;
                    cout<<"\t\t     ---> 4.- Grabar maximo capacidad <--- "<<endl<<endl;
                    cout<<"tam 4: "<<tamUsb<<endl;
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
