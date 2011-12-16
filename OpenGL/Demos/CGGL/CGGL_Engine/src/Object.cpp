/***************************************************************
 * Definições do tipo cggl::Object
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "object.h"

namespace cggl {

#pragma region "Construção"

  Object::Object() 
    : next(0)
  {
    // Sem código.
  }

#pragma region "Métodos Draw, Update e InitGL"

  // Chama o Draw do próximo objecto, se existir.
  void Object::Draw() {
    if(next != 0)
      next->Draw();
  }

  // Chama o Update do próximo objecto, se existir.
  void Object::Update(int deltaTimeMilis) {
    if(next != 0)
      next->Update(deltaTimeMilis);
  }

  // Chama o Update do próximo objecto, se existir.
  void Object::InitGL(){
    if(next != 0)
      next->InitGL();
  }
#pragma endregion

}