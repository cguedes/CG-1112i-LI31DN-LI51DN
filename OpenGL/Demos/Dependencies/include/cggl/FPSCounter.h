/**********************************************************************************
 * Tipo que apresenta o número de frames por segundo da aplicação
 *    - Mostra o valor instântaneo e o valor médio (por segundo)
 * 
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
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
