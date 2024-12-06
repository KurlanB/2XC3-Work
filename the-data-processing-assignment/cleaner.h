/* Kurlan Beeharry, 400521584, November 20, 2024
 *
 * Header file for the cleaner functions
 *
 */

#include <stdlib.h>

float *clean_delete(int *rows, int columns, float data[*rows][columns]);
void clean_impute(int rows, int columns, float (*data)[columns]);
