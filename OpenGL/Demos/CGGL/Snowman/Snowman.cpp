#include "snowman.h" 

using namespace cggl;

Snowman::Snowman(const Vector3& pos) : position(pos) 
{
  direction = Vector3(1, 0, 0);
  velocity = .05; // meters/sec
  angle = 0;
  velocity = 0;

  isDebug = false;
}

void Snowman::Draw(){
  Object::Draw();

  glPushMatrix();
  glTranslated(position.x, position.y, position.z);
  glRotatef(angle, 0, 1, 0);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  static GLfloat almostWhiteColor[3] = { 0.9, 0.9, 0.9 };
  static GLfloat almostBlackColor[3] = { 0.1, 0.1, 0.1 };
  static GLfloat almostRedColor[3]   = { 0.9, 0.1, 0.1 };
  static GLfloat bodyRadius = .75;
  static GLfloat headRadius = .25;
  static GLfloat eyesRadius = .02;
  static GLint sphereSlicesAndStacks = 30;

  glColor3fv(almostWhiteColor);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almostWhiteColor);

  // draw body sphere
  glPushMatrix();
  glTranslated(0, bodyRadius, 0);
  glutSolidSphere(bodyRadius, sphereSlicesAndStacks, sphereSlicesAndStacks);
  glPopMatrix();

  // draw head 
  glPushMatrix();
  glTranslated(0, bodyRadius * 2 + headRadius - headRadius / 5, 0);

  //   -> Eyes
  glPushMatrix();
    glColor3fv(almostBlackColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almostBlackColor);
    glTranslatef(.25, .025, .05);
    glutSolidSphere(eyesRadius, sphereSlicesAndStacks, sphereSlicesAndStacks);
    glTranslatef(0, 0, -.10);
    glutSolidSphere(eyesRadius, sphereSlicesAndStacks, sphereSlicesAndStacks);
  glPopMatrix();

  //   -> Nose
  glPushMatrix();
    glColor3fv(almostRedColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almostRedColor);
    glTranslatef(.25, -.025, 0);
    glRotated(90, 0, 1, 0);
    glutSolidCone(eyesRadius, .10, sphereSlicesAndStacks, sphereSlicesAndStacks);
  glPopMatrix();


  //   -> head sphere
  glColor3fv(almostWhiteColor);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almostWhiteColor);
  glutSolidSphere(headRadius, sphereSlicesAndStacks, sphereSlicesAndStacks);
  glPopMatrix();

  glDisable(GL_LIGHTING);

  // DEBUG (direction "arrow" in front of the snowman)
  if(isDebug)
  {
    glColor3f(1, 1, 0); 
    glBegin(GL_LINES);
      glVertex3f(0,            bodyRadius, 0); 
      glVertex3f(bodyRadius*2, bodyRadius, 0); 
    glEnd();    
  }



  glPopMatrix();
}


void Snowman::Update(int deltaTimeMilis){
  Object::Update(deltaTimeMilis);

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
  if(App::Input->IsSpecialKeyPressed(GLUT_KEY_F1)) { isDebug = !isDebug; App::Input->ReleaseSpecialKey(GLUT_KEY_F1); }


}
