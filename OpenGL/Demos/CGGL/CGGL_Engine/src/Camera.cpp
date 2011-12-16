/***************************************************************
 * Definições do tipo cggl::Camera
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "camera.h"
#include <math.h>

namespace cggl {

  Camera::Camera(Vector3 _eye, Vector3 _center, Vector3 _up) {
    LookAt(_eye, _center, _up);
  }

  void Camera::LookAt(Vector3 _eye, Vector3 _center, Vector3 _up) {
    this->eye     = _eye;
    this->center  = _center;
    this->up      = _up;
  }

  void Camera::SetOpenGLCamera()
  {
    gluLookAt(  eye.x,    eye.y,    eye.z, 
                center.x, center.y, center.z, 
                up.x,     up.y,     up.z);
  }

}
