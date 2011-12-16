/**********************************************************************************
 * Definição do tipo SkyBox. 
 *
 * (c) Carlos Guedes e José Branco - Janeiro de 2008
 **********************************************************************************/

#include "SkyBox.h"

namespace cggl {

  SkyBox::SkyBox(char *_baseFileName, int _distance) 
      : distance(_distance), displayListID(-1)
  {
      strcpy(baseFileName, _baseFileName);
  }

  void SkyBox::Draw()
  {
    Object::Draw();

    if(displayListID) {
      displayListID = glGenLists(1);
      glNewList(displayListID, GL_COMPILE_AND_EXECUTE);

      glDisable(GL_LIGHTING);
      glEnable(GL_TEXTURE_2D);

      DrawWall(0,   0,  90);   // Esquerda  
      DrawWall(1,   0, -90);   // Direita   
      DrawWall(2,   0,   0);   // Frente    
      DrawWall(3,   0, 180);   // Tras      
      DrawWall(4,  90,   0);   // Cima      
      DrawWall(5, -90,   0);   // Baixo     
      
      glDisable(GL_TEXTURE_2D);

      glEndList();

    } else {
      glCallList(displayListID);
    }

  }

  void SkyBox::InitGL() {
    Object::InitGL();

    char *fileNameSuffix[6] = {
      "_left.jpg",
      "_right.jpg",
      "_front.jpg",
      "_back.jpg",
      "_top.jpg",
      "_bottom.jpg"
    };

    for(int i = 0; i < 6; ++i) {
      char fileName[FILENAME_MAX];
      sprintf(fileName, "%s%s", this->baseFileName, fileNameSuffix[i]);
      cggl::App::TextureLoader->LoadTextureFromDisk(fileName, &textures[i]);
    }

  }


  void SkyBox::DrawWall(int textureIdx, double angleXX, double angleYY) {
    glBindTexture(GL_TEXTURE_2D, textures[textureIdx].TextureID);
    glPushMatrix();
    if(angleXX != 0.0) glRotated(angleXX, 1, 0, 0);
    if(angleYY != 0.0) glRotated(angleYY, 0, 1, 0);
    glTranslated(0, 0, -distance);
    glScaled(distance*2, distance*2, 1);
    glBegin( GL_QUADS ); 
      glTexCoord2f(0, 0);
      glVertex3f(-0.5f, -0.5f, 0);
      
      glTexCoord2f(1, 0);
      glVertex3f(+0.5f, -0.5f, 0);
      
      glTexCoord2f(1, 1);
      glVertex3f(+0.5f, +0.5f, 0);
      
      glTexCoord2f(0, 1);
      glVertex3f(-0.5f, +0.5f, 0);
    glEnd();
    glPopMatrix();
  }

}