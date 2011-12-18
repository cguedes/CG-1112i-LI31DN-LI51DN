/**********************************************************************************
 * Declaração do tipo WallTexture. Este tipo representa uma parede na qual é
 *  mapeada uma textura.
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _WALL_WITH_TEXTURE_H
#define _WALL_WITH_TEXTURE_H

#include <cggl/App.h>

class WallWithTexture : public cggl::Object {

  cggl::Vector3 pos;            // posição inicial
  cggl::Vector3 front;          // Vector que indica qual é a frente do objecto
  float width;                  // largura da parede
  float height;                 // altura da parede

  char fileName[FILENAME_MAX];  // ficheiro com a textura
  cggl::glTexture texture;      // identificador da textura

public: 
  WallWithTexture(cggl::Vector3 _pos, cggl::Vector3 _front, float _width, float _height, char* _fileName)
    : pos(_pos), front(_front), width(_width), height(_height)
  { 
    strcpy(fileName, _fileName);
    front.y = 0;
    front.Normalize();
  }

  void Draw();
  void InitGL();

  const cggl::Vector3& GetPosition() { return pos; } ;

};


#endif