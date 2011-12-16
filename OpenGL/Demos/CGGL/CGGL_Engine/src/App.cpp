/***************************************************************
 * Definições do tipo cggl::App
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include <WINDOWS.H>
#include <MMSYSTEM.H>
#include "app.h"
#include <GL/glut.h>

namespace cggl {

#pragma region "Construção"

  App            *App::Instance       = NULL;
  Input          *App::Input          = NULL;
  TextWriter     *App::Writer         = NULL;
  Camera         *App::Camera         = NULL;
  TextureLoader  *App::TextureLoader  = NULL;

  App::App() 
  {
    // Garantir que apenas existe uma instância deste tipo.
    assert(App::Instance == NULL);

    this->root = NULL;

    // Valores por omissão.
    this->width = 800;
    this->height = 600;
    this->windowX = 150;
    this->windowY = 100;
    this->name = "CGGL Game";
    this->timerMilisDelta = 1000.0/100;   // 10ms -> MAX de 100fps

    // Objectos intrinsecos
    App::Input          = new cggl::Input();
    App::Camera         = new cggl::Camera();
    App::Writer         = new TextWriter();
    App::TextureLoader  = new cggl::TextureLoader();

    // Definir a instância da aplicação
    App::Instance = this;
  }

#pragma endregion

#pragma region "Run..."

  void App::Run(int argc, char **argv) 
  {
	  // Inicialização HW e App
	  glutInit(&argc, argv);
	  glutInitDisplayMode(GLUT_DOUBLE /* doubleBuffering */| GLUT_RGBA /* RGBA ColorBuffer */ | GLUT_DEPTH /* ZBuffer */);

	  // Inicialização da Janela
    glutInitWindowSize(this->width, this->height);
	  glutInitWindowPosition(this->windowX, this->windowY);
	  glutCreateWindow(this->name.c_str());
	  // Registo das Callback
    glutDisplayFunc   (App::DisplayCallback);
    glutReshapeFunc   (App::ReshapeCallback);
    glutKeyboardFunc  (App::KeyDownCallback);
    glutKeyboardUpFunc(App::KeyUpCallback);
    glutSpecialFunc   (App::SpecialKeyDownCallback);
    glutSpecialUpFunc (App::SpecialKeyUpCallback);

    // Criação/iniciação da aplicação
    this->CreateScene();

    // InitScene 
    this->InitGL();
    
    glClearColor(0.1, 0.1, 0.1, 0.0);  
    glEnable(GL_DEPTH_TEST);

    glutTimerFunc(this->timerMilisDelta, App::UpdateCallback, timeGetTime());

    // Lançamento do GLUT Event Loop
    //  NOTA: A aplicação fica bloqueada aqui
    //        A partir deste ponto são chamadas as funções de update, reshape e draw
	  glutMainLoop();

    this->ClearObjects();
  }

#pragma endregion

#pragma region "GLUT Callbacks (Reshape, Display, Update, Keyboard)"

  void App::ReshapeCallback(int w,int h) {
    App::Instance->width = w;
    App::Instance->height = h;
    App::Writer->SetupWidthHeight(w, h);

    float aspectRatio = ((float)w) / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
  }

  //--------------------------------------------------------------------------------
  void App::DisplayCallback(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // definição da câmara
    App::Camera->SetOpenGLCamera();

    // Desenho da cena
    App::Instance->Draw();

    // Trocar os buffers (doubleBuffering)
    glutSwapBuffers();
  }
  //--------------------------------------------------------------------------------
  void App::UpdateCallback(int lastTime) {
    int currentTime = timeGetTime();
    int deltaTime = currentTime - lastTime;

    // Actualizar a cena
    App::Instance->Update(deltaTime);

    // Voltar a registar o timer (para que a função volte a ser chamada daqui a XXms)
    glutTimerFunc(App::Instance->timerMilisDelta, App::UpdateCallback, currentTime);

    // Voltar a desenhar
    glutPostRedisplay();
  }
  //--------------------------------------------------------------------------------
  void App::KeyDownCallback(unsigned char key, int x, int y) {
    App::Input->PressKey(key);
  }
  void App::KeyUpCallback  (unsigned char key, int x, int y) {
    App::Input->ReleaseKey(key);
  }
  void App::SpecialKeyDownCallback(int key, int x, int y) {
    App::Input->PressSpecialKey(key);
  }
  void App::SpecialKeyUpCallback  (int key, int x, int y) {
    App::Input->ReleaseSpecialKey(key);
  }
  //--------------------------------------------------------------------------------

#pragma endregion

#pragma region "Métodos Draw, Update e InitGL: chamar métodos respectivos na lista de objectos"

  // "Percorre" a lista de objectos a fazer Draw...
  void App::Draw() {
    if(root != NULL)
      root->Draw();
  }

  // "Percorre" a lista de objectos a fazer Update...
  void App::Update(int deltaTimeMilis) {
    if(root != NULL)
      root->Update(deltaTimeMilis);
  }

  // "Percorre" a lista de objectos a fazer InitGL...
  void App::InitGL() {
    if(root != NULL)
      root->InitGL();
  }
#pragma endregion

#pragma region "Gestão de objectos"

  void App::RegisterObject(Object *obj) {
    // Acrescentar o objecto à lista de objectos (passa a ser o primeiro da lista)
    obj->next = this->root;
    this->root = obj;
  }

  void App::ClearObjects(){

    Object *obj = this->root, *next;
	  while(obj != NULL)
    {
      next = obj->next;
      delete obj;
    }
  }

#pragma endregion

}