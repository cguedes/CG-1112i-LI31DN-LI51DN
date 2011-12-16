/**********************************************************************************
 * Defini��o do objecto SimplePlane.
 * Representa um "plano" ~cuja normal � (0,1,0).
 * Est� posicionado em Y = -3.5 (0.5 do raio das bolas).
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _SIMPLE_PLANE_H_
#define _SIMPLE_PLANE_H_

#include <GL/glut.h>
#include <cggl/App.h>

class SimplePlane : public cggl::Object {
  float y;
  float size;

public: 
  SimplePlane(float yval = -3.5, float sizeval= 10): y(yval), size(sizeval){}

  void Draw(){
    Object::Draw();

    //glEnable(GL_LIGHTING);

    glPushMatrix();
    float diffuseColor[3] = { 0.0, 0.5, 0.0 };
    glColor3f(diffuseColor[0], diffuseColor[1], diffuseColor[2]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, diffuseColor);
    glNormal3f(0, 1, 0);
    glBegin(GL_QUADS);
      glVertex3f(+size, y, +size);
      glVertex3f(+size, y, -size);
      glVertex3f(-size, y, -size);
      glVertex3f(-size, y, +size);
    glEnd();
    glPopMatrix();

  //  glDisable(GL_LIGHTING);
  }

};
#endif //_SIMPLE_PLANE_H_