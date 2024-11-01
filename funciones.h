#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;


void mostrarMenu();
void nombres_jugadores(string &jug1, string &jug2); // funcion para guardar el nombre de los jugadores
int lanzarDado(); // funcion para que nos de el dado aleatorio.
int determinarInicio(string &jug1, string &jug2); // funcion para saber que jugador arranca el juego
void tirada_de_dado (string &jug1, string &jug2);//determinar los 3 dados
void partida();
void creditos();
void jugar ();
void jugarronda(string nombreJugador, int numRonda);


void mostrarMenu()
{
    rlutil::setBackgroundColor(rlutil::YELLOW);//CAMBIAR EL COLOR DEL FONDO
    rlutil::setColor(rlutil::BLACK); //CAMBIAR EL COLOR DE LAS LETRAS

    rlutil:: cls();
    rlutil::locate(30,10); // (filas, columnas)
    cout << "BONZO" << endl;
    rlutil::locate(30,12);
    cout << "1 - JUGAR" << endl;
    rlutil::locate(30,13);
    cout << "2 - ESTADISTICAS" << endl;
    rlutil::locate(30,14);
    cout << "3 - CREDITOS" << endl;
    rlutil::locate(30,16);
    cout << "0 - Salir" << endl;



}

void nombres_jugadores(string &jug1, string &jug2)
{
    char opc;
    do
    {

        cout<< endl;
        cout<< " -----------------------------------------" <<endl;
        cout<< "!              BONZO                      !" <<endl;
        cout<< "!-----------------------------------------!" <<endl;
        cout<< "!                                         !" <<endl;
        cout<< "!     REGISTREN SUS NOMBRES POR FAVOR:    !" <<endl;
        cout<< "!                                         !" <<endl;
        cout<< " -----------------------------------------" <<endl;
        cout<< "          ¿NOMBRE DEL JUGADOR 1? ";
        cin>> jug1;
        cout<< endl;
        cout<< endl;
        cout<< "          ¿NOMBRE DEL JUGADOR 2? ";
        cin>> jug2;
        cout<< endl;
        cout<< " ----------------------------------------" <<endl;
        cout<< "!        ¿CONFIRMAR NOMBRES? (S/N)       " <<endl;
        cout<< " ----------------------------------------" <<endl;
        cout<< endl;
        cout<< "               ELECCIÓN:";
        cin>> opc;
        cout<< endl;

        if (opc == 'N' || opc == 'n')
        {
            cout << "POR FAVOR, INGRESE NUEVAMENTE LOS NOMBRES." << endl;
        }

        if (opc !='N'|| opc!='n'&& opc !='S' || opc!='s' )   {

            cout<<"por favor ingrese S/N"<<endl;
            system ("cls");
        }
    }
    while (opc != 'S' && opc != 's');




}
void jugar ()
{
    int jugador_inicial;
    string jug1;
    string jug2;
    nombres_jugadores(jug1, jug2);  //llamamos a la funcion para q muestre los nombres y las guarde en las variables
    jugador_inicial=determinarInicio(jug1, jug2) ;  //a a ir a det incio y hace el calculo de quien va a empezar para no mostrar los dados inicialmente

    for (int ronda=1; ronda<=6 ; ronda++ )
    {
        if (jugador_inicial==1)  // no pongo jug1 xq si se llaman iguals llamaria al mismo nombre
        {


            // sera void xe va aretornar puntuacion cantidad  de bonificaciones, penalizaciones de dados q iran por referencia entonces retornaria muchas cosaas
            //aca solamente se llama a jugar ronda con nombre de jugador y con num d ronda
            jugarronda(jug1,ronda);
            jugarronda(jug2,ronda);
        }
        else
        {
            jugarronda(jug2,ronda);
            jugarronda(jug1,ronda);
        }
    }

}
void jugarronda(string nombreJugador, int numRonda)
{
    bool banderacontinuarjugando=1;
    string respuesta;
    cout<<"es turno de "<<   nombreJugador<<" en la ronda: "  <<   numRonda<<endl;
    lanzarDado ();  //llamo a lanzar dado para q m e un num del 1 al 6 aleatorio

    while (banderacontinuarjugando)
    {

        int dados [3]  ;
        dados[0]= lanzarDado();//va  a devolver los 3 dados y los guarda
        dados[1] = lanzarDado();
        dados[2]= lanzarDado() ;
        cout<<" dados 1 es "<<dados[0] << " dado 2 es "<<dados[1] <<" dado3 es "<<dados[2]  << endl;

        cout<<" ¿quieres seguir lanzando los dados ?"<<endl;
        cin>>respuesta;
        if  (respuesta == "n"){
               banderacontinuarjugando=false;
        }
    }

}

