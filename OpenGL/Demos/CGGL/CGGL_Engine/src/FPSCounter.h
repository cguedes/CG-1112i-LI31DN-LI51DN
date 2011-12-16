/**********************************************************************************
 * Tipo que apresenta o n�mero de frames por segundo da aplica��o
 *    - Mostra o valor inst�ntaneo e o valor m�dio (por segundo)
 * 
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _CGGL_FPSCOUNTER_H_
#define _CGGL_FPSCOUNTER_H_

#include "App.h"
#include "Object.h"

namespace cggl {

  class FPSCounter : public Object {

    int elapsedTimeMilis;
    int numberOfFramesInstant;
    int numberOfFramesPerSecond;
    int numberOfFramesPerSecondCounter;

  public: 
    FPSCounter();

    void Draw();
    void Update(int deltaTimeMilis);
  };

}


#endif
