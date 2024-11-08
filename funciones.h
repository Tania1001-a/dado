#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;


void mostrarMenu();
void nombres_jugadores(string &jug1, string &jug2); // funcion para guardar el nombre de los jugadores
int lanzarDado(); // funcion para que nos de el dado aleatorio.
int lanzarDadoinicio();
int determinarInicio(string &jug1, string &jug2); // funcion para saber que jugador arranca el juego
void tirada_de_dado (string &jug1, string &jug2);//determinar los 3 dados
void partida();
void creditos();
void jugar ();
void jugarronda(string nombreJugador, int numRonda,int &contadorlanzamientosfinal,bool &jugador_1_pierdeundado,  bool &jugador_2_pierdeundado);
int quitarleundado(int &prohibido,int &sumabonzo);
int duplicarlospuntos(int &sumabonzo) ;
bool confirmarSalida() ;


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

        //setlocale(LC_ALL, "Spanish");

        cout<< "         INGRESE NOMBRE DEL JUGADOR 1? ";
        cin>> jug1;
        cout<< endl;
        cout<< endl;
        cout<< "          INGRESE NOMBRE DEL JUGADOR 2? ";
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
        // aca si se ingresa una letra que no sea s o n funciona mal
        if (opc !='N'&& opc!='n' && opc !='S' && opc!='s' )
        {

            cout<<"por favor ingrese S/N"<<endl;

            system( "pause ");
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
    bool jugador_1_pierdeundado=false ;
    bool jugador_2_pierdeundado=false;
    nombres_jugadores(jug1, jug2);  //llamamos a la funcion para q muestre los nombres y las guarde en las variables
    jugador_inicial=determinarInicio(jug1, jug2) ;  //a a ir a det incio y hace el calculo de quien va a empezar para no mostrar los dados inicialmente
    int contadorlanzamientosfinal_jug1=0;//para buscar el mayor lanzamiento
    int contadorlanzamientosfinal_jug2=0;

    for (int ronda=1; ronda<=6 ; ronda++ )
    {
        if (jugador_inicial==1)  // no pongo jug1 xq si se llaman iguals llamaria al mismo nombre
        {


            // sera void xe va aretornar puntuacion cantidad  de bonificaciones, penalizaciones de dados q iran por referencia entonces retornaria muchas cosaas
            //aca solamente se llama a jugar ronda con nombre de jugador y con num d ronda
            jugarronda(jug1,ronda,jugador_1_pierdeundado, jugador_2_pierdeundado);
            jugarronda(jug2,ronda,jugador_2_pierdeundado, jugador_1_pierdeundado );
        }
        else
        {
            jugarronda(jug2,ronda,contadorlanzamientosfinal_jug2);
            jugarronda(jug1,ronda,contadorlanzamientosfinal_jug1);
        }
    }

}
//cuando estamos en el juego,mientras van saliendo los dados hay que ver donde
// y como hacer un acumulador     q sume los puntos de cada jugador por cada ronda,
//pensamos en hacer dos vectores pero no sabiamos como empezarlo
//////////////////////////////////////////
//tambien tenemos q mostrar los nombres y puntos de los dos jugadores en pantalla  como
// muestra la hoja 6 del trabajo, en esa parte:
// BONZO
////--------------------------------------------------------
//JOEY: 43 puntos DEE DEE: 36 puntos
// falta la funcion salir
//tratar de ingresar manualmente los dados para ver si funciona bien cada cosa q hacemos

/*Si el jugador decide seguir lanzando después de obtener un "Bonzo ve a
dormir" y en la siguiente tirada aparece el número prohibido, perderá tanto
los puntos acumulados como los beneficios obtenidos en esa ronda (como
quitarle un dado al oponente).
○ Si ya se ha quitado un dado al oponente y se obtiene otro "Bonzo ve a
dormir", no se podrá optar por la opción de quitarle un dado nuevamente.
Como mínimo una tirada debe contar con dos dados.

como hacer q pierda los beneficios  en la ronda si ya salio anteriormente la opcion quitarle un dado al oponente
y hacer que una vez que salio bonzo para un mismo jugador ver como hacer para  que no podra volver a quitarle un dado al oponente
                                                   */

