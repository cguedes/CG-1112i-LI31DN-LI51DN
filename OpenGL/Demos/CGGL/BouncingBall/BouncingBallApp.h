/**********************************************************************************
 * Aplica��o espec�fica a implementar: AP3.
 * Serve como exemplo de utiliza��o de fisica em objectos.
 * 
 * A aplica��o representa uma cena que cont�m uma bola 
 *  a saltar na vertical, em cima de um plano segundo as leis da fisica.
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

#include <GL/glut.h>
#include <cggl/App.h>

class BouncingBallApp : public cggl::App {

public: 
  void CreateScene();
  void Draw();
  void Update(int deltaTimeMilis);
};
