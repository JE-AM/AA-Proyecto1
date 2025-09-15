/*
 * Proyecto 1 - Generador de Cuadrados Mágicos
 * Implementación de algoritmos para generar cuadrados mágicos
 * con interfaz gráfica usando GTK+
 */

#include "proyecto1.h"

/*
 * Algoritmo tradicional para generar cuadrados mágicos: Método Arriba-Derecha
 *
 * Este algoritmo coloca el primer número en la fila superior, columna central.
 * Para cada número siguiente:
 * 1. Se mueve una fila arriba y una columna a la derecha
 * 2. Si la posición está ocupada, se mueve una fila abajo desde la posición anterior
 * 3. Se aplica aritmética modular para el manejo de bordes
 */
void generateUpRight(int n, int magicSquare[n][n], int start_row, int start_col) {
    (void)start_row; (void)start_col; // Parámetros no utilizados en este algoritmo

    // Inicializar la matriz con ceros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Posición inicial: fila superior, columna central
    int row = 0;
    int col = n / 2;
    magicSquare[row][col] = 1;

    // Colocar los números del 2 al n²
    for (int num = 2; num <= n * n; num++) {
        // Intentar moverse arriba-derecha usando aritmética modular
        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        // Si la posición está ocupada, moverse abajo desde la posición anterior
        if (magicSquare[newRow][newCol] != 0) {
            newRow = (row + 1) % n;
            newCol = col;
        }

        // Colocar el número y actualizar la posición actual
        magicSquare[newRow][newCol] = num;
        row = newRow;
        col = newCol;
    }
}

/*
 * Algoritmo variante para generar cuadrados mágicos: Método Abajo-Izquierda
 *
 * Este algoritmo es una variación del método tradicional.
 * Coloca el primer número en la fila inferior, columna central.
 * Para cada número siguiente:
 * 1. Se mueve una fila abajo y una columna a la izquierda
 * 2. Si la posición está ocupada, se mueve una fila arriba desde la posición anterior
 * 3. Se aplica aritmética modular para el manejo de bordes
 */
void generateDownLeft(int n, int magicSquare[n][n], int start_row, int start_col) {
    (void)start_row; (void)start_col; // Parámetros no utilizados en este algoritmo

    // Inicializar la matriz con ceros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Posición inicial: fila inferior, columna central
    int row = n - 1;
    int col = n / 2;
    magicSquare[row][col] = 1;

    // Colocar los números del 2 al n²
    for (int num = 2; num <= n * n; num++) {
        // Intentar moverse abajo-izquierda usando aritmética modular
        int newRow = (row + 1) % n;
        int newCol = (col - 1 + n) % n;

        // Si la posición está ocupada, moverse arriba desde la posición anterior
        if (magicSquare[newRow][newCol] != 0) {
            newRow = (row - 1 + n) % n;
            newCol = col;
        }

        // Colocar el número y actualizar la posición actual
        magicSquare[newRow][newCol] = num;
        row = newRow;
        col = newCol;
    }
}

/*
 * Algoritmo del movimiento en L para generar cuadrados mágicos
 *
 * Este algoritmo utiliza un patrón de movimiento similar al caballo del ajedrez.
 * Coloca el primer número en la primera fila, segunda columna.
 * Para cada número siguiente:
 * 1. Se mueve dos filas arriba y una columna a la izquierda (movimiento en L)
 * 2. Si la posición está ocupada, se mueve una fila abajo desde la posición anterior
 * 3. Se aplica aritmética modular para el manejo de bordes
 */
