# Connect4
# Proyecto Final Ccomp1
#include <iostream>
using namespace std;

class DatosJugador{
    public:
	char nombreJugador[81];
	char fichaJugador;
	void JugadorGano (  ){
        cout << endl << nombreJugador << " Connected Four,  Gano!" << endl;
    }
};
class Tablero{
    public:
    char tablero[][10];
    int ancho, alto;
    Tablero(){
        char tablero[9][10];
    }

};
void DibujarTablero (char tablero[][10]){
	int filas = 6, columnas = 7, i, ix;
	cout << " -------"<<endl;
	for(i = 1; i <= filas; i++){
		cout << "|";
		for(ix = 1; ix <= columnas; ix++){
			if(tablero[i][ix] != 'X' && tablero[i][ix] != 'O')
            tablero[i][ix] = '#';
			cout << tablero[i][ix];
		}
		cout << "|" << endl;
	}
    cout << " -------"<<endl;

}
int Jugada( char tablero[][10], DatosJugador jugadorTurno ){
        int jugada;
        while ( jugada < 1 || jugada > 7 ){
            cout << "Turno de "<< jugadorTurno.nombreJugador << endl;
            cout << "Ingresa tu jugada, la posicion de una fila del 1 al 7:  ";
            cin  >> jugada;

            while ( tablero[1][jugada] == 'X' || tablero[1][jugada] == 'O' ){
                cout << "La fila esta llena, intenta otra jugada";
                cin  >> jugada;
            }

        }
    return jugada;
}
void RevisarJugada ( char tablero[][10], DatosJugador jugadorTurno, int jugada ){
	int ancho, turno;
	ancho = 6;
	turno = 0;

	while (  turno != 1 ){
		if ( tablero[ancho][jugada] != 'X' && tablero[ancho][jugada] != 'O' ){
			tablero[ancho][jugada] = jugadorTurno.fichaJugador;
			turno = 1;
		}
		else{
		--ancho;
		}
	}
}

int RevisarGano ( char tablero[][10], DatosJugador jugadorTurno ){
	//char ganador;
	int gano;

	//ganador = jugadorTurno.fichaJugador;
	gano = 0;

	for( int i = 1; i <= 8; i++ ){

		for( int j = 1; j <= 9; j++ ){

			if( tablero[i][j] ==jugadorTurno.fichaJugador  &&
				tablero[i+1][j+1] == jugadorTurno.fichaJugador &&
				tablero[i+2][j+2] == jugadorTurno.fichaJugador &&
				tablero[i+3][j+3] == jugadorTurno.fichaJugador )
            {
				gano = 1;
			}

			if( tablero[i][j] == jugadorTurno.fichaJugador   &&
				tablero[i][j+1] == jugadorTurno.fichaJugador &&
				tablero[i][j+2] == jugadorTurno.fichaJugador &&
				tablero[i][j+3] == jugadorTurno.fichaJugador )
			{
				gano = 1;
			}

			if( tablero[i][j] == jugadorTurno.fichaJugador  &&
				tablero[i+1][j] == jugadorTurno.fichaJugador &&
				tablero[i+2][j] == jugadorTurno.fichaJugador &&
				tablero[i+3][j] == jugadorTurno.fichaJugador )
			{
				gano = 1;
			}

			if( tablero[i][j] == jugadorTurno.fichaJugador  &&
				tablero[i+1][j-1] == jugadorTurno.fichaJugador &&
				tablero[i+2][j-2] == jugadorTurno.fichaJugador &&
				tablero[i+3][j-3] == jugadorTurno.fichaJugador )
			{
				gano = 1;
			}

			if ( tablero[i][j] == jugadorTurno.fichaJugador &&
				 tablero[i][j-1] == jugadorTurno.fichaJugador &&
				 tablero[i][j-2] == jugadorTurno.fichaJugador &&
				 tablero[i][j-3] == jugadorTurno.fichaJugador)
			{
				gano = 1;
			}
		}

	}

    return gano;
}
int TableroLleno( char tablero[][10] ){
	int lleno;
	lleno = 0;
	for ( int i = 1; i <= 7; ++i )
	{
		if ( tablero[1][i] != '#' )
			++lleno;
	}

return lleno;
}

int Reiniciar ( char tablero[][10] ){
	int Reiniciar;

	cout << "Quieres volver a jugar? Si(1) No(2): ";
	cin  >> Reiniciar;
	if ( Reiniciar == 1 )
	{
		for(int i = 1; i <= 6; i++)
		{
			for(int ix = 1; ix <= 7; ix++)
			{
				tablero[i][ix] = '#';
			}
		}
	}
	else{
		cout << "End Game!" << endl;
		Reiniciar=2;
    }
return Reiniciar;
}

int main()
{
	DatosJugador jugadorUno, jugadorDos;
	char tablero[9][10];

	int jugada, gano, lleno, reinicio;

	cout << "Connect 4" << endl << endl;
	cout << "Jugador Uno, ingresa tu Nombre:";
	cin  >> jugadorUno.nombreJugador;
	jugadorUno.fichaJugador = 'X';
	cout << "Jugador Dos, ingresa tu Nombre:";
	cin  >> jugadorDos.nombreJugador;
	jugadorDos.fichaJugador = 'O';

	lleno = 0;
	gano = 0;
	reinicio = 1;
	DibujarTablero( tablero );
	while ( reinicio == 1 )
	{
		jugada = Jugada( tablero, jugadorUno );
		RevisarJugada( tablero, jugadorUno, jugada );
		system("cls");
		DibujarTablero( tablero);
		gano = RevisarGano( tablero, jugadorUno );
		if ( gano == 1 )
		{
			
			jugadorUno.JugadorGano();
			reinicio = Reiniciar(tablero);
			if (reinicio == 2)
			{
				break;
			}
		}

		jugada = Jugada( tablero, jugadorDos );
		RevisarJugada( tablero, jugadorDos, jugada );
		system("cls");
		DibujarTablero( tablero );
		gano = RevisarGano( tablero, jugadorDos );
		if ( gano == 1 )
		{
			//JugadorGano(jugadorDos);
			jugadorDos.JugadorGano();
			reinicio = Reiniciar(tablero);
			if (reinicio == 2)
			{
				break;
			}
		}
		lleno = TableroLleno( tablero );
		if ( lleno == 7 )
		{
			cout << "El tablero esta lleno, es un empate"<< endl;
			reinicio = Reiniciar(tablero);
		}

	}
return 0;
}
