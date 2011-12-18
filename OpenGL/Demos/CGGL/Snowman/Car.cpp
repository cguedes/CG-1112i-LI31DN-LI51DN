#include "car.h" 
#include <cggl/MathUtils.h>

using namespace cggl;

Car::Car(const Vector3& pos) : position(pos) 
{
  model = new ObjModel("models/porsche.obj");

  direction = Vector3(1, 0, 0);
  velocity = .05; // meters/sec
  angle = 0;
  velocity = 0;

}

void Car::InitGL() { 
  Object::InitGL();
  model->InitGL();
}

void Car::Draw() {
  Object::Draw();

  glPushMatrix();
  glTranslated(position.x, position.y+0.5, position.z);
  glRotatef(angle+90, 0, 1, 0);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  model->Draw();

  glDisable(GL_LIGHTING);


  glPopMatrix();
}


void Car::Update(int deltaTimeMilis){
  Object::Update(deltaTimeMilis);

  model->Update(deltaTimeMilis);

  double t = deltaTimeMilis/(float)1000;


  // Movement
  const static float ROTATION_SPEED = 90.0f;      // rotate 90º per second
  const static float ACCELERATION_SPEED = 10.0f;  // acceleration per second

  bool directionChanged = false;


  if(App::Input->IsSpecialKeyPressed(GLUT_KEY_LEFT))
  {
    angle += ROTATION_SPEED * t;
    directionChanged = true;
  }
  else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_RIGHT))
  {
    angle -= ROTATION_SPEED * t;
    directionChanged = true;
  }
  if(App::Input->IsSpecialKeyPressed(GLUT_KEY_UP))
  {
    velocity += ACCELERATION_SPEED * t;
  } 
  else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_DOWN))
  {
    velocity -= ACCELERATION_SPEED * t;
  }
  

  if(directionChanged)
  {
    // update direction
    float angleRad = DEG_TO_RAD(angle);
    direction.x = cos(angleRad);
    direction.z = -sin(angleRad);
  }

  // update position
  // x = x0+ vo*t 
  position = position + (direction * velocity) * t;

  // Some help commands
  //   s -> stop
  //   r -> reset
  //   F1 -> debug on/off
  if(App::Input->IsKeyPressed('s')) { velocity = 0; }
  if(App::Input->IsKeyPressed('r')) { velocity = 0; position = Vector3(); angle = 0; }


}