void generateLShaped(int n, int magicSquare[n][n], int start_row, int start_col) {
    (void)start_row; (void)start_col; // Parámetros no utilizados en este algoritmo

    // Inicializar la matriz con ceros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Posición inicial: primera fila, segunda columna
    int row = 0;
    int col = 1;
    magicSquare[row][col] = 1;

    // Colocar los números del 2 al n²
    for (int num = 2; num <= n * n; num++) {
        // Intentar movimiento en L: 2 arriba, 1 izquierda
        int newRow = (row - 2 + n) % n;
        int newCol = (col - 1 + n) % n;

        // Si la posición está ocupada, moverse abajo desde la posición anterior
        if (magicSquare[newRow][newCol] != 0) {
            newRow = (row + 1) % n;
            newCol = col;
        }

        // Colocar el número y actualizar la posición actual
        magicSquare[newRow][newCol] = num;
        row = newRow;
        col = newCol;
    }
}

/*
 * Algoritmo diagonal para generar cuadrados mágicos
 *
 * Este algoritmo utiliza un movimiento diagonal hacia arriba-izquierda.
 * Coloca el primer número en la fila central, primera columna.
 * Para cada número siguiente:
 * 1. Se mueve una fila arriba y una columna a la izquierda (diagonal)
 * 2. Si la posición está ocupada, se mueve una fila abajo desde la posición anterior
 * 3. Se aplica aritmética modular para el manejo de bordes
 */
void generateSpiral(int n, int magicSquare[n][n], int start_row, int start_col) {
    (void)start_row; (void)start_col; // Parámetros no utilizados en este algoritmo

    // Inicializar la matriz con ceros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Posición inicial: fila central, primera columna
    int row = n / 2;
    int col = 0;
    magicSquare[row][col] = 1;

    // Colocar los números del 2 al n²
    for (int num = 2; num <= n * n; num++) {
        // Intentar movimiento diagonal: arriba-izquierda
        int newRow = (row - 1 + n) % n;
        int newCol = (col - 1 + n) % n;

        // Si la posición está ocupada, moverse abajo desde la posición anterior
        if (magicSquare[newRow][newCol] != 0) {
            newRow = (row + 1) % n;
            newCol = col;
        }

        // Colocar el número y actualizar la posición actual
        magicSquare[newRow][newCol] = num;
        row = newRow;
        col = newCol;
    }
}

/*
 * Función principal para generar cuadrados mágicos
 *
 * Esta función actúa como un dispatcher que llama al algoritmo
 * correspondiente según el método seleccionado por el usuario.
 *
 * Parámetros:
 *   n: orden del cuadrado mágico (n x n)
 *   magicSquare: matriz donde se almacenará el cuadrado mágico
 *   method: método de generación seleccionado
 *   start_row, start_col: posición inicial (no utilizada en los algoritmos actuales)
 */
void generateMagicSquare(int n, int magicSquare[n][n], MagicMethod method, int start_row, int start_col) {
    switch (method) {
        case METHOD_UP_RIGHT:
            generateUpRight(n, magicSquare, start_row, start_col);
            break;
        case METHOD_DOWN_LEFT:
            generateDownLeft(n, magicSquare, start_row, start_col);
            break;
        case METHOD_L_SHAPED:
            generateLShaped(n, magicSquare, start_row, start_col);
            break;
        case METHOD_SPIRAL:
            generateSpiral(n, magicSquare, start_row, start_col);
            break;
    }
}

/*
 * Función auxiliar para destruir widgets hijos
 * Utilizada para limpiar los widgets de la cuadrícula antes de crear una nueva
 */
static void destroy_child(GtkWidget *widget, gpointer data) {
    (void)data; // Parámetro no utilizado
    gtk_widget_destroy(widget);
}

/*
 * Crea la cuadrícula visual del cuadrado mágico
 *
 * Esta función:
 * 1. Limpia la cuadrícula anterior si existe
 * 2. Libera la memoria de las etiquetas anteriores
 * 3. Crea nuevas etiquetas para cada celda del cuadrado
 * 4. Configura el tamaño y estilo de cada etiqueta
 * 5. Añade las etiquetas a la cuadrícula GTK
 */
