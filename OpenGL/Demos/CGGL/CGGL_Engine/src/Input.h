/**********************************************************************************
 * Tipo que representa o dispositivo de entrada.
 *
 * Tem suporte para as teclas:
 *   - ASCII 
 *   - teclas especials (LEFT, RIGHT, ...)
 * 
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _CGGL_INPUT_H_
#define _CGGL_INPUT_H_

#include "globals.h"

namespace cggl {

  #define CGGL_INPUT_MAX_KEYS 255

  class Input {
    bool asciiKeys[CGGL_INPUT_MAX_KEYS];
    bool specialKeys[CGGL_INPUT_MAX_KEYS];


  public:
    Input();

    //----> Public Input Methods ----------------------------------------------------
    //  ASCII key
    void PressKey    (unsigned char k);
    void ReleaseKey  (unsigned char k);
    int  IsKeyPressed(unsigned char k);
    //  Special Keys
    void PressSpecialKey(    int k);
    void ReleaseSpecialKey(  int k);
    int  IsSpecialKeyPressed(int k);
    //-------------------------------------------------------------------------------
  };

}

#endif