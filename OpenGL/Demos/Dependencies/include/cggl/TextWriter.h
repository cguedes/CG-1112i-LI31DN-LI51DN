/**********************************************************************************
 * Tipo que encapsula o desenho de texto em 2D, na área do viewport actual.
 *
 * Modos de funcionamento
 * ========================================
 *   (1) Escrita "unitária" de texto
 *   (2) Escrita "multipla" de texto
 *
 * O modo (1) deve ser utilizado quando apenas se pretende escrever uma linha
 *  enquanto que o modo (2) deve ser utilizado quando é necessário escrever 
 *  mais do que uma linha. 
 *
 * Utilização
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
 *  O sistema de coordenadas usado admite o centro está localizado no canto superior
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
 *  - O tipo de fonte usada é definido no parâmetro <font> no qual se passam valores
 *      de fonte do GLUT (ex: GLUT_BITMAP_9_BY_15 ou GLUT_BITMAP_HELVETICA_18)
 *
 *  - O texto é desenhado com a cor definida pelos valores presentes na máquina de 
 *      estados do openGL relativos à cor (ex: glColor3f(r,g,b))
 *
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

#ifndef _CGGL_TEXT_WRITER_H_
#define _CGGL_TEXT_WRITER_H_

#include "globals.h"

namespace cggl {

  class TextWriter {
    
    int width;
    int height;

  public:
    TextWriter();

    // redefinição da largura/altura do viewport
    void SetupWidthHeight(int w, int h);

    // Modo "unitário"
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
