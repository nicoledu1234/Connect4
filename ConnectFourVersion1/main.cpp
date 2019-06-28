#include <iostream>
#include <cstdlib>
#include <allegro.h>
#include <fstream>
#include <algorithm>

using namespace std;

BITMAP *buffer;
BITMAP *monedabmp;
BITMAP *moneda;
BITMAP *ladrillo;
BITMAP *fin;
BITMAP *ficha ;


//Posicion inicial de la moneda
int direccion = 0; // moneda
int pos_x = 30*15;
int pos_y = 3*30;


//mapa
int const ancho = 21; // juego
int const alto = 31; // juego

int pos_b_x; //  moneda
int pos_b_y; //   moneda
int origen_b_x;  // moneda
int origen_b_y;  // moneda

class Juego{

public:
    int tipo=0;
    static Juego *getInstancia(){
            if(instancia == 0)
                instancia = new Juego();
            return instancia;
        }
    void crearMapa();
    bool finJuego();
    void Inicializar();
    void cambiar(int&,int,int);
    void verificar(int,int,int);
    void RevisarGano(char x,char*);

protected:

       char mapa[ancho][alto]={
       "                           o",
       "                            ",
       "      MMMMMMMMMMMMMMMMM     ",
       "      MMMMMMMMFMMMMMMMM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MMMMMMMMMMMMMMMMM     ",
       "      MMMMMMMMMMMMMMMMM     ",
       "                            ",
    };
char mapa2[ancho][alto]={
       "                           o",
       "                            ",
       "      MMMMMMMMMMMMMMMMM     ",
       "      MMMMMMMMFMMMMMMMM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MFFFFFFFFFFFFFFFM     ",
       "      MFOFOFOFOFOFOFOFM     ",
       "      MMMMMMMMMMMMMMMMM     ",
       "      MMMMMMMMMMMMMMMMM     ",
       "                            ",
    };
    private:
        static Juego *instancia;
};
void Juego::cambiar(int &turno,int col,int fil){
    for(int i=0;i<21;i+=2){
        for(int j = 0;j<31;j+=2){
            if(col == j && fil == i){
                if(mapa[fil][col]== 'O'){
                if(turno == 0){
                  masked_blit(ficha ,buffer,33*1,0,col*30,fil*30,33,33);
                  verificar(fil,col,turno);
                  turno = 1;
                }
                else{
                    masked_blit(ficha,buffer,33*2,0,col*30,fil*30,33,33);
                    verificar(fil,col,turno);
                    turno = 0;
                }
                }
            }
        }
    }
}

void Juego::verificar(int pos1, int pos2,int turno){
    for(int fila = 0; fila < ancho; fila++)
    {
        for(int columna = 0; columna < alto; columna++)
        {
            if((mapa2[fila][columna] == mapa[pos1][pos2])&&(mapa[pos1][pos2] == 'O')){
                    if(turno == 0){
                        mapa2[pos1][pos2] = '0';
                    }
                    else{
                        mapa2[pos1][pos2]  = '1';
                    }
            }
        }
    }
}

void Juego::RevisarGano (char x,char *ruta){

	BITMAP *ganar=load_bitmap(ruta,NULL);
	for( int i = 0; i <= 21; i++ ){

		for( int j = 0; j <= 31; j++ ){

			if( (mapa2[i][j] == x)&&
				(mapa2[i+2][j+2] == x)&&
				(mapa2[i+4][j+4] == x)&&
				(mapa2[i+6][j+6] == x))
            {
				while(!key[KEY_ESC]){
				masked_blit(ganar,buffer,0,0,0,0,880,630);
				break;
				}
			}

			if( (mapa2[i][j] == x)&&
				(mapa2[i][j+2] == x)&&
				(mapa2[i][j+4] == x)&&
				(mapa2[i][j+6] == x))
			{
				while(!key[KEY_ESC]){
				masked_blit(ganar,buffer,0,0,0,0,880,630);
				break;
				}
			}

			if( (mapa2[i][j] == x)&&
				(mapa2[i+2][j] == x)&&
				(mapa2[i+4][j] == x)&&
				(mapa2[i+6][j] == x))
			{
				while(!key[KEY_ESC]){
				masked_blit(ganar,buffer,0,0,0,0,880,630);
				break;
				}
			}

			if( (mapa2[i][j] == x)&&
				(mapa2[i+2][j-2] == x)&&
				(mapa2[i+4][j-4] == x)&&
				(mapa2[i+6][j-6] == x))
			{
				while(!key[KEY_ESC]){
				masked_blit(ganar,buffer,0,0,0,0,880,630);
				break;
				}
			}

			if ( (mapa2[i][j] == x)&&
				 (mapa2[i][j-2] == x)&&
				 (mapa2[i][j-4] == x)&&
				 (mapa2[i][j-6] == x))
			{
				while(!key[KEY_ESC]){
				masked_blit(ganar,buffer,0,0,0,0,880,630);
				break;
				}
			}
		}

	}
}



void Juego::crearMapa()
{
   for(int fila = 0; fila < ancho; fila++)
    {
        for(int columna = 0; columna < alto; columna++)
        {
            if(mapa[fila][columna] == 'M')
            {
                draw_sprite(buffer, ladrillo, columna*30, fila*30);
            }
            else if(mapa[fila][columna] == 'F')
            {
                draw_sprite(buffer,ladrillo, columna*30, fila*30);
            }
            else if(mapa[fila][columna] == 'o')
            {
                draw_sprite(buffer, fin, columna*30, fila*30);
            }
            else if(mapa[fila][columna] == 'O')
            {

            }
        }
   }
}


