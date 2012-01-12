#ifndef _BALL_H_
#define _BALL_H_

#include <cggl/Object.h>

class Ball : public cggl::Object
{

  cggl::Vector3 position;

public: 

  Ball(); 

  void Draw();
  void Update(int deltaTimeMilis);

};

#endif