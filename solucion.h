#pragma once

int GetEstado();
int Winner(char** tablero);
int HorizontalValidation(char** tablero);
int VerticalValidation(char** tablero);
int DiagonalLeftRightValidation(char** tablero);
int DiagonalRightLeftValidation(char** tablero);
bool TieValidation(char** tablero);