#include <iostream>

using namespace std;

float PI = 3.1416;

float quad(float number) {
  return number * number;
}

float area_de_un_circulo(float radio) {
  return quad(radio) * PI;
}

float area_de_una_esfera(float radio) {
  return 4 * quad(radio) * PI;
}

int main(){
  float radio;
  float radio_esfera;

  cout << "por favor ingrese el radio de su circulo" << endl;
  cin >> radio;
  cout << "esta es el area de tu circulo " << area_de_un_circulo(radio) << endl;
  cout << "Ingresa el radio de tu esfera" << endl;
  cin >> radio_esfera;
  cout << "Esta es el area de tu esfera " << area_de_una_esfera(radio_esfera) <<endl;
}
