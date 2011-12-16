/**********************************************************************************
 * Tipo que representa uma câmara, através da qual é vista a cena.
 *
 * É composto por:
 *   -> eye    (olho)
 *   -> center (local para onde está a olhar)
 *   -> up     (rotação em torno de [center-eye])
 *
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _CGGL_CAMERA_H_
#define _CGGL_CAMERA_H_

#include "globals.h"
#include "mathUtils.h"

namespace cggl {

  class Camera {
    Vector3 eye;
    Vector3 center;
    Vector3 up;

  public:
    Camera( Vector3 _eye    = Vector3(0, 0,  2.41), // 2.41 = 1 / tg(45º/2)
            Vector3 _center = Vector3(0, 0,  0),    //  -> Para ficar "igual" ao valor por omissão 
            Vector3 _up     = Vector3(0, 1,  0)  ); //  -> do OpenGL, em Z=0. ==> X:[-1,1] Y:[-1,1]

    // Definição da posição/orientação da câmara
    void LookAt(Vector3 _eye, Vector3 _center, Vector3 _up);

    void SetOpenGLCamera();

    // Acessores de leitura
    const Vector3 &GetEye()    { return eye;    }
    const Vector3 &GetCenter() { return center; }
    const Vector3 &GetUp()     { return up;     }
  };

}
#endif