void create_magic_grid(AppData *data) {
    // Eliminar todos los widgets hijos de la cuadrícula anterior
    gtk_container_foreach(GTK_CONTAINER(data->magic_grid), destroy_child, NULL);

    // Liberar memoria de las etiquetas anteriores si existen
    if (data->grid_labels) {
        for (int i = 0; i < data->grid_order; i++) {
            free(data->grid_labels[i]);
        }
        free(data->grid_labels);
        data->grid_labels = NULL;
    }

    // Crear nueva matriz de etiquetas
    data->grid_labels = malloc(data->order * sizeof(GtkWidget**));
    for (int i = 0; i < data->order; i++) {
        data->grid_labels[i] = malloc(data->order * sizeof(GtkWidget*));
        for (int j = 0; j < data->order; j++) {
            // Crear etiqueta vacía para cada celda
            data->grid_labels[i][j] = gtk_label_new("");

            // Configurar tamaño de la celda dinámicamente basado en el orden
            int cell_size = 60 - (data->order - 3) * 2; // Reducir tamaño conforme aumenta el orden
            if (cell_size < 25) cell_size = 25; // Tamaño mínimo
            gtk_widget_set_size_request(data->grid_labels[i][j], cell_size, cell_size);

            // Configurar formato del texto con tamaño dinámico
            int font_size = 16 - (data->order - 3) * 1; // Reducir fuente conforme aumenta el orden
            if (font_size < 8) font_size = 8; // Tamaño mínimo de fuente
            char markup[64];
            snprintf(markup, sizeof(markup), "<span font='%d' weight='bold'> </span>", font_size);
            gtk_label_set_markup(GTK_LABEL(data->grid_labels[i][j]), markup);

            // Centrar el contenido de la etiqueta
            gtk_widget_set_halign(data->grid_labels[i][j], GTK_ALIGN_CENTER);
            gtk_widget_set_valign(data->grid_labels[i][j], GTK_ALIGN_CENTER);

            // Añadir clase CSS para el estilo visual
            GtkStyleContext *context = gtk_widget_get_style_context(data->grid_labels[i][j]);
            gtk_style_context_add_class(context, "magic-cell");

            // Añadir la etiqueta a la cuadrícula en la posición (j, i)
            gtk_grid_attach(GTK_GRID(data->magic_grid), data->grid_labels[i][j], j, i, 1, 1);
        }
    }

    // Actualizar el orden de la cuadrícula para futuras liberaciones de memoria
    data->grid_order = data->order;

    // Mostrar todos los widgets de la cuadrícula
    gtk_widget_show_all(data->magic_grid);
}

/*
 * Actualiza la visualización de los números en la cuadrícula
 *
 * Recorre toda la matriz del cuadrado mágico y actualiza el contenido
 * de cada etiqueta visual correspondiente. Si una celda contiene 0,
 * muestra un espacio vacío; de lo contrario, muestra el número.
 */
void update_grid_display(AppData *data) {
    for (int i = 0; i < data->order; i++) {
        for (int j = 0; j < data->order; j++) {
            if (data->magic_square[i][j] != 0) {
                // Formatear el número con estilo negrita y tamaño dinámico
                int font_size = 16 - (data->order - 3) * 1; // Reducir fuente conforme aumenta el orden
                if (font_size < 8) font_size = 8; // Tamaño mínimo de fuente
                char text[64];
                snprintf(text, sizeof(text), "<span font='%d' weight='bold'>%d</span>", font_size, data->magic_square[i][j]);
                gtk_label_set_markup(GTK_LABEL(data->grid_labels[i][j]), text);
            } else {
                // Mostrar celda vacía
                int font_size = 16 - (data->order - 3) * 1; // Reducir fuente conforme aumenta el orden
                if (font_size < 8) font_size = 8; // Tamaño mínimo de fuente
                char markup[64];
                snprintf(markup, sizeof(markup), "<span font='%d' weight='bold'> </span>", font_size);
                gtk_label_set_markup(GTK_LABEL(data->grid_labels[i][j]), markup);
            }
        }
    }
}

