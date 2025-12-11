#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

#define EPS 0.00001

int confereValido(Ponto *p)
{
  if (p == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

Ponto *criaPonto(float x, float y)
{
  Ponto *p = malloc(sizeof(Ponto));
  if (!confereValido(p))
  {
    return NULL;
  }
  p->x = x;
  p->y = y;
  return p;
}

void liberaPonto(Ponto *p)
{
  if (!confereValido(p))
  {
    return;
  }
  free(p);
}

void acessaPonto(Ponto *p, float *x, float *y)
{
  if (!confereValido(p))
  {
    return;
  }
  *x = p->x;
  *y = p->y;
}

void atribuiPonto(Ponto *p, float x, float y)
{
  if (!confereValido(p))
  {
    return;
  }
  p->x = x;
  p->y = y;
}

float distancia(Ponto *p1, Ponto *p2)
{
  if ((p1 == NULL) || (p2 == NULL))
  {
    return -1;
  }
  float dx = p1->x - p2->x;
  float dy = p1->y - p2->y;
  float d = sqrtf(dx * dx + dy * dy);
  return d;
}

float distanciaOrigem(Ponto *p)
{
  if (!confereValido(p))
  {
    return -1;
  }
  float d = sqrtf(p->x * p->x + p->y * p->y);
  return d;
}

void imprimePonto(Ponto *p)
{
  if (!confereValido(p))
  {
    return;
  }
  printf("(%.3f,%.3f)", (*p).x, (*p).y);
}

int pontosIguais(Ponto *p1, Ponto *p2)
{
  float diff_x = (*p1).x - (*p2).x;

  if (fabs(diff_x) > EPS)
  {
    return 0;
  }

  float diff_y = (*p1).y - (*p2).y;

  if (fabs(diff_y) > EPS)
  {
    return 0;
  }

  return 1;
}