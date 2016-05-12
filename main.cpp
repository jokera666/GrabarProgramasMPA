#include <iostream>
#include <fstream>  // libreria para abrir leer y escribir en fichero
#include <stdlib.h> // rand y system

using namespace std;

float** ReservarMemoriaMatriz(int n)
{
    float **matrizAux = new float*[n+1];
    for(int i=1; i<=n; i++)
    {
        matrizAux[i] = new float[n+1];
    }
    return matrizAux;
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

void InicializarVectorProgramas(float **M, float *V, int n)
{
    int i;
    int j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=1; j++)
        {
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

void ImprimirProgramas(float *V, int n)
{
    int i;

    for(i=1; i<=n; i++)
    {
        //(char)167 De esta manera se escriben los caracteres ASCII
        // segun el numero de caracter. En este caso 167 es 'º' para la numeración
        cout<<"\tPrograma n"<<(char)167<<" "<<i<<" de capacidad "<<V[i]<<"GB"<<endl;
    }
    cout<<endl;
}

float** LeerFichero(int &tam)
{
   char nombrefichero[50] = "programas.txt";  // nombre del fichero de entrada
   char dato[10];                             // palabra que se lee del fichero
   ifstream f;                                // variable del tipo fichero
   float **matriz;                            // matriz de adyacencia de los programas
   int i,j;

   //cout << "Introduce el nombre del fichero con el grafo: ";
   //cin >> nombrefichero;
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

   matriz = new float* [1];
   for (i=1;i<=tam;i++)
   {
      matriz[i]= new float [tam+1];
   }


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

void LiberarMemoria (float **M, float *V)
{
    delete M;
    delete V;
}

int main()
{

    int opcion;
    int numProgramas;
    float **getFichero;
    float *vectorPesosProgramas;

        do
        {

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

            cin>>opcion;// seleccion de la opcion en la consola

            //comprobar si la opcion es introducida es un numero
            if (cin.fail())
            {
                cin.clear();
                cin.get();
            }

            cin.get();

            switch(opcion)
            {
                case 1:
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
                    ImprimirProgramas(vectorPesosProgramas,numProgramas);
                    //ImprimirVector(vectorPesosProgramas,numProgramas);

                    cout<<"\t\tPulsa la tecla ENTER para volver al menu...";
                    cin.get();
                    system("CLS");
                break;

                case 2:
                    system("CLS");
                    cout<<"Estas en la opcion 2"<<endl;
                    cout<<"\t\tPulsa la tecla ENTER para volver al menu...";
                    cin.get();
                    system("CLS");
                break;

                case 3:
                    system("CLS");
                    cout<<"Estas en la opcion 3"<<endl;
                    cout<<"\t\tPulsa la tecla ENTER para volver al menu...";
                    cin.get();
                    system("CLS");
                break;

                case 4:
                    system("CLS");
                    cout<<"Estas en la opcion 4"<<endl;
                    cout<<"\t\tPulsa la tecla ENTER para volver al menu...";
                    cin.get();
                    system("CLS");
                break;

                case 5:
                    return 1;
                break;

                default:
                    cout<<endl;
                    cout<<"\t\t\t Opcion incorrecta. Vuelva a intentarlo.\a";
                    cin.get();
                    system("CLS");
                break;

            }
        }while(opcion!=5);

    system("PAUSE"); // Para parar el programa ejecutado desde el .EXE
    return 0;
}
