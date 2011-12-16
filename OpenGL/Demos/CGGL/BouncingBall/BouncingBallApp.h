/**********************************************************************************
 * Aplicação específica a implementar: AP3.
 * Serve como exemplo de utilização de fisica em objectos.
 * 
 * A aplicação representa uma cena que contém uma bola 
 *  a saltar na vertical, em cima de um plano segundo as leis da fisica.
 *
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 **********************************************************************************/

#include <GL/glut.h>
#include <cggl/App.h>

#include "Ball.h"

class BouncingBallApp : public cggl::App {

	Ball* ball;

public: 
  void CreateScene();
  void Draw();
  void Update(int deltaTimeMilis);
};
