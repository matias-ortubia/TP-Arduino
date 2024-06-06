void test_verde_amarillo_rojo() {
    printf("Test verde amarillo rojo\n");

    colores_t colores_a_adivinar[CANT_COLORES] = {VERDE, AMARILLO, ROJO};
    resultado_t resultado[CANT_COLORES];

    colores_t intentos[][CANT_COLORES] = {
        {VERDE, AMARILLO, ROJO},    // {CORRECTO, CORRECTO, CORRECTO}
        {VERDE, AMARILLO, AMARILLO},// {CORRECTO, CORRECTO, INCORRECTO}
        {VERDE, AMARILLO, VERDE},   // {CORRECTO, CORRECTO, INCORRECTO}
        {VERDE, ROJO, AMARILLO},    // {CORRECTO, POSICION_INCORRECTA, POSICION_INCORRECTA}
        {AMARILLO, VERDE, ROJO},    // {POSICION_INCORRECTA, POSICION_INCORRECTA, CORRECTO}
        {ROJO, VERDE, AMARILLO},    // {POSICION_INCORRECTA, POSICION_INCORRECTA, POSICION_INCORRECTA}
        {ROJO, AMARILLO, VERDE},    // {POSICION_INCORRECTA, CORRECTO, POSICION_INCORRECTA}
        {AMARILLO, ROJO, VERDE},    // {POSICION_INCORRECTA, POSICION_INCORRECTA, POSICION_INCORRECTA}
        {VERDE, VERDE, VERDE},      // {CORRECTO, INCORRECTO, INCORRECTO}
        {AMARILLO, AMARILLO, AMARILLO}, // {INCORRECTO, CORRECTO, INCORRECTO}
        {ROJO, ROJO, ROJO}          // {INCORRECTO, INCORRECTO, CORRECTO}
    };

    resultado_t expected_results[][CANT_COLORES] = {
        {CORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO},
        {CORRECTO, POSICION_INCORRECTA, POSICION_INCORRECTA},
        {POSICION_INCORRECTA, POSICION_INCORRECTA, CORRECTO},
        {POSICION_INCORRECTA, POSICION_INCORRECTA, POSICION_INCORRECTA},
        {POSICION_INCORRECTA, CORRECTO, POSICION_INCORRECTA},
        {POSICION_INCORRECTA, POSICION_INCORRECTA, POSICION_INCORRECTA},
        {CORRECTO, INCORRECTO, INCORRECTO},
        {INCORRECTO, CORRECTO, INCORRECTO},
        {INCORRECTO, INCORRECTO, CORRECTO}
    };

    size_t num_tests = sizeof(intentos) / sizeof(intentos[0]);

    for (size_t i = 0; i < num_tests; i++) {
        verificar_aciertos(colores_a_adivinar, intentos[i], resultado);
        for (size_t j = 0; j < CANT_COLORES; j++) {
            assert(resultado[j] == expected_results[i][j]);
        }
        mostrar_resultado(resultado);
    }
}

void test_verde_verde_amarillo() {
    printf("Test verde verde amarillo\n");

    resultado_t resultado[CANT_COLORES];
    colores_t colores_a_adivinar[CANT_COLORES] = {VERDE, VERDE, AMARILLO};

    colores_t intentos[][CANT_COLORES] = {
        {VERDE, VERDE, AMARILLO},    // {CORRECTO, CORRECTO, CORRECTO}
        {VERDE, VERDE, VERDE},       // {CORRECTO, CORRECTO, INCORRECTO}
        {VERDE, AMARILLO, VERDE},    // {CORRECTO, POSICION_INCORRECTA, POSICION_INCORRECTA}
        {AMARILLO, VERDE, VERDE},    // {POSICION_INCORRECTA, CORRECTO, POSICION_INCORRECTA}
        {AMARILLO, AMARILLO, VERDE}, // {POSICION_INCORRECTA, INCORRECTO, POSICION_INCORRECTA}
        {ROJO, ROJO, ROJO},          // {INCORRECTO, INCORRECTO, INCORRECTO}
        {VERDE, ROJO, AMARILLO},     // {CORRECTO, INCORRECTO, CORRECTO}
        {ROJO, VERDE, AMARILLO},     // {INCORRECTO, CORRECTO, CORRECTO}
        {ROJO, AMARILLO, VERDE},     // {INCORRECTO, POSICION_INCORRECTA, POSICION_INCORRECTA}
        {AMARILLO, VERDE, AMARILLO}, // {INCORRECTO, CORRECTO, CORRECTO}
        {VERDE, AMARILLO, ROJO}      // {CORRECTO, POSICION_INCORRECTA, INCORRECTO}
    };

    resultado_t expected_results[][CANT_COLORES] = {
        {CORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO},
        {CORRECTO, POSICION_INCORRECTA, POSICION_INCORRECTA},
        {POSICION_INCORRECTA, CORRECTO, POSICION_INCORRECTA},
        {POSICION_INCORRECTA, INCORRECTO, POSICION_INCORRECTA},
        {INCORRECTO, INCORRECTO, INCORRECTO},
        {CORRECTO, INCORRECTO, CORRECTO},
        {INCORRECTO, CORRECTO, CORRECTO},
        {INCORRECTO, POSICION_INCORRECTA, POSICION_INCORRECTA},
        {INCORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, POSICION_INCORRECTA, INCORRECTO}
    };

    size_t num_tests = sizeof(intentos) / sizeof(intentos[0]);

    for (size_t i = 0; i < num_tests; i++) {
        verificar_aciertos(colores_a_adivinar, intentos[i], resultado);
        mostrar_resultado(resultado);
        for (size_t j = 0; j < CANT_COLORES; j++) {
            assert(resultado[j] == expected_results[i][j]);
        }
    }
}