// por ultimo al terinar el juego limpiar la pantalla para que no se muestre la tirada anterior


void jugarronda(string nombreJugador, int numRonda,int &contadorlanzamientosfinal,bool &yoperdiundado,  bool &oponentepierdeundado )

{
    bool banderacontinuarjugando=true;

    string respuesta;
    int acu_bonzo=0;
    int sumabonzo;
    cout<<"es turno de " << endl;
    cout << " ---------------- "<<  nombreJugador << "----------------" << endl;
    cout << " en la ronda: "  << " # " << numRonda <<endl;
    int contadorlanzamiento=0;

    while (banderacontinuarjugando)
    {
        contadorlanzamiento++; //cuenta lanzamientos a cada uno en cada ronda

        //lanzarDado ();  //llamo a lanzar dado para q m e un num del 1 al 6 aleatorio
        int dados [3]  ;
        int opcion;

        if(oponentepierdeundado && (dados[0]==prohibido ||dados[1]==prohibido  ||dados[2]==prohibido )
    {

        oponentepierdeundado=false;//pierde el beneficio de q oponente perdio un dado
    }
    cout<<" primer dado:  "<<dados[0] << " segundo dado: "<<dados[1] <<" tercer dado: "<<dados[2]  << endl<< endl;
        int prohibido = numRonda;  // Número prohibido que es el numero de  la ronda
        int contadorvecesdebonzo=0;
        // este if es si no esta penalizado
        if  (yoperdiundado)
    {

        dados[0]= lanzarDado();//va  a devolver los 3 dados y los guarda
            dados[1] = lanzarDado();

        }
        else
        {
                   dados[0]= lanzarDado();//va  a devolver los 3 dados y los guarda
        dados[1] = lanzarDado();
        dados[2]= lanzarDado();
         // q juegeu cn dos dados
        if (dados[0] == dados[1] && dados[1] == dados[2] && dados [0] != prohibido&& dados [1] != prohibido&& dados [2] != prohibido)
    {
        contadorvecesdebonzo++;
        cout<<"obtuvo BONZO VE A DORMIR !!!" ;
        acu_bonzo=dados[0] +dados [1] +dados [2];
            cout <<" usted puede elegir entre las siguentes opciones :";
            cout<< "opcion 1: quitarle un dado al oponente " <<endl;
            cout<<" opcion 2: duplicar los puntos "<< endl;
            cin>> opcion;
            switch (opcion)
            {
            case 1:
                oponentepierdeundado=true ;
                //  bool banderaqueseuso=0;
                //quitarleundado(prohibido,sumabonzo);
                // bool banderaqueseuso=1;
                break;

            case 2:
                duplicarlospuntos(sumabonzo);
                break;
            default :
                cout << "ingrese una opcion correcta ";
            }

            cout << "¿Quieres seguir lanzando? (S/N): ";
            cin >> respuesta;
            if(respuesta == "S" || respuesta == "s")
            {
                if(contadorvecesdebonzo==1 && numRonda+1 == prohibido)
                {
                    //perdera los puntos acumulados de las ronda (hacer vector de contador de puntos de cada ronda)
                    // ver como pierde las dos opciones
                }
            }
            if (respuesta == "N" || respuesta == "n")
            {
                banderacontinuarjugando= false;  // se le asina false a la bandera para decir q el jugador no quiere seguir jugando,osea pone en false a la bandera
            }
        }


        if (dados[0] == prohibido && dados[1] == prohibido && dados[2] == prohibido)
    {
        cout << "¡Perdiste el juego! Los tres dados mostraron el número prohibido." << endl;

        return;  //   //el return termina con la funcion jugarronda   despues de  q mostro el mensaje de que perdio,aca los 3 dados
        //en esa ronda fueron iguales al num prohibido  muestra que el jugador perdio y la funcion termina

    }
    /* Si aparecen dos caras con el número prohibido en la misma tirada, además
    de perder los puntos, en la próxima ronda el jugador solo podrá lanzar con
    dos dados.  como hacer para que solo en la proxima vuelta pueda lanzar dos dados y desp volver a tres dados */

    else if ((dados[0] == prohibido && dados[1] == prohibido) ||
                 (dados[1] == prohibido && dados[2] == prohibido) ||
                 (dados[0] == prohibido && dados[2] == prohibido))
    {

        cout << "Perdiste tus puntos en esta ronda ya que salieron dos caras iguales al numero prohibido y solo podrás lanzar con dos dados en la siguiente ronda." << endl<< endl;

        banderacontinuarjugando= false;   // esto es que el jugador  perdio y se  informa que solo podrá lanzar con dos dados en la prox ronda
    }
    else if (dados[0] == prohibido && dados[1] == prohibido && dados[2] == prohibido)
    {
        cout << "Perdiste tus puntos en esta ronda ya que salieron tres caras iguales al numero prohibido."
             // "el jugador pierde quedando su puntaje en cero" , habria q resolver como volver los puntos a cero
             << endl<<endl;
        banderacontinuarjugando= false;
    }
    else
    {
        int suma = dados[0] + dados[1] + dados[2];
            cout << "Puntos de la ronda :" << suma << endl<<endl;
            cout << "lanzamientos: " << contadorlanzamiento<< endl << endl ;
            cout << "¿Quieres seguir jugando? (S/N): ";
            cin >> respuesta;
            if (respuesta == "N" || respuesta == "n")
            {
                banderacontinuarjugando= false;  // se le asina false a la bandera para decir q el jugador no quiere seguir jugando,osea pone en false a la bandera
            }

        }


    }

    yoperdiundado=false;

    contadorlanzamientosfinal+=contadorlanzamiento;
    cout<<" contador final de cada uno"<<contadorlanzamientosfinal<< endl;      }
}


int lanzarDado()
{
    int dado = rand()%6+1;
    switch (dado)
    {
    case 1:
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        break;
    case 2:
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|       |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 3:
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|   *   |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 4:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 5:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 6:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    }




    return dado;

}

int determinarInicio(string &jug1, string &jug2)
{

    int numero_dado = lanzarDado( ) ;


    // guardo el valor del dado aleatorio dentro de la variable;




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


    switch (numero_dado)
    {
    case 1:
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        break;
    case 2:
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|       |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 3:
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|   *   |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 4:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 5:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 6:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    }




    return numero_dado;



}






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


int quitarleundado(int &prohibido, int &suma)
{
    int vcastigado[2];
    int x;
    int sumabonzo=0;
    int dados [2];

    for (x=0; x<2 ; x++ )
    {

        vcastigado[x]=lanzarDado();
    }


    if(dados[0]==dados[1] && dados[0]== prohibido && dados[1]== prohibido)
    {

        suma=0;

    }
    else
    {

        if(dados[0]==dados[1] && dados[0]!= prohibido && dados[1]!= prohibido)
        {

            cout << "no obtuvo el beneficio de BONZO,VE A DORMIR !!";
            sumabonzo=dados[0]+dados[1];
            return sumabonzo;  // donde retornaba sumabonzo?
        }




    }

}

int duplicarlospuntos(int &sumabonzo)
{
    int sumaduplicado;
    sumaduplicado=sumabonzo*2;
    return sumaduplicado; //donde retorna?


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

bool confirmarSalida()
{

    char respuesta;
    while(true)
    {
        cout << "Estas seguro de que deseas salir? (s/n): ";
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S')
        {
            return true;  // Confirmación de salida
        }
        else if( respuesta == 'n' || respuesta == 'N')
        {
            return false;
        }
        else
        {
            cout<<"ingrese una opcion valida"<<endl<<endl;
        }
    }
}


#endif // FUNCIONES_H_INCLUDED
