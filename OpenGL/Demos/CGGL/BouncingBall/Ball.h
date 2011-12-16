/**********************************************************************************
 * Definição do objecto Ball.
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
#ifndef _BALL_H_
#define _BALL_H_

#include <GL/glut.h>
#include <cggl/App.h>


class Ball : public cggl::Object {

  cggl::Vector3 position;  // posição inicial
  float radius;
  cggl::Vector3 velocity;
  
public: 
  Ball(cggl::Vector3 pos, float rad);

  void Update(int deltaTimeMilis);
  void Draw();
};

#endif //_BALL_H_