#include <iostream>
#include <fstream>
using namespace std;
int main() {
	string nombre;
	float renta, nota;
	ifstream fin("../solicitantes.txt");//Declaramos fin como variable de entrada
	ofstream fout("../aceptados.txt");//Declaramos fout como variable de salida
	ofstream fbin("../aceptados.bec",ios::out | ios::binary);//Variable binaria
	fin>>nombre;//leemos un campo para saber si estamos en fin de archivo
		while(!fin.eof()){
			fin>> renta >>nota;
			if ((renta<=22000) && (nota>6)) {
				cout << "Allow: " << nombre << " con renta: " << renta << " y nota: "<< nota << endl;
				fout << nombre << " " << renta << " " << nota << endl;
				//Hacemos cast y escribimos en ACEPTADOS.BEC
				fbin.write(reinterpret_cast<const char *>(&nombre), sizeof(string));
				fbin.write(reinterpret_cast<const char *>(&renta), sizeof(float));
				fbin.write(reinterpret_cast<const char *>(&nota), sizeof(float));
			}
			fin>>nombre;//Leemos para saber si estamos en fin de archivo
		}
		fbin.close(),fin.close(),fout.close();
		cout<< "FIN DE ARCHIVO / Se ha generado el archivo binario de aceptados"<<endl;
}