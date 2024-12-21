//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

struct Personajes {
    string nombre;
    int salud;
    int ataque[3];
    int defensa;
};

void continuarJuego ();
void titulo ();
void bienvenida ();
void instrucciones ();
void ListaPersonajes (Personajes p1, Personajes p2, Personajes p3, Personajes p4, Personajes p5);
int eleccionPersonaje(Personajes p1, Personajes p2, Personajes p3, Personajes p4, Personajes p5);
int eleccionEnemigo (Personajes p1, Personajes p2, Personajes p3, Personajes p4, Personajes p5, int personajePropio);
void personajesElegidos (string nombreP, string nombreE);
void estadoPersonajes (int saludP, string nombreP, int saludE, string nombreE);
void ataquePropio (int ataqueP[], int& saludE, int defensaE);
void ataqueEnemigo (int ataqueE[], int& saludP, int defensaP);
void mensajeGanaste ();
void mensajePerdiste ();

int main()
{   
    Personajes p1;
    p1.nombre = "John Wick";
    p1.salud = 100;
    p1.ataque[0] = 40;
    p1.ataque[1] = 30;
    p1.ataque[2] = 25;
    p1.defensa = 60;

    Personajes p2;
    p2.nombre = "Lara Croft";
    p2.salud = 100;
    p2.ataque[0] = 35;
    p2.ataque[1] = 40;
    p2.ataque[2] = 25;
    p2.defensa = 65;

    Personajes p3;
    p3.nombre = "Ethan Hunt";
    p3.salud = 100;
    p3.ataque[0] = 30;
    p3.ataque[1] = 20;
    p3.ataque[2] = 25;
    p3.defensa = 70;

    Personajes p4;
    p4.nombre = "Jason Bourne";
    p4.salud = 100;
    p4.ataque[0] = 45;
    p4.ataque[1] = 30;
    p4.ataque[2] = 35;
    p4.defensa = 60;

    Personajes p5;
    p5.nombre = "Natasha Romanoff";
    p5.salud = 100;
    p5.ataque[0] = 40;
    p5.ataque[1] = 30;
    p5.ataque[2] = 25;
    p5.defensa = 75;

    //declaramos varibles: nombre, ataque y defensa para los personajes elegidos.
    string nombreP;
    string nombreE;
    int saludP;
    int saludE;
    int ataqueP[3];
    int ataqueE[3];
    int defensaP;
    int defensaE;

    //Ingresamos el nombre de los personajes que
    int personajePropio = 0;
    int personajeEnemigo = 0;
    
    titulo ();
    bienvenida ();
    continuarJuego ();
    titulo ();
    instrucciones ();
    continuarJuego ();
    titulo ();
    ListaPersonajes (p1, p2, p3, p4, p5);
    personajePropio = eleccionPersonaje(p1, p2, p3, p4, p5);
    personajeEnemigo = eleccionEnemigo(p1, p2, p3, p4, p5, personajePropio);

    switch (personajePropio)
    {
    case 1:
        nombreP = p1.nombre;
        saludP = p1.salud;
        ataqueP[0] = p1.ataque[0];
        ataqueP[1] = p1.ataque[1];
        ataqueP[2] = p1.ataque[2];
        defensaP = p1.defensa;
        break;
    
    case 2:
        nombreP = p2.nombre;
        saludP = p2.salud;
        ataqueP[0] = p2.ataque[0];
        ataqueP[1] = p2.ataque[1];
        ataqueP[2] = p2.ataque[2];
        defensaP = p2.defensa;
        break;
    
    case 3:
        nombreP = p3.nombre;
        saludP = p3.salud;
        ataqueP[0] = p3.ataque[0];
        ataqueP[1] = p3.ataque[1];
        ataqueP[2] = p3.ataque[2];
        defensaP = p3.defensa;
        break;
    
    case 4:
        nombreP = p4.nombre;
        saludP = p4.salud;
        ataqueP[0] = p4.ataque[0];
        ataqueP[1] = p4.ataque[1];
        ataqueP[2] = p4.ataque[2];
        defensaP = p4.defensa;
        break;
    
    case 5:
        nombreP = p5.nombre;
        saludP = p5.salud;
        ataqueP[0] = p5.ataque[0];
        ataqueP[1] = p5.ataque[1];
        ataqueP[2] = p5.ataque[2];
        defensaP = p5.defensa;
        break;
    
    default:
        break;
    }

    switch (personajeEnemigo)
    {
    case 1:
        nombreE = p1.nombre;
        saludE = p1.salud;
        ataqueE[0] = p1.ataque[0];
        ataqueE[1] = p1.ataque[1];
        ataqueE[2] = p1.ataque[2];
        defensaE = p1.defensa;
        break;
    
    case 2:
        nombreE = p2.nombre;
        saludE = p2.salud;
        ataqueE[0] = p2.ataque[0];
        ataqueE[1] = p2.ataque[1];
        ataqueE[2] = p2.ataque[2];
        defensaE = p2.defensa;
        break;
    
    case 3:
        nombreE = p3.nombre;
        saludE = p3.salud;
        ataqueE[0] = p3.ataque[0];
        ataqueE[1] = p3.ataque[1];
        ataqueE[2] = p3.ataque[2];
        defensaE = p3.defensa;
        break;
    
    case 4:
        nombreE = p4.nombre;
        saludE = p4.salud;
        ataqueE[0] = p4.ataque[0];
        ataqueE[1] = p4.ataque[1];
        ataqueE[2] = p4.ataque[2];
        defensaE = p4.defensa;
        break;
    
    case 5:
        nombreE = p5.nombre;
        saludE = p5.salud;
        ataqueE[0] = p5.ataque[0];
        ataqueE[1] = p5.ataque[1];
        ataqueE[2] = p5.ataque[2];
        defensaE = p5.defensa;
        break;
    
    default:
        break;
    }

    titulo ();
    personajesElegidos(nombreP, nombreE);
    continuarJuego ();
   
    
    do
    {
        titulo ();
        estadoPersonajes (saludP, nombreP, saludE, nombreE);
        ataquePropio (ataqueP, saludE, defensaE);
        if (saludE <= 0)
        {
            titulo ();
            estadoPersonajes (saludP, nombreP, saludE, nombreE);
            mensajeGanaste();
            //continuarJuego ();
            break;
        }
        titulo ();
        estadoPersonajes (saludP, nombreP, saludE, nombreE);
        cout <<"########## Turno de tu oponente ##########"<<endl;
        ataqueEnemigo (ataqueE, saludP, defensaP);
        if (saludP <= 0)
        {
            titulo ();
            estadoPersonajes (saludP, nombreP, saludE, nombreE);
            mensajePerdiste();
            //continuarJuego ();
            break;
        }    
      
    } while (saludP > 0 || saludE > 0);

    return 0;
}

