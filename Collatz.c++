// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"


using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    int kmax;
    int imax;
    int imin;
    int klength;

    kmax=1;

    if(i>j){
       imax=i;
       imin=j;
    }
    else{
       imax=j;
       imin=i;
    }

    for (int n=imin;n<=imax;n++){
        
       klength=cycle_length(n);
     
       if(kmax<klength){
	       kmax=klength;
       }
    
    }
    
    return kmax;

}


//_______________________

// cycle_length

//______________________

unsigned short cach[1000000];

int cycle_length(int n){
      
      int bigcycle=1;
      cach[1]=1;

      if (n>1000000){

          if (n%2==0){
          bigcycle = cycle_length(n/2)+1;
          }
          else{
          bigcycle = cycle_length(3*n+1)+1;
     
          }
          
          return bigcycle;

      }
      
   
      if(cach[n]==0){

           if((n%2)==0){
             
             cach[n]=cycle_length(n/2)+1; 
              
           }

           else{
             
             cach[n]=cycle_length(3*n+1)+1; 

           }
      
      }

      return cach[n];
     
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