/*
 * Actualiza la visualización de las sumas en el área de texto
 *
 * Calcula y muestra:
 * 1. La suma mágica esperada (n * (n² + 1) / 2)
 * 2. La suma de cada fila
 * 3. La suma de cada columna
 * 4. La suma de ambas diagonales
 *
 * Esto permite al usuario verificar si el cuadrado es realmente mágico.
 */
void update_sums_display(AppData *data) {
    // Obtener el buffer de texto y limpiarlo
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data->sums_text));
    gtk_text_buffer_set_text(buffer, "", -1);

    // Obtener iterador para insertar texto al final
    GtkTextIter iter;
    gtk_text_buffer_get_end_iter(buffer, &iter);

    // Calcular la suma mágica teórica
    int magic_sum = data->order * (data->order * data->order + 1) / 2;

    // Mostrar la suma mágica esperada
    char text[256];
    snprintf(text, sizeof(text), "Expected magic sum: %d\n\n", magic_sum);
    gtk_text_buffer_insert(buffer, &iter, text, -1);

    // Calcular y mostrar las sumas de las filas
    for (int i = 0; i < data->order; i++) {
        data->row_sums[i] = 0;
        for (int j = 0; j < data->order; j++) {
            data->row_sums[i] += data->magic_square[i][j];
        }
        snprintf(text, sizeof(text), "Row %d: %d\n", i + 1, data->row_sums[i]);
        gtk_text_buffer_insert(buffer, &iter, text, -1);
    }

    gtk_text_buffer_insert(buffer, &iter, "\n", -1);

    // Calcular y mostrar las sumas de las columnas
    for (int j = 0; j < data->order; j++) {
        data->col_sums[j] = 0;
        for (int i = 0; i < data->order; i++) {
            data->col_sums[j] += data->magic_square[i][j];
        }
        snprintf(text, sizeof(text), "Column %d: %d\n", j + 1, data->col_sums[j]);
        gtk_text_buffer_insert(buffer, &iter, text, -1);
    }

    gtk_text_buffer_insert(buffer, &iter, "\n", -1);

    // Calcular las sumas de las diagonales
    data->diagonal1_sum = 0;
    data->diagonal2_sum = 0;
    for (int i = 0; i < data->order; i++) {
        data->diagonal1_sum += data->magic_square[i][i];                    // Diagonal principal
        data->diagonal2_sum += data->magic_square[i][data->order - 1 - i];  // Diagonal secundaria
    }

    // Mostrar las sumas de las diagonales
    snprintf(text, sizeof(text), "Main diagonal: %d\n", data->diagonal1_sum);
    gtk_text_buffer_insert(buffer, &iter, text, -1);
    snprintf(text, sizeof(text), "Secondary diagonal: %d\n", data->diagonal2_sum);
    gtk_text_buffer_insert(buffer, &iter, text, -1);
}

/*
 * Coloca el siguiente número en el cuadrado mágico (modo paso a paso)
 *
 * Esta función ejecuta un paso real del algoritmo seleccionado,
 * mostrando cómo el algoritmo decide dónde colocar cada número.
 */
