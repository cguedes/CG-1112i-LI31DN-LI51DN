/**********************************************************************************
 * Aplicação específica a implementar: Boneco de neve.
 * 
 *
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Área Departamental de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes - Dezembro de 2011
 **********************************************************************************/

#include <GL/glut.h>
#include <cggl/App.h>

#include "Snowman.h"

class SnowmanApp : public cggl::App {

  Snowman * snowman;

public: 
  void CreateScene();
  void Draw();
  void Update(int deltaTimeMilis);
};
