#include <iostream>
#include "rlutil.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>
# include <locale.h>
#include "funciones.h"
using namespace std;




int main()
{
    //setlocale(LC_ALL, "spanish"); //Seteo el lenguaje de la consola.
    setlocale(LC_ALL, "Spanish"); //Seteo el lenguaje de la consola.
    //SetConsoleOutputCP(CP_UTF8) ;

    srand (time(NULL)); //Planto la semilla del random


// Menu
    int opcion;

    do
    {
        system("cls");
        mostrarMenu();


        rlutil::locate(30,10);
        cout << "¿Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        string jug1,jug2; //defino variables para los nombres

        switch(opcion)
        {
        case 1:
            system("cls");
            cout << "selecciono la opcion JUGAR" << endl;
            //nombres_jugadores(jug1,jug2); // hacer el ingreso de los nombres

            // hacer funcion jugar
            jugar();

            //determinarInicio(jug1,jug2);
            //tirada_de_dado(jug1, jug2);

            break;
        case 2:
            cout << "selecciono la opcion ESTADISTICAS" << endl;

            break;
        case 3:
            creditos();
            // hacer funcion de creditos
            cout << "selecciono la opcion CREDITOS" << endl;
            break;

        case 0:
            system("cls");
             if ( confirmarSalida()) {
            cout << "USTED HA SALIDO DEL JUEGO " << endl ;
            return 0; }
            break;
        default:
            cout << "No ingreso una opcion valida" << endl;
            break;
        }
        system("pause");



    }

    while(true);



    return 0;
}
