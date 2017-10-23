#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <vector> 
using namespace std;
//I initialize these constants here instead of doing it in the class Neuron to don't waste memory by copying it in each neurons 

const int tau(200);
const int C(10);
const double R(tau/C);
const int h(1);    //10-4s
const int t_start(0);
const int t_stop(1600);
const int t_refra(20);
const double V_thr(20.0);    //mV
const double V_reset(0.0);
const double Jconst(4.0);
const double Jnull(0.0);
const double Inull(0.0);
const int D(15);   //D is the number of steps h in the delay 
const int bufferSize(D+1);    //the bufffer size is equal to D the number of steps h in the delay + 1 
#endif
