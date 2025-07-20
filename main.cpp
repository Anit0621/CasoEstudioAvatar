/*
CASO DE ESTUDIO - PUNTO DE AVATAR CPU
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma Gonzalez
Codigo: 202242058
Correo: valentina.montezuma@correounivalle.edu.co


Descripcion de caso:

Se implementó en el repositorio de GitHub una actualización que añade dos avatares al juego: el avatar principal controlado 
por el jugador usando WASD, que puede ganar alcanzando la salida o perder cayendo en abismos, de este se hizo la implementacion 
que estaba pendiente y se mostro en la guia del caso de estudio. Por otra parte se hizo tambien la implementacion del AvatarCPU 
que se mueve automáticamente en direcciones aleatorias por el tablero sin afectar la jugabilidad principal, se hizo aplicando lo
de la guia y adicional a esto modificandola para que cumpliera con el polimorfismo segun las guias vistas. 
Mientras el jugador se enfoca en su objetivo, el AvatarCPU se desplaza de forma independiente añadiendo dinamismo visual al juego, 
manteniendo intactas las mecánicas originales donde solo el avatar controlado determina el resultado final.

*/


#include <iostream>
#include "Tablero.h"
#include "Juego.h"
#include "LogicaDeMovimiento.h"
#include "VistaConsola.h"
#include "Avatar.h"
#include "AvatarCPU.h"
#include <vector>

int main() {
    // Configuración inicial
    Tablero tablero;
    tablero.cargarDesdeArchivo("dataTablero.txt");
    
    // Creación de personajes
    Avatar* jugador = new Avatar();
    AvatarCPU* cpu = new AvatarCPU();
    
    // Posiciones iniciales
    jugador->setPosicionFila(2);
    jugador->setPosicionColumna(2);
    cpu->setPosicionFila(10);
    cpu->setPosicionColumna(5);
    
    // Vector para la vista
    std::vector<IPersonaje*> personajes = {jugador, cpu};
    
    // Sistema del juego
    LogicaDeMovimiento logica;
    Juego juego(&tablero, jugador, &logica, true);
    VistaConsola vista(&tablero, personajes); // Ahora con 2 parámetros correctos
    
    // Bucle principal
    while(juego.getEstado()) {
        vista.mostrarJuego();
        vista.mostrarMensaje("Digite su movimiento (WASD):");
        
        char input = vista.getEntradaConsola();
        
        // Mover personajes
        jugador->mover(input);
        cpu->mover(input);
        
        juego.play(input);
    }

    // Resultado final
    if(juego.getWin()) {
        vista.mostrarMensaje("¡Ganaste! Puntos: " + std::to_string(juego.getPuntaje()));
    } else {
        vista.mostrarMensaje("¡Perdiste! Caíste en un abismo");
    }
    
    delete jugador;
    delete cpu;
    return 0;
}