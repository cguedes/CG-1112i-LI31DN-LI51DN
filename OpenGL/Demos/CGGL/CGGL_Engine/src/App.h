/**********************************************************************************
 * Tipo base de aplica��es CGGL.
 * Representa o motor de jogo. 
 * Regista-se no GLUT e gera eventos de ciclo de vida da aplica��o.
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

#ifndef _CGGL_APP_H_
#define _CGGL_APP_H_

#include <string>
#include "Globals.h"

#include "Object.h"
#include "Input.h"
#include "TextWriter.h"
#include "Camera.h"
#include "TextureLoader.h"


namespace cggl {

  class App {

    // Configura��es da aplica��o
    int width, height;
    int windowX, windowY;
    std::string name;
    unsigned int timerMilisDelta;
    
    // Raiz da lista de objectos da cena
    Object *root;

    // Entidades "singleton" da aplica��o
  public:
    static App *Instance;       // App Singleton Instance

    // Campos intrinsecos da aplica��o
    static Input *Input;                  // Input  (Teclado)
    static TextWriter *Writer;            // Writer (escrita de texto 2D)
    static Camera *Camera;                // Camera (C�mara virtual)
    static TextureLoader *TextureLoader;  // TextureLoader (Carregamento de texturas 2D)

  public:
    App();
    
    virtual void CreateScene() = 0;
    virtual void Draw();
    virtual void Update(int deltaTimeMilis);
    virtual void InitGL();
    virtual void Run(int argc, char **argv);
    
    void RegisterObject(Object *);
    void ClearObjects();

    int GetWidth()    {return width;}
    int GetHeight()   {return height;}
  private:

    // GLUT callbacks -------------------------------------------------------------------
    static void DisplayCallback();
    static void UpdateCallback(int lastTime);
    static void ReshapeCallback(int w,int h);
    static void KeyDownCallback(unsigned char key, int x, int y);
    static void KeyUpCallback  (unsigned char key, int x, int y);
    static void SpecialKeyDownCallback(int key, int x, int y);
    static void SpecialKeyUpCallback  (int key, int x, int y);
    // ----------------------------------------------------------------------------------

    /*
    void Init();
    void InitGL();
    */

  };

}


#endif
