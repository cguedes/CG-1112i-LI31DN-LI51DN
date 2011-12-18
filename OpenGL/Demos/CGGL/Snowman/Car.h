/**********************************************************************************
 * Defini��o do objecto "Boneco de Neve".
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
#ifndef _CAR_H_
#define _CAR_H_

#include <GL/glut.h>
#include <cggl/App.h>
#include <cggl/ObjModel.h>


class Car : public cggl::Object {

  cggl::Vector3 position;
  cggl::Vector3 direction;
  float velocity;
  float angle;

  cggl::ObjModel* model;

public: 
  Car(const cggl::Vector3& pos);

  void InitGL();
  void Update(int deltaTimeMilis);
  void Draw();

  cggl::Vector3& GetPosition()  { return position; };
  cggl::Vector3& GetDirection() { return direction; };

};

#endif //_CAR_H_