void continuarJuego ()
{
    cout <<endl;
    system("pause");
}

void instrucciones ()
{
    cout <<"En Crossover Letal, elige un personaje icónico del cine y enfréntate en combates 1 vs 1 por turnos."<<endl<<
            "Cada turno, selecciona uno de los tres ataques disponibles: arma de fuego, arma blanca o cuerpo a cuerpo,"<<endl<<
            "cada uno con su propio daño. El objetivo es reducir la salud del oponente a 0 antes de que hagan lo mismo contigo. "<<endl<<
            "¡Demuestra quién es la verdadera leyenda de la acción! 🎬⚔️"<<endl;
}

void titulo ()
{
    system ("cls"); //Limpia la pantalla de consola
    cout <<endl<<"************************************************************************************************************";
    cout <<R"(
                 ____                                         _         _        _ 
                / ___|_ __ ___  ___ ___  _____   _____ _ __  | |    ___| |_ __ _| |
               | |   | '__/ _ \/ __/ __|/ _ \ \ / / _ \ '__| | |   / _ \ __/ _` | |
               | |___| | | (_) \__ \__ \ (_) \ V /  __/ |    | |__|  __/ || (_| | |
                \____|_|  \___/|___/___/\___/ \_/ \___|_|    |_____\___|\__\__,_|_|
    )"<<endl;
    cout <<"************************************************************************************************************"<<endl;
}

void bienvenida ()
{
    cout <<"🌟 Bienvenido a Crossover Letal 🌟"<<endl;
    cout <<"Prepárate para la batalla definitiva donde los héroes más icónicos del cine se enfrentan cara a cara "<<endl<<
            "en un choque épico. En este mundo, las reglas de sus historias se rompen, y solo queda una pregunta: "<<endl<<
            "¿Quién será el último en pie?"<<endl;
}

void ListaPersonajes (Personajes p1, Personajes p2, Personajes p3, Personajes p4, Personajes p5)
{    
    //cout <<"************************************************************************************************************"<<endl;
    cout <<setw(40)<<p1.nombre<<setw(15)<<p2.nombre<<setw(15)<<p3.nombre<<setw(15)<<p4.nombre<<setw(20)<<p5.nombre<<endl;
    cout <<setw(40)<<"(Opcion 1)"<<setw(15)<<"(Opcion 2)"<<setw(15)<<"(Opcion 3)"<<setw(14)<<"(Opcion 4)"<<setw(17)<<"(Opcion 5)"<<endl<<endl;
    cout <<"Salud"<<setw(31)<<p1.salud<<setw(15)<<p2.salud<<setw(15)<<p3.salud<<setw(15)<<p4.salud<<setw(16)<<p5.salud<<endl;
    cout <<"Ataque 1 (Arma de fuego)"<<setw(11)<<p1.ataque[0]<<setw(15)<<p2.ataque[0]<<setw(15)<<p3.ataque[0]<<setw(15)<<p4.ataque[0]<<setw(16)<<p5.ataque[0]<<endl;
    cout <<"Ataque 2 (Arma Blanca)"<<setw(13)<<p1.ataque[1]<<setw(15)<<p2.ataque[1]<<setw(15)<<p3.ataque[1]<<setw(15)<<p4.ataque[1]<<setw(16)<<p5.ataque[1]<<endl;
    cout <<"Ataque 3 (Cuerpo a cuerpo)"<<setw(9)<<p1.ataque[2]<<setw(15)<<p2.ataque[2]<<setw(15)<<p3.ataque[2]<<setw(15)<<p4.ataque[2]<<setw(16)<<p5.ataque[2]<<endl;
    cout <<"Defensa"<<setw(28)<<p1.defensa<<setw(15)<<p2.defensa<<setw(15)<<p3.defensa<<setw(15)<<p4.defensa<<setw(16)<<p5.defensa<<endl;
    cout <<"************************************************************************************************************"<<endl;
}

int eleccionPersonaje(Personajes p1, Personajes p2, Personajes p3, Personajes p4, Personajes p5)
{
    int personajePropio = 0;
    
    do
    {
       cout <<"Para elegir un personaje digite una opción: ";
       cin >>personajePropio;

    } while (personajePropio < 1 || personajePropio > 5);

    return personajePropio;
    
}

int eleccionEnemigo (Personajes p1, Personajes p2, Personajes p3, Personajes p4, Personajes p5, int personajePropio)
{
    int personajeEnemigo = 0;
    do
    {
        srand(time(0));
        personajeEnemigo = rand()%5 + 1;
    } while (personajePropio == personajeEnemigo);

    return personajeEnemigo;
}

void personajesElegidos (string nombreP, string nombreE)
{
    cout <<"Elegiste a "<<nombreP<<" y lucharas contra "<<nombreE<<endl;
    cout <<"QUE EMPIEZE LA LUCHA!!!"<<endl;
    cout <<"************************************************************************************************************"<<endl;
    
}

void estadoPersonajes (int saludP, string nombreP, int saludE, string nombreE)
{
    char barraP = 219;
    char barraE = 219;
    int actualP = saludP/10;
    int actualE = saludE/10;
    cout <<nombreP<<" :"<<saludP<<setw(2);
    for (int i=0; i < actualP; i++) cout <<barraP;
    cout <<setw (58);
    cout <<nombreE<<" :"<<saludE<<setw(2);
    for (int i=0; i < actualE; i++) cout <<barraE;
    cout <<endl<<endl;
    
}

void ataquePropio (int ataqueP[], int& saludE, int defensaE)
{
    int OpAtaque = 0;
    cout <<"========== Es tu turno ========== "<<endl<<endl;
    cout <<"Tus Ataques: "<<endl;
    cout <<"(1) Arma de fuego: "<<ataqueP[0]<<setw(20)
         <<"(2) Arma blanca: "<<ataqueP[1]<<setw(27)
         <<"(3) Cuerpo a cuerpo: "<<ataqueP[2]<<endl<<endl;
    do
    {   cout <<"Elije una opcion: ";
        cin >>OpAtaque;
    } while (OpAtaque < 1 || OpAtaque > 3);

    saludE = saludE - ((100 - defensaE))*ataqueP[OpAtaque - 1]/100;

    if (saludE < 0) saludE = 0;
}

void ataqueEnemigo (int ataqueE[], int& saludP, int defensaP)
{
    int OpAtaque = 0;
    srand(time(0));
    OpAtaque = rand()%3 + 1;
    saludP = saludP - ((100 - defensaP))*ataqueE[OpAtaque - 1]/100;
    if (saludP < 0) saludP = 0;

    switch (OpAtaque)
    {
    case 1: cout <<endl<<"Tu oponente te esta atacando con Arma de fuego"<<endl;
        break;
    case 2: cout <<endl<<"Tu oponente te esta atacando con Arma blanca"<<endl;
        break;
    case 3: cout <<endl<<"Tu oponente te esta atacando Cuerpo a cuerpo"<<endl;
        break;
    
    default:
        break;
    }
    continuarJuego ();

}

void mensajeGanaste ()
{
    cout <<endl<<R"(
                  __   __           __        ___         _ _ 
                  \ \ / /__  _   _  \ \      / (_)_ __   | | |
                   \ V / _ \| | | |  \ \ /\ / /| | '_ \  | | |
                    | | (_) | |_| |   \ V  V / | | | | | |_|_|
                    |_|\___/ \__,_|    \_/\_/  |_|_| |_| (_|_)
    )"<<endl;

}

void mensajePerdiste ()
{
    cout <<endl<<R"(
                 __   __            _              _             __
                 \ \ / /__  _   _  | |    ___  ___| |_      _   / /
                  \ V / _ \| | | | | |   / _ \/ __| __|    (_) | | 
                   | | (_) | |_| | | |__| (_) \__ \ |_      _  | | 
                   |_|\___/ \__,_| |_____\___/|___/\__|    (_) | | 
                                                                \_\
    )"<<endl;

}

