#include <bits/stdc++.h>

using namespace std;

int** create(int n){
   
   int **matrix = (int**) malloc((3*n)*sizeof(int*));
      for (int i=0;i<3;++i){
         matrix[i] = (int*) malloc(3*sizeof(int));
      }
   return matrix;
}

void input (int n, int **matrix){
   
   
   for(int i=0; i<3*n; ++i){
      if(i % 3 == 1){
         std::cin >> matrix[i][0];
         std::cin >> matrix[i][2];
      }
      else{
         for(int j=0; j<3; ++j){
            std::cin >> matrix[i][j];
         }
      }
   }
   return;
   
}


void find(int n, int **matrix, int **sum){
   int center[3];
   int index = 0;
   int temp = 0;
   while(index < n){
      for(int i=3*index; i<3*(index+1); ++i){ 
         if((i % 3 != 1) && (matrix[i][0] + matrix[i][2] == matrix[i][1]<<1)){
            ++(*sum)[index];
         }   
         if((i % 3 == 0) && ((matrix)[i][0] + (matrix)[i+2][0] == matrix[i+1][0]<<1)){
            ++(*sum)[index];
         } 
         if((i % 3 == 0) && (matrix[i][2] + matrix[i+2][2] == matrix[i+1][2]<<1)){
            ++(*sum)[index];
         }   
         if(i % 3 == 1){
            temp = 0; //Initialize!
            center[0] = (matrix[i][0]+matrix[i][2]); 
            center[1] = (matrix[i-1][1]+matrix[i+1][1]);
            center[2] = (matrix[i-1][0]+matrix[i+1][2]);
            center[3] = (matrix[i+1][0]+matrix[i-1][2]);
            for(int j=0; j<=2; ++j){
               for(int k=j+1; k<=3; ++k){
                   if(center[j] == center[j+1]){
                      ++temp;
                   }
              }
              //compare with center[0] done!
              if(temp == 3){
                  (*sum)[index] = (*sum)[index]+4;
                  break;
               }
               if(temp == 2){
                  (*sum)[index] = (*sum)[index]+3;
                  break;
               }
               if(temp == 1){
                  (*sum)[index] = (*sum)[index]+2;
                  break;
               }
               //temp == 0 continue;
            }
            if(temp == 0){
              ++(*sum)[index];    
            }
      }
   }
      
   ++index;
   }
   
   for(int i=0; i<n; ++i){
      cout << "Case #" << n << ": ";
      cout << (*sum)[i] << "\n";
   }
   
   return;
}


int main(){
   int n;
   cin >> n;
   int **matrix;
   matrix = create(n);
   input(n,matrix);
   
   int* sum = (int*) malloc(n*sizeof(int));
   find(n,matrix,&sum);  
   
   
   return 0;
}
