#include <cggl/FPSCounter.h>
#include "Pong.h"
#include "Ball.h"

using namespace cggl;

void Pong::CreateScene() 
{ 
  this->RegisterObject(new FPSCounter());
  this->RegisterObject(new Ball());


  cggl::App::Camera->LookAt(
    // eye
    cggl::Vector3(10, 10, 10),
    // look
    cggl::Vector3(0, 0, 0),
    // up
    cggl::Vector3(0, 1, 0)
  );


}