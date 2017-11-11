#include "neuron.h"
#include "random"
#include <cmath>

/**
*  Constructor
*/

Neuron::Neuron()
/**
 * The constructor inisializes the neuron's attributs 
 */
	: pot_ (0.0), clock_(0), n_spikes_(0), spike_(false), e_(true), received_spikes_(0)
	{
		spikes_.clear();
		buffer_.clear();
		received_connections_.clear();
		sent_connections_.clear();
		received_spikes_.clear();
		for(size_t i=0; i < bufferSize; i++) {
			buffer_.push_back(0.0);
		}
	}


/*****************************************************/	

/**
 * ... Getters ...
 */
	
double Neuron::getPot() const {
	return pot_; 
}

bool Neuron::getSpike() const {
	return spike_; 
}

vector<int> Neuron::getSpikes() const {
	return spikes_; 
}

double Neuron::getSpikeTime(size_t a) const {
	return spikes_[a];
}	
	
int Neuron::getSpikesN() const {
	return n_spikes_; 
}

int Neuron::getClock() const {
	return clock_;
}

double Neuron::bufferAfterDelay() {
	double J(buffer_[clock_%(bufferSize)]);
	/** When we access to the buffer, 
	 * we have to immidiatly reinitialize it 
	 * for the next spikes
	 */
	buffer_[clock_%(bufferSize)] = 0;
	return J;
}

bool Neuron::getE() {
	return e_;
}

vector<int> Neuron::getReceivedConnections() {
	return received_connections_;
}

vector<int> Neuron::getSentConnections() {
	return sent_connections_;
}

vector<int> Neuron::getReceivedSpikes() {
	return received_spikes_;
}


/*****************************************************/	

/** 
 * ... Setters ...
 */

void Neuron::setPot(double pot) {
	pot_ = pot;
}

void Neuron::setBuffer(bool e) {
	if(e) {
		buffer_[(clock_+D)%(bufferSize)] += J_e;
	}
	else {
		buffer_[(clock_+D)%(bufferSize)] += J_i;
	}
}

void Neuron::setE(bool b) {
	e_ = b;
}


/*****************************************************/

/**
 * ... Updaters ...
 */

bool Neuron::update (double I, double noise) {
	updateClock();
	updatePot(I, bufferAfterDelay(),noise);
	/** The clock is updated first and then we calculate the potential 
	 * because the differential equation calculate "V(t+h)".
	 */
	if(pot_ > V_thr) {
		spikes_.push_back(clock_);
		spike_ = true;
		n_spikes_++;
	}
	else {
		spike_ = false;
	}
	
	/** Dealing with the refractory time
	 */
	if(!spikes_.empty()) {
		if(spikes_.back() <= clock_ and clock_ < (spikes_.back()+ t_refra )) {
			pot_ = V_reset;
		}
	}
	
	return spike_;
	/** Update return true if the neuron is spiking 
	 */ 	
}


void Neuron::updatePot (double I, double J, double noise) {
	pot_ = exp(-h/tau)*pot_ + I*R*(1-exp(-h/tau)) + J + noise;	/** mV */
}


void Neuron::updateClock() {
	clock_+=h;
}


/*****************************************************/

/**
 * ... Adders ...
 */

void Neuron::addReceivedConnection(int c) {
	received_connections_.push_back(c);
}

void Neuron::addSentConnection(int c) {
	sent_connections_.push_back(c);
}
	
void Neuron::addReceivedSpike(int t) {
	received_spikes_.push_back(t+D);
}


/*****************************************************/
	
	

	 
		
	

	
	
	
	
