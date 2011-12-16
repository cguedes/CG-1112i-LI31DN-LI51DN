/**********************************************************************************
 * Tipo base de objectos em aplicações CGGL.
 * Representa estidades com representação gráfica e dinâmica (actualização do estado)
 * 
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _CGGL_OBJECT_H_
#define _CGGL_OBJECT_H_


namespace cggl {

    class Object {
    
    // suporte à lista intrusiva
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
