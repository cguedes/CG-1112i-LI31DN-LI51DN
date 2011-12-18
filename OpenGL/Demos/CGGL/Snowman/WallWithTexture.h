/**********************************************************************************
 * Declara��o do tipo WallTexture. Este tipo representa uma parede na qual �
 *  mapeada uma textura.
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _WALL_WITH_TEXTURE_H
#define _WALL_WITH_TEXTURE_H

#include <cggl/App.h>

class WallWithTexture : public cggl::Object {

  cggl::Vector3 pos;            // posi��o inicial
  cggl::Vector3 front;          // Vector que indica qual � a frente do objecto
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