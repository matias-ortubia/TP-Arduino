#define CANT_COLORES 3

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
Compara los colores ingresados con los colores a adivinar y devuelve por parámetro un array con el estado de cada uno.
'resultado' tiene que tener espacio para CANT_COLORES elementos.
*/
void verificar_aciertos(colores_t colores_a_adivinar[], colores_t colores_ingresados[], resultado_t *resultado) {
  resultado_t flags[CANT_COLORES] = {INCORRECTO, INCORRECTO, INCORRECTO};

  // Primera recorrida para chequear los colores que están en la posición correcta
  for(size_t i = 0; i < CANT_COLORES; i++) {
    if(colores_ingresados[i] == colores_a_adivinar[i]) { 
      resultado[i] = CORRECTO;
    } else {
      resultado[i] = INCORRECTO; // Cargo INCORRECTO por defecto para evitar valores basura
    }
  }

  // Segunda recorrida para chequear los colores que están en una posición incorrecta
  size_t cont_respuesta = 0;
  size_t cont_input = 0;

  while(cont_input < CANT_COLORES) {
    if(resultado[cont_input] == CORRECTO) {
      cont_input++;
      continue;
    }
    cont_respuesta = 0;
    while(cont_respuesta < CANT_COLORES) {
      if(flags[cont_respuesta] == POSICION_INCORRECTA || resultado[cont_input] == POSICION_INCORRECTA || resultado[cont_respuesta] == CORRECTO) {
        cont_respuesta++;
        continue;
      }
      if(colores_a_adivinar[cont_respuesta] == colores_ingresados[cont_input]) {
        flags[cont_respuesta] = POSICION_INCORRECTA;
        resultado[cont_input] = POSICION_INCORRECTA;
        break;
      }
      cont_respuesta++;
    }
    cont_input++;
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



void test_derrota() {
  colores_t respuesta[] = {AMARILLO, ROJO, AMARILLO};
  colores_t intento[] = {AMARILLO, AMARILLO, VERDE};
  resultado_t resultado[CANT_COLORES];
  
  verificar_aciertos(respuesta, intento, resultado);

  mostrar_resultado(resultado);
  
  if (verificar_victoria(resultado) == true) {
  	Serial.println("Ganaste!");
  } else {
    Serial.println("Perdiste :(");
  }
}

void test_victoria() {
  colores_t respuesta[] = {AMARILLO, ROJO, VERDE};
  colores_t intento[] = {AMARILLO, ROJO, VERDE};
  resultado_t resultado[CANT_COLORES];
  
  verificar_aciertos(respuesta, intento, resultado);

  mostrar_resultado(resultado);
  
  if (verificar_victoria(resultado) == true) {
  	Serial.println("Ganaste!");
  } else {
    Serial.println("Perdiste :(");
  }
}



void setup()
{
  Serial.begin(9600);

  test_derrota();
  test_victoria();
}

void loop()
{

}