void place_next_number(AppData *data) {
    // Verificar si ya se han colocado todos los números
    if (data->current_number > data->order * data->order) {
        gtk_widget_set_sensitive(data->step_button, FALSE);
        gtk_widget_set_sensitive(data->complete_button, FALSE);
        return;
    }

    int newRow, newCol;

    // Ejecutar un paso del algoritmo según el método seleccionado
    switch (data->method) {
        case METHOD_UP_RIGHT:
            if (data->current_number == 1) {
                // Primer número: fila superior, columna central
                data->current_row = 0;
                data->current_col = data->order / 2;
            } else {
                // Intentar moverse arriba-derecha
                newRow = (data->current_row - 1 + data->order) % data->order;
                newCol = (data->current_col + 1) % data->order;

                // Si la posición está ocupada, moverse abajo
                if (data->magic_square[newRow][newCol] != 0) {
                    newRow = (data->current_row + 1) % data->order;
                    newCol = data->current_col;
                }

                data->current_row = newRow;
                data->current_col = newCol;
            }
            break;

        case METHOD_DOWN_LEFT:
            if (data->current_number == 1) {
                // Primer número: fila inferior, columna central
                data->current_row = data->order - 1;
                data->current_col = data->order / 2;
            } else {
                // Intentar moverse abajo-izquierda
                newRow = (data->current_row + 1) % data->order;
                newCol = (data->current_col - 1 + data->order) % data->order;

                // Si la posición está ocupada, moverse arriba
                if (data->magic_square[newRow][newCol] != 0) {
                    newRow = (data->current_row - 1 + data->order) % data->order;
                    newCol = data->current_col;
                }

                data->current_row = newRow;
                data->current_col = newCol;
            }
            break;

        case METHOD_L_SHAPED:
            if (data->current_number == 1) {
                // Primer número: primera fila, segunda columna
                data->current_row = 0;
                data->current_col = 1;
            } else {
                // Intentar movimiento en L: 2 arriba, 1 izquierda
                newRow = (data->current_row - 2 + data->order) % data->order;
                newCol = (data->current_col - 1 + data->order) % data->order;

                // Si la posición está ocupada, moverse abajo
                if (data->magic_square[newRow][newCol] != 0) {
                    newRow = (data->current_row + 1) % data->order;
                    newCol = data->current_col;
                }

                data->current_row = newRow;
                data->current_col = newCol;
            }
            break;

        case METHOD_SPIRAL:
            if (data->current_number == 1) {
                // Primer número: fila central, primera columna
                data->current_row = data->order / 2;
                data->current_col = 0;
            } else {
                // Intentar movimiento diagonal: arriba-izquierda
                newRow = (data->current_row - 1 + data->order) % data->order;
                newCol = (data->current_col - 1 + data->order) % data->order;

                // Si la posición está ocupada, moverse abajo
                if (data->magic_square[newRow][newCol] != 0) {
                    newRow = (data->current_row + 1) % data->order;
                    newCol = data->current_col;
                }

                data->current_row = newRow;
                data->current_col = newCol;
            }
            break;
    }

    // Colocar el número en la posición calculada
    data->magic_square[data->current_row][data->current_col] = data->current_number;
    data->current_number++;

    // Actualizar las visualizaciones
    update_grid_display(data);
    update_sums_display(data);
}

/*
 * Manejador del evento "clic" del botón "Iniciar"
 *
 * Esta función:
 * 1. Valida que el orden sea impar y esté en el rango permitido
 * 2. Libera memoria de cuadrados anteriores si existen
 * 3. Inicializa un nuevo cuadrado mágico vacío
 * 4. Configura los parámetros iniciales
 * 5. Crea la nueva cuadrícula visual
 * 6. Habilita/deshabilita los botones apropiados
 */
