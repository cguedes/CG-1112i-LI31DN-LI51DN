/***************************************************************
 * Tipos "matemáticos" utilitários
 *   -> Vector3
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

#ifndef _CGGL_MATH_UTILS_H_
#define _CGGL_MATH_UTILS_H_

namespace cggl {

  #ifndef PI
  #define PI 3.1415926535897932384626433832795
  #endif

  #ifndef DEG_TO_RAD
  #define DEG_TO_RAD(deg) (deg *(PI / 180))
  #endif

  #ifndef RAD_TO_DEG
  #define RAD_TO_DEG(rad) (rad *(180 / PI))
  #endif

  struct Vector3 {
    float x, y, z;
    Vector3(float xx = 0, float yy = 0, float zz = 0) : x(xx), y(yy), z(zz) { /* sem código */ }

    float          Magnitude();
    const Vector3& Normalize();

    // Produto externo (cross product) e interno (dot product)
    Vector3 CrossProduct(const Vector3 &v);
    float     DotProduct(const Vector3 &v);

    // Operadores
    Vector3 &operator+=(Vector3 &v)  { this->x += v.x; this->y += v.y; this->z += v.z;  return *this; }
    Vector3 &operator-=(Vector3 &v)  { this->x -= v.x; this->y -= v.y; this->z -= v.z;  return *this; }
    Vector3 &operator+=(float f)     { this->x += f; this->y += f; this->z += f;        return *this; }
    Vector3 &operator-=(float f)     { this->x -= f; this->y -= f; this->z -= f;        return *this; }
    Vector3 &operator*=(float f)     { this->x *= f; this->y *= f; this->z *= f;        return *this; }
    Vector3 &operator/=(float f)     { return this->operator *=(1/f); }
    
    Vector3 operator+(const Vector3 &v) { Vector3 res(x + v.x, y + v.y, z + v.z); return res; }
    Vector3 operator-(const Vector3 &v) { Vector3 res(x - v.x, y - v.y, z - v.z); return res; }
    Vector3 operator+(float f)          { Vector3 res(x + f, y + f, z + f);       return res; }
    Vector3 operator-(float f)          { Vector3 res(x - f, y - f, z - f);       return res; }
    Vector3 operator*(float f)          { Vector3 res(x * f, y * f, z * f);       return res; }
    Vector3 operator/(float f)          { return this->operator*(1/f); }

    Vector3 &operator-()                { x *= -1; y *= -1; z *= -1; return *this;      }


  };

  // Overloads onde o operando Vector3 surge do lado direito da expressão
  Vector3 operator+(float f, const Vector3 &v);
  Vector3 operator-(float f, const Vector3 &v);
  Vector3 operator*(float f, const Vector3 &v);
  Vector3 operator/(float f, const Vector3 &v);

  struct Vector2 {
    float x, y;
    Vector2(float xx = 0, float yy = 0) : x(xx), y(yy) { /* sem código */ }

    float          Magnitude();
    const Vector2& Normalize();

    // Produto externo (cross product) e interno (dot product)
    Vector2 CrossProduct(const Vector2 &v);
    float     DotProduct(const Vector2 &v);

    // Operadores
    Vector2 &operator+=(Vector2 &v)  { this->x += v.x; this->y += v.y; return *this; }
    Vector2 &operator-=(Vector2 &v)  { this->x -= v.x; this->y -= v.y; return *this; }
    Vector2 &operator+=(float f)     { this->x += f; this->y += f;     return *this; }
    Vector2 &operator-=(float f)     { this->x -= f; this->y -= f;     return *this; }
    Vector2 &operator*=(float f)     { this->x *= f; this->y *= f;     return *this; }
    Vector2 &operator/=(float f)     { return this->operator *=(1/f); }

    Vector2 operator+(const Vector2 &v) { Vector2 res(x + v.x, y + v.y); return res; }
    Vector2 operator-(const Vector2 &v) { Vector2 res(x - v.x, y - v.y); return res; }
    Vector2 operator+(float f)          { Vector2 res(x + f, y + f);     return res; }
    Vector2 operator-(float f)          { Vector2 res(x - f, y - f);     return res; }
    Vector2 operator*(float f)          { Vector2 res(x * f, y * f);     return res; }
    Vector2 operator/(float f)          { return this->operator*(1/f); }
    Vector2 &operator-()                { x *= -1; y *= -1; return *this;      }


  };

  // Overloads onde o operando Vector2 surge do lado direito da expressão
  Vector2 operator+(float f, const Vector2 &v);
  Vector2 operator-(float f, const Vector2 &v);
  Vector2 operator*(float f, const Vector2 &v);
  Vector2 operator/(float f, const Vector2 &v);
}
#endif