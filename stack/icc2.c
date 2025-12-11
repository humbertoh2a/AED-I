#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float real;
  float imagem;
} TComplexo;

// Cria e retorna um numero complexo
TComplexo criarComplexo ( float real , float imag ) {
  TComplexo *c = malloc(sizeof(TComplexo));

  if(c == NULL) {
    return;
  }

  c->imagem = imag;
  c->real = real;

  return *c;
}


 // Soma dois numeros complexos
 TComplexo somarComplexos ( TComplexo a , TComplexo b ) {
  TComplexo *c = malloc(sizeof(TComplexo));

  float img = a.imagem + b.imagem;
  c->imagem = img;
  
 }

// Subtrai dois numeros complexos
TComplexo subtrairComplexos ( TComplexo a , TComplexo b );

// Multiplica dois numeros complexos
TComplexo multiplicarComplexos ( TComplexo a , TComplexo b );

// Imprime um numero complexo no formato " a + bi " ou " a - bi "
void imprimirComplexo ( TComplexo c );

