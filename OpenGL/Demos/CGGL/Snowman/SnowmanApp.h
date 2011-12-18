/**********************************************************************************
 * Aplica��o espec�fica a implementar: Boneco de neve.
 * 
 *
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * �rea Departamental de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
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