void on_start_clicked(GtkWidget *widget, AppData *data) {
    (void)widget; // Parámetro no utilizado

    // Obtener el orden seleccionado por el usuario
    int order = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(data->order_spin));

    // Validar que el orden sea impar y esté en el rango válido
    if (order % 2 == 0 || order < 3 || order > 21) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(data->main_window),
                                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                                  GTK_MESSAGE_ERROR,
                                                  GTK_BUTTONS_CLOSE,
                                                  "The order must be an odd number between 3 and 21.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    // Guardar el orden anterior para liberar memoria correctamente
    int old_order = data->order;

    // Guardar la configuración seleccionada
    data->order = order;
    data->method = gtk_combo_box_get_active(GTK_COMBO_BOX(data->method_combo));

    // Liberar memoria del cuadrado anterior si existe
    if (data->magic_square) {
        for (int i = 0; i < old_order; i++) {
            free(data->magic_square[i]);
        }
        free(data->magic_square);
        free(data->row_sums);
        free(data->col_sums);
    }

    // Asignar memoria para el nuevo cuadrado mágico
    data->magic_square = malloc(order * sizeof(int*));
    for (int i = 0; i < order; i++) {
        data->magic_square[i] = malloc(order * sizeof(int));
        // Inicializar todas las celdas con cero
        for (int j = 0; j < order; j++) {
            data->magic_square[i][j] = 0;
        }
    }

    // Asignar memoria para los arreglos de sumas
    data->row_sums = calloc(order, sizeof(int));
    data->col_sums = calloc(order, sizeof(int));
    data->diagonal1_sum = 0;
    data->diagonal2_sum = 0;

    // Generar posición inicial aleatoria (no utilizada por los algoritmos actuales)
    srand(time(NULL));
    data->start_row = rand() % order;
    data->start_col = rand() % order;

    // Inicializar parámetros para la generación paso a paso
    data->current_row = data->start_row;
    data->current_col = data->start_col;
    data->current_number = 1;
    data->is_active = TRUE;

    // Crear la nueva cuadrícula visual y actualizar pantalla
    create_magic_grid(data);
    update_grid_display(data);
    update_sums_display(data);

    // Configurar el estado de los botones
    gtk_widget_set_sensitive(data->step_button, TRUE);
    gtk_widget_set_sensitive(data->complete_button, TRUE);
    gtk_widget_set_sensitive(data->start_button, FALSE);
}

/*
 * Manejador del evento "clic" del botón "Paso"
 *
 * Coloca el siguiente número en el cuadrado mágico y verifica
 * si se ha completado la generación para deshabilitar los botones.
 */
void on_step_clicked(GtkWidget *widget, AppData *data) {
    (void)widget; // Parámetro no utilizado

    // Colocar el siguiente número si la generación está activa
    if (data->is_active && data->current_number <= data->order * data->order) {
        place_next_number(data);
    }

    // Verificar si se ha completado el cuadrado
    if (data->current_number > data->order * data->order) {
        gtk_widget_set_sensitive(data->step_button, FALSE);
        gtk_widget_set_sensitive(data->complete_button, FALSE);
        data->is_active = FALSE;
    }
}

/*
 * Manejador del evento "clic" del botón "Completar"
 *
 * Genera instantáneamente todo el cuadrado mágico y actualiza
 * la visualización, luego deshabilita los botones de progreso.
 */
void on_complete_clicked(GtkWidget *widget, AppData *data) {
    (void)widget; // Parámetro no utilizado

    if (data->is_active) {
        // Generar el cuadrado mágico completo
        int temp_square[data->order][data->order];
        generateMagicSquare(data->order, temp_square, data->method, data->start_row, data->start_col);

        // Copiar el cuadrado generado al cuadrado visible
        for (int i = 0; i < data->order; i++) {
            for (int j = 0; j < data->order; j++) {
                data->magic_square[i][j] = temp_square[i][j];
            }
        }

        // Actualizar las visualizaciones
        update_grid_display(data);
        update_sums_display(data);

        // Deshabilitar botones y marcar como inactivo
        gtk_widget_set_sensitive(data->step_button, FALSE);
        gtk_widget_set_sensitive(data->complete_button, FALSE);
        data->is_active = FALSE;
    }
}

/*
 * Manejador del evento "clic" del botón "Reiniciar"
 *
 * Limpia el cuadrado mágico actual, reinicia los parámetros
 * y habilita el botón "Iniciar" para comenzar una nueva generación.
 */
