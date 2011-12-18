/**********************************************************************************
 * Definição do objecto Axis.
 *   Mostra um eixo de coordenadas do mundo usando as cores
 *    RED   -> xx axis
 *    GREEN -> yy axis
 *    BLUE  -> zz axis
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes - Dezembro de 2011
 **********************************************************************************/

#ifndef _AXIS_H_
#define _AXIS_H_

#include <GL/glut.h>
#include <cggl/App.h>

class Axis : public cggl::Object {

  float size;

public: 
  Axis(float size = 10): size(size){}

  void Draw(){
    Object::Draw();
    glPushMatrix();

    glBegin(GL_LINES);
      // xx
      glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(size, 0, 0);
      // yy
      glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, size, 0);
      // zz
      glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, size);
    glEnd();

    glPopMatrix();
  }



};
#endif //_AXIS_H_