
#include <iostream>
#include "MazeSolver.h"
#include "MazeSolver.cpp"

int main() {

 MazeSolver solver("inputA.txt");

 if(solver.mazeIsReady())
 {
 solver.solveMaze();

 solver.printSolution();
 }

cout<<"\n"<<endl;

 MazeSolver solver1("inputB.txt");

 if(solver1.mazeIsReady())
 {
 solver1.solveMaze();

 solver1.printSolution();
 }

cout<<"\n"<<endl;

 MazeSolver solver2("inputC.txt");

 if(solver2.mazeIsReady())
 {
 solver2.solveMaze();

 solver2.printSolution();
 }

cout<<"\n"<<endl;

 MazeSolver solver3("inputD.txt");

 if(solver3.mazeIsReady())
 {
 solver3.solveMaze();

 solver3.printSolution();
 }

 return 0;
} 
