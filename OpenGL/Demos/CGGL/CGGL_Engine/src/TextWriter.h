/**********************************************************************************
 * Tipo que encapsula o desenho de texto em 2D, na �rea do viewport actual.
 *
 * Modos de funcionamento
 * ========================================
 *   (1) Escrita "unit�ria" de texto
 *   (2) Escrita "multipla" de texto
 *
 * O modo (1) deve ser utilizado quando apenas se pretende escrever uma linha
 *  enquanto que o modo (2) deve ser utilizado quando � necess�rio escrever 
 *  mais do que uma linha. 
 *
 * Utiliza��o
 * ========================================
 *  (1) TextWriterInstance->WriteImediateText(x, y, text, font)
 *
 *  (2) TextWriterInstance->BeginWriteText()
 *      TextWriterInstance->WriteText(x, y, text, font)
 *      TextWriterInstance->EndWriteText()
 *
 *
 * Sistema de coordenadas
 * ========================================
 *  O sistema de coordenadas usado admite o centro est� localizado no canto superior
 *   esquerdo da janela e que o X cresce para a direita e o Y para baixo. 
 *
 *   (0,0)----- X
 *     | #####################
 *     | #                   #
 *     | #                   #
 *     Y #                   #
 *       #####################
 *   
 *
 * Outros aspectos
 * ========================================
 *  - O tipo de fonte usada � definido no par�metro <font> no qual se passam valores
 *      de fonte do GLUT (ex: GLUT_BITMAP_9_BY_15 ou GLUT_BITMAP_HELVETICA_18)
 *
 *  - O texto � desenhado com a cor definida pelos valores presentes na m�quina de 
 *      estados do openGL relativos � cor (ex: glColor3f(r,g,b))
 *
 *
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _CGGL_TEXT_WRITER_H_
#define _CGGL_TEXT_WRITER_H_

#include "globals.h"

namespace cggl {

  class TextWriter {
    
    int width;
    int height;

  public:
    TextWriter();

    // redefini��o da largura/altura do viewport
    void SetupWidthHeight(int w, int h);

    // Modo "unit�rio"
    void WriteImediateText(float x, float y, const char *text, void *font);

    // Modo "multiplo"
    void BeginWriteText();
    void WriteText(float x, float y, const char *text, void *font);
    void EndWriteText();

    int GetMaxX() {return width;}
    int GetMaxY() {return height;}
  };

}

#endif
