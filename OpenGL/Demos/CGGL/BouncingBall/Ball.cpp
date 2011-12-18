#include "ball.h" 

using namespace cggl;

Ball::Ball(Vector3 pos, float rad): position(pos), radius(rad){

  velocity = Vector3(1,20,0);
}

void Ball::Draw(){
  Object::Draw();
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glPushMatrix();
    const static float diffuseColor[3] = { 0.8, 0, 0 };
    glColor3fv(diffuseColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);

    glTranslated(position.x, position.y, position.z);
    glutSolidSphere(radius, 30, 30);
  glPopMatrix();

  glDisable(GL_LIGHTING);
}


void Ball::Update(int deltaTimeMilis){
  Object::Update(deltaTimeMilis);

  double t = deltaTimeMilis/(float)1000;

  double mass = 0.5;
  // a = F / m
  double fg = mass * -9.8;    // fg = m*g 
  double fdy = -6*3.14*radius*0.00001827*velocity.y;
  double fdx = -6*3.14*radius*0.00001827*velocity.x;

  double ax = (fdx) / mass;
  double ay = (fg + fdy) / mass;

  // v = v0 + a*t 
  velocity.y += ay * t;
  velocity.x += ax * t; // air resistance

  // x = x0+ vo*t + 0.5*a*t*t  
  position.y = position.y + velocity.y*t + 0.5 * ay * t * t;
  position.x = position.x + velocity.x*t;

  if(position.y <= radius){
    position.y = radius;
    velocity.y = -velocity.y * .8;  // COR - coeficiente de restituicao (simulacao)
    velocity.x = velocity.x  * .8;  // atrito (simulacao)
  }

}