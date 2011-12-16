/***************************************************************
 * Tipo que representa um modelo Obj (Wavefront OBJ).
 *  
 * Disponibiliza o m�todo void DrawModel() para desenhar o modelo. � utilizada
 *  uma displaylist para desenhar o modelo de forma a aumentar o desempenho da aplica��o
 * 
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electr�nica e Telecomunica��es e de Computadores
 * Licenciatura em Engenharia Inform�tica e de Computadores
 * Computa��o Gr�fica
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _OBJ_MODEL_H_
#define _OBJ_MODEL_H_

#include "Object.h"
#include <string>
#include "glm.h"

namespace cggl {

  class ObjModel : public cggl::Object {

  protected:
    std::string modelFileName;
    float modelScale;           // escala a aplicar ao modelo. Ap�s leitura, o modelo fica com dimens�o unit�ria
    GLMmodel *model;            // Pointer para a estrutura que representa o modelo
    int modelDisplayListID; 

  public:
    ObjModel(char *_modelFileName, float modelScale = 1.0f);

    void InitGL();
    void DrawModel();
    void Draw();

  };

}

#endif