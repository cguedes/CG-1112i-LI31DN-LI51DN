/**********************************************************************************
 * Defini��o do tipo WallWithTexture.
 *
 * (c) Carlos Guedes e Jos� Branco - Janeiro de 2008
 **********************************************************************************/

#include <cggl/App.h>
#include <cggl/MathUtils.h>
#include <cggl/TextureLoader.h>
#include "WallWithTexture.h"

using namespace cggl;

void WallWithTexture::Draw() {
  Object::Draw();

  // Sabendo que a parede tem que ser desenhada de forma a parecer uma parede
  //  (na vertical) apenas � necess�rio definir a rota��o em torno de YY.
  //  
  // Para fazer isso, basta calcular o produto interno entre a frente da parede
  //  desenhada (drawingFront -> neste caso � em direc��o a +Z) e a frente que se 
  //  pretende considerar (membro front). Sabe-se que o produto interno pode ser
  //  utilizado da seguinte forma:
  //
  //                     vec1 DOT vec2
  //    angle = arcos (-----------------)
  //                    |vec1| * |vec2|
  Vector3 drawingFront(0,0,1);
  float dot = drawingFront.DotProduct(front);
  float angleRAD = acos( dot );
  float angleDEG = RAD_TO_DEG(angleRAD);

  // Activar a utiliza��o de texturas
  glEnable(GL_TEXTURE_2D);
  // Indicar que deve ser utilizada a textura (texture.TextureID), definida no InitGL
  glBindTexture(GL_TEXTURE_2D, texture.TextureID);


  glPushMatrix();
  glTranslated(pos.x, pos.y, pos.z);
  glRotated(angleDEG, 0, 1, 0);
  glScaled(width, height, 1);


  // Ao desenhar o poligono � necess�rio definir, por v�rtice, qual � 
  //  a coordenada de textura correspondente, ou seja, que "pixel" da 
  //  textura est� associada a cada um dos v�rtices do pol�gono.
  // As quadriculas do pol�gono s�o preenchidas atrav�s da interpola��o 
  //  dos valores de textura definidos para os v�rtices (como nas cores)

  glBegin( GL_QUADS ); 
    glTexCoord2f(0, 0); // Associar o v�rtice seguinte � posi��o (0,0) da textura
    glVertex3f(-0.5f, -0.5f, 0);
    
    glTexCoord2f(1, 0);
    glVertex3f(+0.5f, -0.5f, 0);
    
    glTexCoord2f(1, 1);
    glVertex3f(+0.5f, +0.5f, 0);
    
    glTexCoord2f(0, 1);
    glVertex3f(-0.5f, +0.5f, 0);
  glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
    
}

void WallWithTexture::InitGL() {
  Object::InitGL();
  // Carregar a textura do disco e guard�-la (o seu identificador) na estrutura texture
  App::TextureLoader->LoadTextureFromDisk(fileName, &texture);
}