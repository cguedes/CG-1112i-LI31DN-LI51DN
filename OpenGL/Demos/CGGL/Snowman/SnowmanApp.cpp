#include <GL/glut.h>
#include <cggl/App.h>
#include <cggl/FPSCounter.h>
#include <cggl/ObjModel.h>

#include "SnowmanApp.h"
#include "Axis.h"
#include "SimplePlane.h"
#include "Snowman.h"
#include "Car.h"

using namespace cggl;
  
void SnowmanApp::CreateScene() 
{
    RegisterObject( new Axis() );
    RegisterObject( new FPSCounter() );
    RegisterObject( new SimplePlane(0, 40) );
    
    RegisterObject( snowman = new Snowman(Vector3(0, 0, 0)) );
    //RegisterObject( new Car(Vector3(0, 0, 0)) );


    // Setup default camera (#4)
    App::Camera->LookAt(Vector3(10, 5, 10), Vector3(0,1,0), Vector3::UP);
}

void SnowmanApp::Draw() 
{
  App::Draw();
}

void SnowmanApp::Update(int deltaTimeMilis) 
{
	if(App::Input->IsKeyPressed('x')) exit(0);

  if(App::Input->IsKeyPressed('1')) App::Camera->LookAt(Vector3(2, 3, 4), Vector3(0,1,0),   Vector3::UP); 
  if(App::Input->IsKeyPressed('2')) App::Camera->LookAt(Vector3(5, 1, 0), Vector3(0,1,0),   Vector3::UP); 
  if(App::Input->IsKeyPressed('3')) App::Camera->LookAt(Vector3(0, 1, 5), Vector3(0,1,0),   Vector3::UP); 
  if(App::Input->IsKeyPressed('4')) App::Camera->LookAt(Vector3(10, 5, 10), Vector3(0,1,0), Vector3::UP); 

  if(App::Input->IsKeyPressed('0')) App::Camera->LookAt(Vector3(0, 30, 0), Vector3(0,0,0), Vector3(0,0,-1)); 

  // snowman tracking (experimental version)
  if(App::Input->IsKeyPressed('t'))
  {
    Vector3 eye = snowman->GetPosition() - snowman->GetDirection() * 4 + Vector3(0,1,0) * 4;
    Vector3 center = snowman->GetPosition() + snowman->GetDirection() + Vector3(0,1,0) * 2;
    App::Camera->LookAt(eye, center, Vector3::UP); 
  }


	App::Update(deltaTimeMilis);
}




// ------------------------------------------------------------------------------------
void main(int argc, char **argv) {
  SnowmanApp app;
  app.Run(argc, argv);
}
// ------------------------------------------------------------------------------------
