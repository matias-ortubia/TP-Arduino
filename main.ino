#define CANT_COLORES 3
#define MAX_INTENTOS 3

typedef enum {
  VERDE,
  AMARILLO,
  ROJO
} colores_t;

typedef enum {
  CORRECTO,
  POSICION_INCORRECTA,
  INCORRECTO
} resultado_t;


void verificar_aciertos(colores_t colores_a_adivinar[], colores_t colores_ingresados[], resultado_t *resultado);
bool verificar_victoria(resultado_t resultado[]);
void mostrar_resultado(resultado_t resultado[]);


/*
Compara los colores ingresados con los colores a adivinar y devuelve por parametro un array con el estado de cada uno.
'resultado' tiene que tener espacio para CANT_COLORES elementos.
*/
void verificar_aciertos(colores_t colores_a_adivinar[], colores_t colores_ingresados[], resultado_t *resultado) {
  resultado_t flags[CANT_COLORES] = {INCORRECTO, INCORRECTO, INCORRECTO};

  // Primera recorrida para chequear los colores que estan en la posicion correcta
  for(size_t i = 0; i < CANT_COLORES; i++) {
    if(colores_ingresados[i] == colores_a_adivinar[i]) { 
      resultado[i] = CORRECTO;
    } else {
      resultado[i] = INCORRECTO; // Cargo INCORRECTO por defecto para evitar valores basura
    }
  }

  // Segunda recorrida para chequear los colores que estan en una posicion incorrecta
  for (size_t cont_input = 0; cont_input < CANT_COLORES; cont_input++) {
    if(resultado[cont_input] != CORRECTO) {  
      for (size_t cont_respuesta = 0; cont_respuesta < CANT_COLORES; cont_respuesta++) {
        if (flags[cont_respuesta] != POSICION_INCORRECTA && 
                resultado[cont_input] != POSICION_INCORRECTA && 
                resultado[cont_respuesta] != CORRECTO) {
          
          if(colores_a_adivinar[cont_respuesta] == colores_ingresados[cont_input]) {
            flags[cont_respuesta] = POSICION_INCORRECTA;
            resultado[cont_input] = POSICION_INCORRECTA;
            break;
          }
        }
      }
    }
  }
}

// Devuelve true si el jugador acertó todos los colores, y false en caso contrario
bool verificar_victoria(resultado_t resultado[]) {
  for (size_t i = 0; i < CANT_COLORES; i++) {
    if (resultado[i] != CORRECTO) {
      return false;
    }
  }
  return true;
}

void mostrar_colores(colores_t colores[]) {
    putchar('[');
    for (size_t i = 0; i < CANT_COLORES; i++) {
        switch(colores[i]) {
            case AMARILLO:
                printf("AMARILLO");
                break;
            case VERDE:
                printf("VERDE");
                break;
            case ROJO:
                printf("ROJO");
                break;
            default:
                printf("Error");
                break;
        }
        printf("%s", i != CANT_COLORES - 1 ? ", " : "]");
    }
}

void mostrar_resultado(resultado_t resultado[]) {
  for (size_t i = 0; i < CANT_COLORES; i++) {
    Serial.print("Resultado para el color ");
    Serial.print(i);
    Serial.print(": ");
    switch (resultado[i]) {
      case CORRECTO:
        Serial.println("CORRECTO");
        break;
      case POSICION_INCORRECTA:
        Serial.println("POSICION_INCORRECTA");
        break;
      case INCORRECTO:
        Serial.println("INCORRECTO");
        break;
    }
  }
}

// TODO: Adaptar a Arduino (digitalRead, pasar cosas a loop y setup, etc)
void comenzar_juego() {
    // Se elige un patron de colores aleatorio
    srand(time(NULL));
    int color1 = rand() % CANT_COLORES;    
    int color2 = rand() % CANT_COLORES;
    int color3 = rand() % CANT_COLORES;

    colores_t colores_a_adivinar[CANT_COLORES] = {color1, color2, color3};
#ifdef DEBUG
    printf("La respuesta es: ");
    mostrar_colores(colores_a_adivinar);
    putchar('\n');
#endif

    // Se le pide al usuario que ingrese una combinacion de colores
    size_t turno = 1;
    bool victoria = false;
    while(turno <= MAX_INTENTOS && victoria == false) {
        printf("Turno %zd\n", turno);
        colores_t intento[CANT_COLORES];

        // TODO Leer combinacion de colores

        // Se compara esa combinacion con los colores a adivinar 
        resultado_t resultado[CANT_COLORES];
        verificar_aciertos(colores_a_adivinar, intento, resultado);

#ifdef DEBUG
        mostrar_resultado(resultado);
        putchar('\n');
        putchar('\n');
#endif
        if(verificar_victoria(resultado) == true) 
            victoria = true;

        turno++;
    }

    if(victoria == true)
        printf("Ganaste!\n");
    else {
        printf("Perdiste :(\nLa respuesta era: ");
        mostrar_colores(colores_a_adivinar);
        putchar('\n');
    }
}




void setup()
{
  Serial.begin(9600);

}

void loop()
{

}
