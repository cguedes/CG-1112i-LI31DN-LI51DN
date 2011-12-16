/***************************************************************
 * Definições do tipo cggl::Input
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "Input.h"

namespace cggl {

  Input::Input() {
    for(int i = 0; i < CGGL_INPUT_MAX_KEYS; ++i) {
      asciiKeys[i] = false;
      specialKeys[i] = false;
    }
  }

  void Input::PressKey(unsigned char k) {
    asciiKeys[k] = true;
  }

  void Input::ReleaseKey(unsigned char k) {
    asciiKeys[k] = false;
  }

  int  Input::IsKeyPressed(unsigned char k) {
    return (asciiKeys[k] == true);
  }

  void Input::PressSpecialKey(int k) {
    specialKeys[k] = true;
  }

  void Input::ReleaseSpecialKey(int k) {
    specialKeys[k] = false;
  }

  int  Input::IsSpecialKeyPressed(int k) {
    return (specialKeys[k] == true);
  }

}