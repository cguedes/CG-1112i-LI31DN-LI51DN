#include <cggl/App.h>
#include "Ball.h"

using namespace cggl;

Ball::Ball() 
{ 
  position = Vector3(1, 0, 0);
}

void Ball::Draw() 
{ 
  Object::Draw();

  glPushMatrix();

  glTranslated(position.x, position.y, position.z);
  glutSolidSphere(1, 30, 30);

  glPopMatrix();

}


void Ball::Update(int deltaTimeMillis) 
{ 
  Object::Update(deltaTimeMillis);

  position.x += .01;
}