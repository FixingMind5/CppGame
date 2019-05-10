#include <iostream>
#include <fstream>

using namespace std;

int main(){
  string lines, first_line = "lksdbncliwdnclwd", second_line, third_line;
  int line;
  // sirve para la salida de datos out-stream
  ofstream MyFile("GameData.txt"); //Crea un archivo con el nombre de "GameData"

  if (MyFile.is_open()) { //va a revisar si está abierto

    //Los datos se mandan al archivo en lugar de a la consola
    MyFile << "Hola Platzi!!" << endl;
    MyFile << "Es un buen curso este!!" << endl;
    MyFile << "Quiero tener el mundo a mis pies" << endl;

  }

  //Para permitir que el sistema operativo haga con ella
  //lo que quiera
  //MyFile.close();

  //Entrada de datos in-stream
  ifstream MyFileRead("GameData.txt");

  if (MyFile.is_open()) {
    while (getline(MyFileRead, lines)) {
      if (line == 0) {
        first_line = lines;
      } else if (line == 1) {
        second_line = lines;
      } else if (line == 2) {
        third_line = lines;
      }
      line++;
    }
  } else {
    cout << "No logré abrir el archivo" << endl;
  }

  cout << first_line << endl;
  cout << second_line << endl;
  cout << third_line << endl;
}
