#include <iostream>
#include "Tablero.h"
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include "Juego.h"
#include "Tablero.h"
#include "LogicaDeMovimiento.h"
#include "VistaConsola.h"
#include "Avatar.h"
#include <cstdlib>

int main() {
    // Crear un tablero (igual que en tu código original)
    Tablero tablero;
    tablero.cargarDesdeArchivo("dataTablero.txt");
    
    // Crear el avatar (igual que en tu código original)
    Avatar avatar;
    avatar.setPosicionFila(2);
    avatar.setPosicionColumna(2);
    
    // Crear la lógica de movimiento (igual que en tu código original)
    LogicaDeMovimiento logicaDeMovimiento;
    
    // Crear juego (igual que en tu código original)
    Juego juego(&tablero, &avatar, &logicaDeMovimiento, true);
    juego.iniciar();
    
    VistaConsola vista(&tablero, &avatar);
    
    // Bucle del juego (igual que en tu código original)
    do {
        vista.mostrarJuego();
        vista.mostrarMensaje("Digite su movimiento:");
        juego.play(vista.getEntradaConsola());
    } while(juego.getWin() == false && juego.getEstado() == true);

    // Mensajes finales (igual que en tu código original)
    if (juego.getWin() == true) {
        vista.mostrarMensaje("Ganaste el juego, el total de puntos es:" + std::to_string(juego.getPuntaje()));
    } else {
        vista.limpiarPantalla();
        vista.mostrarMensaje("Perdiste el juego, el total de puntos es:0");
    }
    
    return 0;
}