int lanzarDado()
{
    int dado = rand()%6+1;

    return dado;

}

int determinarInicio(string &jug1, string &jug2)
{

    int numero_dado = lanzarDado(); // guardo el valor del dado aleatorio dentro de la variable;


    if(numero_dado % 2 !=0 )
    {
        cout << endl << "Comienza el Jugador n°1 " << jug1 << endl << "el numero de dado que salio es " << numero_dado << endl;
        return 1;
    }
    else
    {
        cout << endl << "Comienza el Jugador n°2 " << jug2 << endl << "el numero de dado que salio es " << numero_dado << endl;
        return 2;
    }
}
//void partida ()
//{
//    tirada_de_dado(int &dado1_jugador1, int &dado2_jugador1, int &dado3_jugador1, int &dado1_jugador2, int &dado2_jugador2, int &dado3_jugador2);
//}




int tirada_de_dado ()
{
    string jug1,jug2;
    int dados[3];  //dados es el vector que voy a retornar

    dados[0] = lanzarDado();   //el vector se va allenar con 3 num aleatorios
    dados[1] = lanzarDado();
    dados[2]=lanzarDado() ;



    cout << endl << "Jugador 1: " << jug1<< endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Dado 1 -> " << dados[0] << endl << "Dado 2 -> " << dados[1] << endl << "Dado  3-> " << dados[2] << endl;
    cout << "---------------------------------------------------" << endl << endl << endl;


    //Jugador 2
    int dado1_jugador2 = lanzarDado();
    int dado2_jugador2 = lanzarDado();
    int dado3_jugador2=lanzarDado() ;

    cout << endl << "Jugador 2: " << jug2<< endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Dado 1 -> " << dado1_jugador2 << endl << "Dado 2 -> " << dado2_jugador2 << endl << "Dado  3-> " << dado3_jugador2 << endl;
    cout << "---------------------------------------------------" << endl << endl << endl  ;

}



void creditos()
{
    rlutil:: cls();

    cout<< endl;
    cout<< " -----------------------------------------" <<endl;
    cout<< "!                BONZO                    !" <<endl;
    cout<< "!-----------------------------------------!" <<endl;
    cout<< "!                                         !" <<endl;
    cout<< "!            -----------------            !" <<endl;
    cout<< "!           !    CRÉDITOS     !           !" <<endl;
    cout<< "!            -----------------            !" <<endl;
    cout<< "!                                         !" <<endl;
    cout<< "!    ---------------------------------    !" <<endl;
    cout<< "!   !   NOMBRE ! APELLIDO  ! LEGAJO   !   !" <<endl;
    cout<< "!   !---------------------------------!   !" <<endl;
    cout<< "!   !   TANIA  ! ALVEZ OLIVERA !30209 !   !" <<endl;
    cout<< "!   !   CINTYA ! RODRIGUEZ ! 27699    !   !" <<endl;
    cout<< "!   !   JESICA ! LEGUIZA   ! 28015    !   !" <<endl;
    cout<< "!   !   MARTINA! NARVAEZ   ! 32055    !   !" <<endl;
    cout<< "!   !---------------------------------!   !" <<endl;
    cout<< "!   !            GRUPO: 02            !   !" <<endl;
    cout<< "!    ---------------------------------    !" <<endl;
    cout<< "!                                         !" <<endl;
    cout<< " ----------------------------------------- " <<endl;

}

#endif // FUNCIONES_H_INCLUDED
