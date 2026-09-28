#include "interface/SistemaDeSuporte.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {

#ifdef _WIN32
    // no windows isso evita que os acentos saiam todos quebrados no console
    SetConsoleOutputCP(CP_UTF8);
#endif

    // o menu concentra o uso do sistema aqui so iniciamos e deixamos ele trabalhar
    SistemaDeSuporte sistema;
    sistema.executar();

    return 0;
}
