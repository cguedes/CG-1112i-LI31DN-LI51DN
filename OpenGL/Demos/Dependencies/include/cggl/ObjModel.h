/***************************************************************
 * Tipo que representa um modelo Obj (Wavefront OBJ).
 *  
 * Disponibiliza o método void DrawModel() para desenhar o modelo. É utilizada
 *  uma displaylist para desenhar o modelo de forma a aumentar o desempenho da aplicação
 * 
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
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
    float modelScale;           // escala a aplicar ao modelo. Após leitura, o modelo fica com dimensão unitária
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