#include "constantes.h"
#include "solucion.h"
#include "logica.h"


#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/
int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de 
    dos dimensiones tablero.  

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tablero[1][0]
    */


   /*  HorizontalValidation */
    
    char** tablero = GetTablero();
/*     int countValidator;
    for (int i = 0; i < 3; i++)
    {
        countValidator =0; 
    char nowPlayer = tablero[i][0];
        for (int j = 0; j < 3; j++)
            {
                if(tablero[i][j]!='_'){  
                    countValidator++; 
                    if(countValidator==3){           
                        if (nowPlayer=='X')
                        {     
                            return GANO_X;
                        }
                        else
                        {
                            return GANO_O;
                        }   
                    }                
                }
            } 
    } */

    for (int i = 0; i < 3; i++)
    {
        char nowPlayer = tablero[i][0];
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j]=='_')
            {
                break; 
            }

            if (nowPlayer!=tablero[i][j])
            {
                break; 
            }

            if (j==2)
            {
               if (nowPlayer=='X')
               {
                   return GANO_X;
               }
               else
               {
                   return GANO_O;
               }
            }
            
        }
        
    }
    


    /* VerticalValidation */
    for (int i = 0; i < 3; i++)
    {
        if(tablero[0][i]!='_' && tablero[0][i]==tablero[1][i] &&tablero[1][i]== tablero[2][i]){

            if(tablero[0][i]=='X'){
                return GANO_X;
            }
            else {
                return GANO_O;
            }
        }
    }   

    /* DiagonalLeftRightValidation */

    if(tablero[0][0]!='_' && tablero[0][0]==tablero[1][1] &&tablero[1][1]== tablero[2][2]){

        if(tablero[0][0]=='X'){
            return GANO_X;
        }
        else {
            return GANO_O;
        }
    }

    /* DiagonalRightLeftValidation */
    if(tablero[0][2]!='_' && tablero[0][2]==tablero[1][1] &&tablero[1][1]== tablero[2][0]){

        if(tablero[0][2]=='X'){
            return GANO_X;
        }
        else {
            return GANO_O;
        }
    }

    /* Empate */
    int count =0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j]!='_')
            {
                count++;
            }
        }   
    }
    if (count==9)
    {
        return EMPATE;
    }

    return JUEGO_EN_CURSO;
}


