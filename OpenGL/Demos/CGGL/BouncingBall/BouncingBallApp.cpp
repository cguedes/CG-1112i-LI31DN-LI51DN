#include <GL/glut.h>
#include <cggl/App.h>
#include <cggl/FPSCounter.h>

#include "BouncingBallApp.h"
#include "Ball.h"
#include "SimplePlane.h"

using namespace cggl;
  
void BouncingBallApp::CreateScene() {
  RegisterObject( ball = new Ball(Vector3(-10, 2, 0), 2) );
  RegisterObject( new Ball(Vector3(10, 4, 0), 2) );

  RegisterObject( new SimplePlane(0, 100) );
  RegisterObject( new FPSCounter() );
}

void BouncingBallApp::Draw() 
{
  App::Draw();
}

void BouncingBallApp::Update(int deltaTimeMilis) 
{
	if(App::Input->IsKeyPressed('c'))
	{
		App::Camera->LookAt(Vector3(0, 20, 50), 
							ball->getPosition(), 
							Vector3(0,1,0));
	}
	else
	{
		App::Camera->LookAt(Vector3(0, 20, 50), 
						  Vector3(0,20,0), 
						  Vector3(0,1,0));
	}

	App::Update(deltaTimeMilis);
}




// ------------------------------------------------------------------------------------
void main(int argc, char **argv) {
  BouncingBallApp app;
  app.Run(argc, argv);
}
// ------------------------------------------------------------------------------------