void on_reset_clicked(GtkWidget *widget, AppData *data) {
    (void)widget; // Parámetro no utilizado

    // Limpiar el cuadrado mágico si existe
    if (data->magic_square) {
        for (int i = 0; i < data->order; i++) {
            for (int j = 0; j < data->order; j++) {
                data->magic_square[i][j] = 0;
            }
        }
        // Actualizar las visualizaciones para mostrar el cuadrado vacío
        update_grid_display(data);
        update_sums_display(data);
    }

    // Reiniciar parámetros de generación
    data->current_number = 1;
    data->is_active = FALSE;

    // Configurar el estado de los botones
    gtk_widget_set_sensitive(data->step_button, FALSE);
    gtk_widget_set_sensitive(data->complete_button, FALSE);
    gtk_widget_set_sensitive(data->start_button, TRUE);
}

/*
 * Libera toda la memoria dinámica utilizada por la aplicación
 *
 * Esta función debe llamarse antes de terminar el programa
 * para evitar fugas de memoria.
 */
void cleanup_app_data(AppData *data) {
    // Liberar memoria del cuadrado mágico
    if (data->magic_square) {
        for (int i = 0; i < data->order; i++) {
            free(data->magic_square[i]);
        }
        free(data->magic_square);
    }

    // Liberar memoria de las etiquetas de la cuadrícula
    if (data->grid_labels) {
        for (int i = 0; i < data->grid_order; i++) {
            free(data->grid_labels[i]);
        }
        free(data->grid_labels);
    }

    // Liberar memoria de los arreglos de sumas
    free(data->row_sums);
    free(data->col_sums);
}

/*
 * Función principal del programa
 *
 * Inicializa GTK+, carga la interfaz desde el archivo Glade,
 * configura los manejadores de eventos y ejecuta el bucle principal.
 */
int main(int argc, char *argv[]) {
    // Inicializar GTK+
    gtk_init(&argc, &argv);

    // Crear el constructor de interfaz y cargar el archivo Glade
    GtkBuilder *builder = gtk_builder_new();
    GError *error = NULL;

    if (!gtk_builder_add_from_file(builder, "magic_square.glade", &error)) {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return 1;
    }

    // Crear e inicializar la estructura de datos de la aplicación
    AppData *data = g_new0(AppData, 1);

    // Obtener referencias a todos los widgets de la interfaz
    data->main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    data->order_spin = GTK_WIDGET(gtk_builder_get_object(builder, "order_spin"));
    data->method_combo = GTK_WIDGET(gtk_builder_get_object(builder, "method_combo"));
    data->start_button = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));
    data->step_button = GTK_WIDGET(gtk_builder_get_object(builder, "step_button"));
    data->complete_button = GTK_WIDGET(gtk_builder_get_object(builder, "complete_button"));
    data->reset_button = GTK_WIDGET(gtk_builder_get_object(builder, "reset_button"));
    data->magic_grid = GTK_WIDGET(gtk_builder_get_object(builder, "magic_grid"));
    data->sums_text = GTK_WIDGET(gtk_builder_get_object(builder, "sums_text"));

    // Conectar las señales de los botones con sus manejadores
    g_signal_connect(data->start_button, "clicked", G_CALLBACK(on_start_clicked), data);
    g_signal_connect(data->step_button, "clicked", G_CALLBACK(on_step_clicked), data);
    g_signal_connect(data->complete_button, "clicked", G_CALLBACK(on_complete_clicked), data);
    g_signal_connect(data->reset_button, "clicked", G_CALLBACK(on_reset_clicked), data);

    // Liberar el constructor ya que no se necesita más
    g_object_unref(builder);

    // Mostrar la ventana principal y todos sus widgets
    gtk_widget_show_all(data->main_window);

    // Conectar la señal de cierre de ventana para terminar el programa
    g_signal_connect(data->main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Ejecutar el bucle principal de GTK+
    gtk_main();

    // Limpiar la memoria antes de salir
    cleanup_app_data(data);
    g_free(data);

    return 0;
}