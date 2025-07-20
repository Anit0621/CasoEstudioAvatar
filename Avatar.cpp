#include "Avatar.h"

Avatar::Avatar() {
    // Constructor vacío como en tu versión original
}

void Avatar::mover(char direction) {
    int nuevaFila = getPosicionFila();    // Usando getPosicionFila() de tu código
    int nuevaColumna = getPosicionColumna(); // Usando getPosicionColumna() de tu código

    switch (direction) {
        case 'W': case 'w': nuevaFila--; break;
        case 'S': case 's': nuevaFila++; break;
        case 'A': case 'a': nuevaColumna--; break;
        case 'D': case 'd': nuevaColumna++; break;
        default: return; // Igual que en el ejemplo del profesor
    }
    
    setPosicionFila(nuevaFila);       // Usando setPosicionFila() de tu código
    setPosicionColumna(nuevaColumna); // Usando setPosicionColumna() de tu código
}