/***************************************************************
 * Definições dos tipos
 *   - cggl::Vector2
 *   - cggl::Vector3
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "mathUtils.h"
#include <math.h>

namespace cggl {

  float Vector3::Magnitude() {
    return sqrt( x * x + y * y + z * z );
  }
  const Vector3& Vector3::Normalize() {
    float mag = Magnitude();
    if(mag != 0)
    {
      x /= mag;
      y /= mag;
      z /= mag;
    }
    return *this;
  }

  /* Produto externo (cross product)
   *  Retorna o vector normal aos vectores this e v (sistema mão direita).
   *  
   *        | V
   *        |  
   *        +----- U (this)
   *       /
   *      / 
   *   U x V 
   *
   * Equação:
   * ===============================
   *   
   *           | x  y  z  |
   *   U x V = | Ux Uy Uz |
   *           | Vx Vy Vz |
   *
   *
   * Fonte: http://mathworld.wolfram.com/CrossProduct.html
   */
  Vector3 Vector3::CrossProduct(const Vector3 &v) {
      
    Vector3 res;
    res.x = this->y * v.z - this->z * v.y;
    res.y = this->z * v.x - this->x * v.z;
    res.z = this->x * v.y - this->y * v.x;  
    return res;
  }

  /* Produto interno (dot product)
   *  Retorna o coseno do angulo formado entre os vectores this e v.
   *  Assume que os vectores estão normalizados.
   *
   *  Equação:
   *  ===============================
   *   A.B = |A||B|cos(b)
   *   A.B = Ax.Bx + Ay.By
   *
   *  Notas:
   *  ===============================
   *   A.B = 0 quando os vectores são perpendiculares
   *
   *  Fontes: http://mathworld.wolfram.com/DotProduct.html
   *          http://www.cs.brown.edu/exploratories/freeSoftware/repository/edu/brown/cs/exploratories/applets/dotProduct/dot_product_guide.html
   */
  float Vector3::DotProduct(const Vector3 &v) {
    return x*v.x + y*v.y + z*v.z;
  }



  // Overloads onde o operando Vector3 surge do lado direito da expressão
  Vector3 operator+(float f, const Vector3 &v) { return Vector3(f+v.x, f+v.y, f+v.z); }
  Vector3 operator-(float f, const Vector3 &v) { return Vector3(f-v.x, f-v.y, f-v.z); }
  Vector3 operator*(float f, const Vector3 &v) { return Vector3(f*v.x, f*v.y, f*v.z); }
  Vector3 operator/(float f, const Vector3 &v) { return Vector3(f/v.x, f/v.y, f/v.z); }

  // constantes (em relação ao plano XY - 2D)
  const Vector3 Vector3::UP = Vector3(0, 1, 0);
  const Vector3 Vector3::DOWN = Vector3(0, -1, 0);
  const Vector3 Vector3::LEFT = Vector3(-1, 0, 0);
  const Vector3 Vector3::RIGHT = Vector3(1, 0, 0);
  const Vector3 Vector3::FRONT = Vector3(0, 0, -1);
  const Vector3 Vector3::BACK = Vector3(0, 0, 1);

}






/* Testes.... 
void main(int argc, char **argv) {
  Vector3 vx(1, 0, 0);
  Vector3 vy(0, 1, 0);
  Vector3 vz = vx.CrossProduct(vy);
  printf("(x,y,z) = (%.2f, %.2f, %.2f)\n", vz.x, vz.y, vz.z);

  float cosAngleVxVz = vx.DotProduct(vz);
  printf("cosAngleVxVz = %.2f\n", cosAngleVxVz);

  Vector3 h = (vx + vy) * 3;
  printf("h(x,y,z) = (%.2f, %.2f, %.2f)\n", h.x, h.y, h.z);
  printf("h.Magnitude() = %.2f\n", h.Magnitude());
  h = h.Normalize();
  printf("|h|.Magnitude() = %.2f\n", h.Magnitude());
  h.z = 0.2;
  h = h.Normalize();
  Vector3 hCrossVx = h.CrossProduct(vx);
  printf("hCrossVx(x,y,z) = (%.2f, %.2f, %.2f)\n", hCrossVx.x, hCrossVx.y, hCrossVx.z);
  Vector3 vXCrossH = vx.CrossProduct(h);
  printf("vXCrossH(x,y,z) = (%.2f, %.2f, %.2f)\n", vXCrossH.x, vXCrossH.y, vXCrossH.z);
}

// */