/***************************************************************
 * Definições do tipo cggl::App
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "TextWriter.h"

namespace cggl {

  TextWriter::TextWriter()
  {
    SetupWidthHeight(1, 1);
  }

  void TextWriter::SetupWidthHeight(int w, int h)
  {
    width = w;
    height = h;
  }

#pragma region "Modo 'unitário'"

  void TextWriter::WriteImediateText(float x, float y, const char *text, void *font)
  {
    BeginWriteText();
    WriteText(x, y, text, font);
    EndWriteText();
  }

#pragma endregion

#pragma region "Modo 'multiplo'"

  void TextWriter::WriteText(float x, float y, const char *text, void *font) 
  {
    glRasterPos2f(x, y);
    for (const char *c = text; *c != '\0'; c++) {
      glutBitmapCharacter(font, *c);
    }
  }

  void TextWriter::BeginWriteText() {
	  // Mudar para a matriz de projecção
    glMatrixMode(GL_PROJECTION);
	  // Gravar o estado actual
	  glPushMatrix();
	  // Definir uma nova projecção (ortográfica)
	  glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1000);
	  // Inverter o eixo dos YY para termos o Y a crescer para baixo
	  glScalef(1, -1, 1);
	  // Mover a origem para ficar no canto superior esquerdo
	  glTranslatef(0, -height, 0);
    // Passar para a matriz model/view (ficar pronto para desenhar 2D)
	  glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
  }

  void TextWriter::EndWriteText() {
    // Mudar para a matriz de projecção e repor os valores anteriores
	  glMatrixMode(GL_PROJECTION);
	  glPopMatrix();
    // Passar novamente para a matriz model/view (ficar pronto para 3D)
	  glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
  }



#pragma endregion


}