bool Juego::finJuego()
{
   for(int fila = 0; fila < ancho; fila++)
    {
        for(int columna = 0; columna < alto; columna++)
        {
            if(mapa[fila][columna] == 'o')
            {
                return true;
            }
        }
   }
   return false;
}

void Juego::Inicializar()
{
    buffer = create_bitmap(880, 630);
    ladrillo = load_bitmap("bloqueA.bmp",NULL);
    monedabmp = load_bitmap("black.bmp",NULL);
    moneda = create_bitmap(33, 33);
    fin = load_bitmap("icono.bmp",NULL);
    ficha = load_bitmap("fichaAmarilla.bmp",NULL);
}

class Sprite
{
    public:
        virtual void CrearSprite() = 0;
};

Juego *Juego::instancia = 0;

class Moneda: public Sprite, public Juego
{
    public:
        bool activo;
        void CrearSprite();
        void direccionamiento(int &, int &, int &,int &,int &);

};

void Moneda::direccionamiento(int &direccion, int &pos_x, int &pos_y,int &fil,int &col){

       if(key[KEY_LEFT]){
           direccion  = 0;
            activo = true;
        }
       else if(key[KEY_RIGHT]){
           direccion = 1;
            activo = true;
        }
       else if(key[KEY_UP]){
           direccion  = 2;
            activo = true;
        }
       else if(key[KEY_DOWN]){
           direccion  =  3;
            activo = true;
        }
        if(direccion == 0 && activo == true){
                 if((mapa[pos_y/30][(pos_x-30)/30] != 'M')&&(mapa[pos_y/30][(pos_x-30)/30] != 'O')){
                   pos_x -= 30;
                   col--;
                   activo = false;
                }
                else
                    direccion = 1;
           }

           if(direccion == 1 && activo == true){
                if((mapa[pos_y/30][(pos_x+30)/30] != 'M')&&(mapa[pos_y/30][(pos_x+30)/30] != 'O')){
                   pos_x += 30;
                   col++;
                    activo = false;
                }
                else
                    direccion = 2;
           }

           if(direccion == 2 && activo == true){
                if((mapa[(pos_y-30)/30][pos_x/30] != 'M')&&(mapa[(pos_y-30)/30][pos_x/30] != 'O')){
                  pos_y -= 30;
                  fil--;
                  activo = false;
                }
                else
                    direccion = 3;
           }

           if(direccion == 3 && activo == true){
                if((mapa[(pos_y+30)/30][pos_x/30] != 'M')&&(mapa[(pos_y+30)/30][pos_x/30] != 'O')){
                   pos_y += 30;
                   fil++;
                   activo = false;
                }
                else
                    direccion = 3;
           }
}

void Moneda::CrearSprite()
{
    blit(monedabmp, moneda, direccion*33,0,0,0,33,33);
    draw_sprite(buffer, moneda, pos_x, pos_y);
}

int main()
{

    allegro_init();
	install_keyboard();
	install_mouse();

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 880, 630, 0, 0);


	Juego *configuracion = Juego::getInstancia();
    configuracion->Inicializar();

    Moneda *mone = new Moneda;
    bool nivel1 = true;

	BITMAP *buffer2 = create_bitmap(880, 630);
	BITMAP *fondo1;
	BITMAP *fondo2;
	BITMAP *fondo3;
	BITMAP *cursor;


	fondo1 = load_bitmap("menu1a.bmp",NULL);
	fondo2 = load_bitmap("menu2a.bmp",NULL);
	fondo3 = load_bitmap("menu3a.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);

    bool salida = false;

    int turno = 0;

	while ( !salida )
	{
         // posicion del boton
         if ( mouse_x > 480 && mouse_x < 530 &&
              mouse_y > 200 && mouse_y < 350)
         {
            blit(fondo2, buffer2, 0, 0, 0, 0, 880, 630);

            // si presionas el click izquierdo
            if ( mouse_b & 1 )
            {
                salida=true;
            }
         }

         else if ( mouse_x > 377 && mouse_x < 530 &&
              mouse_y > 430 && mouse_y < 471)
         {
            blit(fondo3, buffer2, 0, 0, 0, 0, 880, 630);

            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                allegro_exit();
            }
         }else{
            blit(fondo1, buffer2, 0, 0, 0, 0, 880, 630);
         }



         masked_blit(cursor, buffer2, 0, 0, mouse_x, mouse_y, 13,22);


	     blit(buffer2, screen, 0, 0, 0, 0, 880, 630);

}


	clear(buffer2);
	clear(fondo1);
	clear(fondo2);
	clear(fondo3);
	clear(cursor);

    int col = 15,fil = 4;

    while(!key[KEY_ESC] && configuracion->finJuego()  && nivel1){


       mone->direccionamiento(direccion, pos_x, pos_y,fil,col);


       configuracion->crearMapa();
	   mone->CrearSprite();

        if(key[KEY_SPACE]){
            configuracion->cambiar(turno,col,fil);
        }

        char rojo[]={"ganoRojo.bmp"};
        char amarillo[]={"ganoAmarillo.bmp"};
        configuracion->RevisarGano('1',rojo);
        configuracion->RevisarGano('0',amarillo);


	   blit(buffer,screen,0,0,0,0,880,630);
	   rest(70);
	   clear(moneda);

 }
    allegro_exit();
	return 0;
}
END_OF_MAIN();
