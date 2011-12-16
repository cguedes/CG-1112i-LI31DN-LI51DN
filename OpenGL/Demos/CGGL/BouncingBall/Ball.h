/**********************************************************************************
 * Defini��o do objecto Ball.
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
#ifndef _BALL_H_
#define _BALL_H_

#include <GL/glut.h>
#include <cggl/App.h>


class Ball : public cggl::Object {

  cggl::Vector3 position;  // posi��o inicial
  float radius;
  cggl::Vector3 velocity;
  
public: 
  Ball(cggl::Vector3 pos, float rad);

  void Update(int deltaTimeMilis);
  void Draw();
};

#endif //_BALL_H_