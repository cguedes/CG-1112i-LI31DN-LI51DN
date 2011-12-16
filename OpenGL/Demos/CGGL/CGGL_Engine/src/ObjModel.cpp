/***************************************************************
 * Definições do tipo cggl::ObjModel
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "objModel.h"

namespace cggl {

  ObjModel::ObjModel(char *_modelFileName, float _modelScale) 
  : modelFileName(_modelFileName), modelScale(_modelScale), model(NULL), modelDisplayListID(-1)
  {
  }

  void ObjModel::InitGL() { 

    Object::InitGL();
    if(model == NULL) 
    {
      model = glmReadOBJ((char*)modelFileName.c_str());
      glmUnitize(model);
      glmFacetNormals(model);
      glmVertexNormals(model, 90.0);
      glmScale(model, modelScale);

    }

    
  }

  void ObjModel::DrawModel()   { 

    // Se o modelo estiver carregado, e a lista 
    //  ainda não tiver sido criada Criar a lista.
    if(model != NULL && modelDisplayListID == -1) {
      modelDisplayListID = glGenLists(1);
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glNewList(modelDisplayListID, GL_COMPILE);
      glmDraw(model, GLM_SMOOTH | GLM_MATERIAL);
      glDisable(GL_LIGHTING);
      glEndList();
    }
    // Desenhar a lista, caso exista
    if(modelDisplayListID != -1)
    {
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glCallList(modelDisplayListID);
      glDisable(GL_LIGHTING);
    }

  }

  void ObjModel::Draw() {

    Object::Draw();
    DrawModel();

  }


}