﻿// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TDynamicMatrix<int> a(3), b(3), c(3);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами" << endl;
  for (i = 0; i < 3; i++)
  {
      for (j = i; j < 3; j++)
      {
          a[i][j] = i * 10 + j;
          b[i][j] = (i * 10 + j) * 100;
      }
  }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
}
//---------------------------------------------------------------------------
