#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

int ** adj_mat(){ 
  // Carregando a matriz
  int size = 946;
  // Cria uma matriz vazia com 48 de largura x altura
  int** mat = new int*[size];
  for(int i = 0; i<size; i++){
      mat[i] = new int[size];
  }
  for(int i = 0; i<size; i++){
      for(int j = 0; j<size; j++){
          mat[i][j] = 0;

      }
  }

  std::ifstream file("data/frb45-21-5.clq");
  std::string   line;
  std::getline(file, line);

  while(std::getline(file, line))
  {
      std::stringstream   linestream(line);
      std::string         data;
      int                 val1;
      int                 val2;
      std::getline(linestream, data, ' ');
      linestream >> val1 >> val2;
      mat[val1][val2] = 1;
      mat[val2][val1] = 1;
      mat[val1][val1] = 1;
      mat[val2][val2] = 1;
  }
  return mat;
}

int** mat = adj_mat();