#include <stdio.h>
#include <ctype.h>

// --- Definiciones de las Piezas ---
// Blancas: P (Peón), R (Torre), N (Caballo), B (Alfil), Q (Reina), K (Rey)
// Negras: p (peón), r (torre), n (caballo), b (alfil), q (reina), k (rey)
char tablero[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// --- Prototipos de Funciones ---
void imprimirTablero();
int esMovimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino);
int esPiezaBlanca(char pieza);
int esPiezaNegra(char pieza);

// --- Función Principal ---
int main() {
    int filaOrigen, colOrigen, filaDestino, colDestino;
    char entrada[5];
    int turnoBlanco = 1; // 1 para el turno de las blancas, 0 para las negras

    while (1) {
        imprimirTablero();
        printf("\nTurno de las %s.\n", turnoBlanco ? "Blancas (MAYUSCULAS)" : "Negras (minusculas)");
        printf("Ingrese su movimiento (ej. e2e4): ");
        scanf("%s", entrada);

        // Convertir la entrada (ej. "e2e4") a coordenadas del tablero
        colOrigen = entrada[0] - 'a';
        filaOrigen = 8 - (entrada[1] - '0');
        colDestino = entrada[2] - 'a';
        filaDestino = 8 - (entrada[3] - '0');

        // --- Validación del Movimiento ---
        if (filaOrigen < 0 || filaOrigen > 7 || colOrigen < 0 || colOrigen > 7 ||
            filaDestino < 0 || filaDestino > 7 || colDestino < 0 || colDestino > 7) {
            printf("\n*** Movimiento fuera del tablero. Intente de nuevo. ***\n");
            continue;
        }

        char pieza = tablero[filaOrigen][colOrigen];
        if ((turnoBlanco && !esPiezaBlanca(pieza)) || (!turnoBlanco && !esPiezaNegra(pieza))) {
            printf("\n*** No es tu pieza. Intente de nuevo. ***\n");
            continue;
        }

        if (esMovimientoValido(filaOrigen, colOrigen, filaDestino, colDestino)) {
            tablero[filaDestino][colDestino] = tablero[filaOrigen][colOrigen];
            tablero[filaOrigen][colOrigen] = ' ';
            turnoBlanco = !turnoBlanco; // Cambiar turno
        } else {
            printf("\n*** Movimiento ilegal. Intente de nuevo. ***\n");
        }
    }

    return 0;
}

// --- Implementación de Funciones ---

void imprimirTablero() {
    printf("\n  a b c d e f g h\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d| ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("|%d\n", 8 - i);
    }
    printf(" +-----------------+\n");
    printf("  a b c d e f g h\n");
}

int esPiezaBlanca(char pieza) {
    return pieza >= 'A' && pieza <= 'Z';
}

int esPiezaNegra(char pieza) {
    return pieza >= 'a' && pieza <= 'z';
}

// Función simplificada para validar movimientos.
// Una implementación completa requeriría reglas para cada pieza.
int esMovimientoValido(int fO, int cO, int fD, int cD) {
    char pieza = tablero[fO][cO];
    char piezaDestino = tablero[fD][cD];

    // No se puede capturar una pieza del mismo color
    if (esPiezaBlanca(pieza) && esPiezaBlanca(piezaDestino)) return 0;
    if (esPiezaNegra(pieza) && esPiezaNegra(piezaDestino)) return 0;

    // --- Lógica de Movimiento por Pieza (Simplificada) ---
    // Esta sección debería expandirse con las reglas específicas de cada pieza.
    // Por ahora, permite cualquier movimiento a una casilla vacía o con enemigo.
    // Aquí es donde se agregaría la lógica para peones, torres, etc.

    // Ejemplo básico para el Peón Blanco
    if (pieza == 'P') {
        // Mover una casilla hacia adelante
        if (cO == cD && tablero[fD][cD] == ' ' && fD == fO - 1) return 1;
        // Mover dos casillas en el primer movimiento
        if (fO == 6 && cO == cD && tablero[fD][cD] == ' ' && fD == fO - 2) return 1;
        // Capturar en diagonal
        if (abs(cO - cD) == 1 && fD == fO - 1 && esPiezaNegra(tablero[fD][cD])) return 1;
        return 0; // Movimiento de peón no válido
    }

    // Ejemplo básico para el Peón Negro
    if (pieza == 'p') {
        // Mover una casilla hacia adelante
        if (cO == cD && tablero[fD][cD] == ' ' && fD == fO + 1) return 1;
        // Mover dos casillas en el primer movimiento
        if (fO == 1 && cO == cD && tablero[fD][cD] == ' ' && fD == fO + 2) return 1;
        // Capturar en diagonal
        if (abs(cO - cD) == 1 && fD == fO + 1 && esPiezaBlanca(tablero[fD][cD])) return 1;
        return 0; // Movimiento de peón no válido
    }

    // Para las demás piezas, esta lógica simplificada solo valida la captura.
    // Se necesita añadir la lógica de movimiento de torre, alfil, etc.
    // Por simplicidad, este código no la incluye, pero este es el lugar para ponerla.

    printf("\n-> Alerta: La logica de movimiento para esta pieza no esta implementada. Se permite el movimiento.\n");

    return 1; // Permite el movimiento si no es una pieza del mismo color
}
