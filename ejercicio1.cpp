#include <string>
#include <vector>
using namespace std;

class Equipo {
private:
    string codigo;
    string marca;
    bool encendido;
public:
    Equipo(string codigo, string marca) {
        this->codigo = codigo;
        this->marca = marca;
        this->encendido = false;
    }
    void encender() {
        encendido = true;
    }
    void apagar() {
        encendido = false;
    }
    bool estaEncendido() {
        return encendido;
    }
};

class Laboratorio {
private:
    string nombre;
    vector<Equipo*> equipos;
public:
    Laboratorio(string nombre) {
        this->nombre = nombre;
    }
    void agregarEquipo(Equipo* equipo) {
        equipos.push_back(equipo);
    }
    int cantidadEncendidos() {
        int contador = 0;
        for (int i = 0; i < (int)equipos.size(); i++) {
            if (equipos[i]->estaEncendido()) {
                contador++;
            }
        }
        return contador;
    }
};

int main() {
    Laboratorio lab("Laboratorio 101");
    Equipo pc1("PC-01", "Dell");
    Equipo pc2("PC-02", "HP");
    lab.agregarEquipo(&pc1);
    lab.agregarEquipo(&pc2);
    pc1.encender();
    return 0;
}
