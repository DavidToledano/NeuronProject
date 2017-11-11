#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <vector> 
using namespace std;

/** I initialize these constants here instead of doing it in the 
 * class Neuron to don't waste memory by copying it in each neurons. 
 * Of cuirse, my code is far from being perfectly optimized for the memory
 * but here I was aware of this, so I did like that */

const double tau(200.0);      /**< constant for the differential equation */
const double C(10.0);         /**< constant for the differential equation */
const double R(tau/C);        /**< constant for the differential equation */
const double h(1.0);          /**< the step (10-4s) */
const int t_refra(20);        /**< the length of therefractory period */
const double V_thr(20.0);     /**< the threshold */
const double V_reset(0.0);    /**< the potnetial reset after a spike */
const double Jnull(0.0);      /**< to fill the buffer when there is no spike */
const double Inull(0.0);	  /**< there is no current into the the network */
const int D(15);              /**< D is the number of steps h in the delay */
const int bufferSize(D+1);    /**< the bufffer size is equal to D, the number of steps h in the delay, + 1 */
const int n_e(10000);         /**< the number of exitatory neurons */
const int n_i(2500);          /**< the number of Inhibitory neurons */ 
const int n_neurons(n_i+n_e); /**< the total number of neurons */
const double J_e(0.1);        /**< the potential transmitted by an exitatory neuron */
const double J_i(-0.5);       /**< the potential transmitted by an Inhibitory neuron */
const double C_e(1000);       /**< the number of exitatory connections received by a neuron */
const double C_i(250);        /**< the number of Inhibitory connections received by a neuron */
const double C_tot(C_e+C_i);  /**< the total number of connections for each neuron */
const double mu_thr(V_thr/(C_e*J_e*tau));    /**< unit of the external frequency */
const double mu_ext(2*mu_thr);               /**< the external frequancy (expressed in units of mu_thr) */ 
const double lambda(mu_ext*C_e*h*J_e*10);    /**< the rate lambda for the Poisson Distribution */

#endif
