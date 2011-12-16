/**********************************************************************************
 * Tipo base de objectos em aplica��es CGGL.
 * Representa estidades com representa��o gr�fica e din�mica (actualiza��o do estado)
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

#ifndef _CGGL_OBJECT_H_
#define _CGGL_OBJECT_H_


namespace cggl {

    class Object {
    
    // suporte � lista intrusiva
    Object *next;
    friend class App;

  public:
    Object();

    virtual void Draw();
    virtual void Update(int deltaTimeMilis);
    virtual void InitGL();
  };

}


#endif
