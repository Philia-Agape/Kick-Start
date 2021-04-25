#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstring>

using namespace std;

void Increasing_Substring(int t, int** arr, char*** str, int*** out){
   /*arr = (int*)malloc((t+1) * sizeof(int)); //array of length of each string
   *str = (char**)malloc((t+1) * sizeof(char*));
   *out = (int**)malloc((t+1) * sizeof(int*));*/
   
   for (auto i =0; i<t;++i){
      cout << "Enter arr[" << i << "]" << endl;
      cin >> (*arr)[i];
      //cout << (*arr)[i] << "\n";
      //buff = (char*)malloc(*arr[i] * sizeof(char));
      (*out)[i] = (int*)calloc((*arr)[i]+1,sizeof(int));
      (*str)[i] = (char*)malloc(((*arr)[i]+1) * sizeof(char)); 
      cin >> (*str)[i];
      /*for (auto j = 0; j<(*arr)[i];++j){
         cout << (int)(*str)[i][j] << " ";
      }
      cout << endl;*/
      //strcpy(buff,str[i]); 
      //cout << buff;
      //free(buff);
   }
   
   for (auto i=0; i<t;++i){
      (*out)[i][0] = 1;
      //temp[0] = (int)buff[0];
      //temp[1] = (int)buff[1]; 
      //cout << buff[0];
      //cout << buff[1];
      //cout << (int)(*str[i][0]);
      for (auto j=1;j<((*arr)[i]);++j){
       
         if(((int)(*str)[i][j] > (int)(*str)[i][j-1])){
            (*out)[i][j] = (*out)[i][j-1]+1;
            //cout << (*out)[i][j] << " ";
         }
         else{
            (*out)[i][j] = 1;
            //cout << (*out)[i][j] << " ";
         }
      }
   }
   for (auto i=0;i<t;++i){
      cout << "Case #" << i <<": ";
      for (auto j = 0; j < (*arr)[i];++j){
         cout << (*out)[i][j] << " ";
      }
      cout << "\n";
   }
}

int main(){
   int t;
   cin >> t;
   int* arr = (int*)malloc((t+1) * sizeof(int));
   char** str = (char**)malloc((t+1) * sizeof(char*));
   int** out = (int**)malloc((t+1) * sizeof(int*));
   /*for(auto i=0;i<t;++i){
      out[i] = (int*)malloc(110*sizeof(int));
      str[i] = (char*)malloc(110*sizeof(char)); 
   }*/
   
   //arr = malloc(strlen(str) * sizeof(*arr)); 

   
   Increasing_Substring(t,&arr,&str,&out);
   free(arr); 
   free(str); 
   free(out); 
   return 0;
}
