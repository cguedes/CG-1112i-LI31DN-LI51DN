/***************************************************************
 * Definições do tipo cggl::FPSCounter
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "FPSCounter.h"

namespace cggl {

  FPSCounter::FPSCounter() 
    : elapsedTimeMilis(0),
      numberOfFramesInstant(0), 
      numberOfFramesPerSecond(0), numberOfFramesPerSecondCounter(0)
  {
    // Sem código.
  }

  void FPSCounter::Update(int deltaTimeMilis) {
    // É essencial colocar a chamada ao respectivo método da classe base
    //   para garantir que os respectivos métodos dos objectos da cena 
    //   são chamados (lista intrusiva).
    Object::Update(deltaTimeMilis);

    this->numberOfFramesInstant = 1000.0 / deltaTimeMilis;
    this->elapsedTimeMilis += deltaTimeMilis;
    if(this->elapsedTimeMilis >= 1000.0) {
      this->numberOfFramesPerSecond = this->numberOfFramesPerSecondCounter;
      this->numberOfFramesPerSecondCounter = 0;
      this->elapsedTimeMilis -= 1000.0;
    }
  }



  void FPSCounter::Draw() 
  {

    // É essencial colocar a chamada ao respectivo método da classe base
    //   para garantir que os respectivos métodos dos objectos da cena 
    //   são chamados (lista intrusiva).
    Object::Draw();

    // Contabilizar este frame
    ++this->numberOfFramesPerSecondCounter;

    int x = App::Writer->GetMaxX() - 100;
    char txtFPSIns[20];
    char txtFPSAve[20];
    sprintf(txtFPSIns, "%d instant", this->numberOfFramesInstant);
    sprintf(txtFPSAve, "%d average", this->numberOfFramesPerSecond);

    // "FPS:"
    glColor3f(1,1,0);
    cggl::App::Writer->WriteImediateText(x, 20, "FPS:", GLUT_BITMAP_9_BY_15);

    // Desenho de texto "multiplo"
    glColor3f(1, 1, 1);
    cggl::App::Writer->BeginWriteText();
    cggl::App::Writer->WriteText(x+10,  40, txtFPSIns, GLUT_BITMAP_8_BY_13);
    cggl::App::Writer->WriteText(x+10,  60, txtFPSAve, GLUT_BITMAP_8_BY_13);
    cggl::App::Writer->EndWriteText();
  }


}