void test_rojo_verde_verde() {
    printf("test rojo verde verde\n");
    resultado_t resultado[CANT_COLORES];
    colores_t colores_a_adivinar[CANT_COLORES] = {ROJO, VERDE, VERDE};

    colores_t intentos[][CANT_COLORES] = {
        {ROJO, VERDE, VERDE},        // {CORRECTO, CORRECTO, CORRECTO}
        {ROJO, ROJO, ROJO},          // {CORRECTO, INCORRECTO, INCORRECTO}
        {VERDE, VERDE, VERDE},       // {INCORRECTO, CORRECTO, CORRECTO}
        {ROJO, VERDE, ROJO},         // {CORRECTO, CORRECTO, INCORRECTO}
        {VERDE, ROJO, VERDE},        // {POSICION_INCORRECTA, POSICION_INCORRECTA, CORRECTO}
        {VERDE, VERDE, ROJO},        // {POSICION_INCORRECTA, CORRECTO, POSICION_INCORRECTA}
        {VERDE, ROJO, ROJO},         // {POSICION_INCORRECTA, POSICION_INCORRECTA, INCORRECTO}
        {AMARILLO, VERDE, VERDE},    // {INCORRECTO, CORRECTO, CORRECTO}
        {VERDE, AMARILLO, VERDE},    // {POSICION_INCORRECTA, INCORRECTO, CORRECTO}
        {ROJO, AMARILLO, VERDE},     // {CORRECTO, INCORRECTO, CORRECTO}
        {ROJO, VERDE, AMARILLO}      // {CORRECTO, CORRECTO, INCORRECTO}
    };

    resultado_t expected_results[][CANT_COLORES] = {
        {CORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, INCORRECTO, INCORRECTO},
        {INCORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO},
        {POSICION_INCORRECTA, POSICION_INCORRECTA, CORRECTO},
        {POSICION_INCORRECTA, CORRECTO, POSICION_INCORRECTA},
        {POSICION_INCORRECTA, POSICION_INCORRECTA, INCORRECTO},
        {INCORRECTO, CORRECTO, CORRECTO},
        {POSICION_INCORRECTA, INCORRECTO, CORRECTO},
        {CORRECTO, INCORRECTO, CORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO}
    };

    size_t num_tests = sizeof(intentos) / sizeof(intentos[0]);

    for (size_t i = 0; i < num_tests; i++) {
        verificar_aciertos(colores_a_adivinar, intentos[i], resultado);
        printf("Intento %zd: ", i);
        mostrar_resultado(resultado);
        for (size_t j = 0; j < CANT_COLORES; j++) {
            assert(resultado[j] == expected_results[i][j]);
        }
    }
}

void test_verde_verde_verde() {
    printf("test verde verde verde\n");
    resultado_t resultado[CANT_COLORES];
    colores_t colores_a_adivinar[CANT_COLORES] = {VERDE, VERDE, VERDE};

    colores_t intentos[][CANT_COLORES] = {
        {VERDE, VERDE, VERDE},       // {CORRECTO, CORRECTO, CORRECTO}
        {ROJO, ROJO, ROJO},          // {INCORRECTO, INCORRECTO, INCORRECTO}
        {AMARILLO, AMARILLO, AMARILLO}, // {INCORRECTO, INCORRECTO, INCORRECTO}
        {VERDE, ROJO, AMARILLO},     // {CORRECTO, INCORRECTO, INCORRECTO}
        {ROJO, VERDE, VERDE},        // {INCORRECTO, CORRECTO, CORRECTO}
        {VERDE, VERDE, ROJO},        // {CORRECTO, CORRECTO, INCORRECTO}
        {AMARILLO, VERDE, VERDE},    // {INCORRECTO, CORRECTO, CORRECTO}
        {VERDE, AMARILLO, VERDE},    // {CORRECTO, INCORRECTO, CORRECTO}
        {VERDE, VERDE, AMARILLO},    // {CORRECTO, CORRECTO, INCORRECTO}
        {ROJO, AMARILLO, VERDE},     // {INCORRECTO, INCORRECTO, CORRECTO}
        {VERDE, ROJO, VERDE}         // {CORRECTO, INCORRECTO, CORRECTO}
    };

    resultado_t expected_results[][CANT_COLORES] = {
        {CORRECTO, CORRECTO, CORRECTO},
        {INCORRECTO, INCORRECTO, INCORRECTO},
        {INCORRECTO, INCORRECTO, INCORRECTO},
        {CORRECTO, INCORRECTO, INCORRECTO},
        {INCORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO},
        {INCORRECTO, CORRECTO, CORRECTO},
        {CORRECTO, INCORRECTO, CORRECTO},
        {CORRECTO, CORRECTO, INCORRECTO},
        {INCORRECTO, INCORRECTO, CORRECTO},
        {CORRECTO, INCORRECTO, CORRECTO}
    };

    size_t num_tests = sizeof(intentos) / sizeof(intentos[0]);

    for (size_t i = 0; i < num_tests; i++) {
        verificar_aciertos(colores_a_adivinar, intentos[i], resultado);
        printf("Intento %zd: ", i);
        mostrar_resultado(resultado);
        for (size_t j = 0; j < CANT_COLORES; j++) {
            assert(resultado[j] == expected_results[i][j]);
        }
    }
}
