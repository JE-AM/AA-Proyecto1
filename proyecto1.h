/*
 * Proyecto 1 - Generador de Cuadrados Mágicos
 * Archivo de cabecera con definiciones y estructuras principales
 */

#ifndef PROYECTO1_H
#define PROYECTO1_H

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <time.h>

/* Enumeración de los métodos disponibles para generar cuadrados mágicos */
typedef enum {
    METHOD_UP_RIGHT,    // Método tradicional: arriba-derecha
    METHOD_DOWN_LEFT,   // Método variante: abajo-izquierda
    METHOD_L_SHAPED,    // Método del movimiento en L (como caballo de ajedrez)
    METHOD_SPIRAL       // Método diagonal
} MagicMethod;

/* Estructura principal que contiene todos los datos de la aplicación */
typedef struct {
    // Widgets de la interfaz gráfica
    GtkWidget *main_window;      // Ventana principal
    GtkWidget *order_spin;       // Control para seleccionar el orden del cuadrado
    GtkWidget *method_combo;     // ComboBox para seleccionar el método
    GtkWidget *start_button;     // Botón para iniciar la generación
    GtkWidget *step_button;      // Botón para avanzar paso a paso
    GtkWidget *complete_button;  // Botón para completar automáticamente
    GtkWidget *reset_button;     // Botón para reiniciar
    GtkWidget *magic_grid;       // Grid que contiene el cuadrado mágico
    GtkWidget *sums_text;        // Área de texto para mostrar las sumas

    // Datos del cuadrado mágico
    int **magic_square;          // Matriz que representa el cuadrado mágico
    GtkWidget ***grid_labels;    // Matriz de etiquetas para mostrar los números
    int order;                   // Orden del cuadrado (n x n)
    int grid_order;              // Orden actual de la cuadrícula de etiquetas
    int current_number;          // Número actual a colocar (para modo paso a paso)
    int current_row, current_col; // Posición actual en el algoritmo
    int start_row, start_col;    // Posición inicial randomizada para el algoritmo
    MagicMethod method;          // Método seleccionado para generar el cuadrado
    gboolean is_active;          // Indica si hay una generación en proceso

    // Datos para verificación de las sumas
    int *row_sums;               // Suma de cada fila
    int *col_sums;               // Suma de cada columna
    int diagonal1_sum;           // Suma de la diagonal principal
    int diagonal2_sum;           // Suma de la diagonal secundaria
} AppData;

/* Funciones para generar cuadrados mágicos con diferentes algoritmos */
void generateMagicSquare(int n, int magicSquare[n][n], MagicMethod method, int start_row, int start_col);
void generateUpRight(int n, int magicSquare[n][n], int start_row, int start_col);    // Algoritmo arriba-derecha
void generateDownLeft(int n, int magicSquare[n][n], int start_row, int start_col);   // Algoritmo abajo-izquierda
void generateLShaped(int n, int magicSquare[n][n], int start_row, int start_col);    // Algoritmo movimiento en L
void generateSpiral(int n, int magicSquare[n][n], int start_row, int start_col);     // Algoritmo diagonal

/* Funciones de manejo de eventos de la interfaz gráfica */
void on_start_clicked(GtkWidget *widget, AppData *data);     // Evento del botón "Iniciar"
void on_step_clicked(GtkWidget *widget, AppData *data);      // Evento del botón "Paso"
void on_complete_clicked(GtkWidget *widget, AppData *data);  // Evento del botón "Completar"
void on_reset_clicked(GtkWidget *widget, AppData *data);     // Evento del botón "Reiniciar"

/* Funciones para manejo de la interfaz gráfica */
void create_magic_grid(AppData *data);      // Crea la cuadrícula visual del cuadrado mágico
void update_grid_display(AppData *data);    // Actualiza la visualización de los números
void update_sums_display(AppData *data);    // Actualiza la visualización de las sumas
void place_next_number(AppData *data);      // Coloca el siguiente número en modo paso a paso
void cleanup_app_data(AppData *data);       // Libera la memoria utilizada

#endif