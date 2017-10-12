#include "neuron.h"
#include <iostream>
#include <cmath>

Neuron::Neuron() 
	: pot_ (0.0)
	{
		spikes_.clear();
	}
	
double Neuron::getPot() const {
	return pot_; 
}

void Neuron::setPot(double pot) {
	pot_ = pot;
}

bool Neuron::getSpike() const {
	return spike_; 
}

vector<double> Neuron::getSpikes() const {
	return spikes_; 
}

double Neuron::getSpikeTime(size_t a) const {
	return spikes_[a];
}	
	
size_t Neuron::getSpikesN() const {
	return spikes_.size(); 
}

void Neuron::update (double I, double J) {
	updatePot(dt,I, J);
	updateTime();
	//updateBuffer(J)
	if(pot_ > V_thr) {
		spikes_.push_back(t_);
		spike_ = true;
	}
	else {
		spike_ = false;
	}
		
	if(!spikes_.empty()) {
		if(spikes_.back() <= t_ and t_ < (spikes_.back()+ t_refra )) {
			pot_ = V_reset;
		}
	}		
}

void Neuron::updatePot (double dt, double I, double J) {
	double const1 (exp(-dt/tau));
	double const2 (R*(1-const1));
	pot_ = ((const1*pot_) + (I*const2) + (J));        //mV
}

void Neuron::updateTime() {
	t_+=dt;
}

/*
void Neuron::updateBuffer(double J) {
	vector<double> buffer_(double 16);            // à faire autre part, c'est juste que là je sais pas oü
	if (neuron1.getSpike() == true) {
		buffer_[t_%16] = 
	}
}
*/



	 
		
	

	
	
	
	
