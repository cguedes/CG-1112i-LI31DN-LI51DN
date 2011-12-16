/**********************************************************************************
 * Declara��o do tipo SkyBox. 
 *
 * Uma skyBox serve para aumentar o realismo da aplica��o apresentando um 
 *  conjunto de imagens envolvendo toda a cena. � baseado no mapeamento de 6 
 *  texturas a cada uma das faces de um cubo.
 * 
 * As imagens seguem a seguinte regra:
 *   Esquerda  -> <baseFileName>_left.jpg
 *   Direita   -> <baseFileName>_right.jpg
 *   Frente    -> <baseFileName>_front.jpg
 *   Tras      -> <baseFileName>_back.jpg
 *   Cima      -> <baseFileName>_top.jpg
 *   Baixo     -> <baseFileName>_bottom.jpg
 *
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Janeiro de 2008
 **********************************************************************************/

#ifndef _SKYBOX_H
#define _SKYBOX_H

#include <GL/glut.h>
#include "App.h"

namespace cggl {

  class SkyBox : public cggl::Object {

    char baseFileName[FILENAME_MAX];  // nome base das imagens da skyBox
    cggl::glTexture textures[6];      // texturas (ids OpenGL)
    int distance;                     // Dist�ncia da parede 
    int displayListID;                // Identificador da displayList da SkyBox

  public: 
    SkyBox(char *_baseFileName, int _distance = 500);
    void Draw();
    void InitGL();

  private:
    void DrawWall(int textureIdx, double angleXX, double angleYY);

  };

}

#endif