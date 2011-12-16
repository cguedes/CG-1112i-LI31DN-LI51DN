/***************************************************************
 * Defini��es do tipo cggl::Object
 *
 * (c) Carlos Guedes e Jos� Branco - Novembro de 2007
 ***************************************************************/

#include "object.h"

namespace cggl {

#pragma region "Constru��o"

  Object::Object() 
    : next(0)
  {
    // Sem c�digo.
  }

#pragma region "M�todos Draw, Update e InitGL"

  // Chama o Draw do pr�ximo objecto, se existir.
  void Object::Draw() {
    if(next != 0)
      next->Draw();
  }

  // Chama o Update do pr�ximo objecto, se existir.
  void Object::Update(int deltaTimeMilis) {
    if(next != 0)
      next->Update(deltaTimeMilis);
  }

  // Chama o Update do pr�ximo objecto, se existir.
  void Object::InitGL(){
    if(next != 0)
      next->InitGL();
  }
#pragma endregion

}