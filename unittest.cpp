#include "gtest/gtest.h"
#include "network.h"
#include "neuron.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST (NeuronTest, potential) {
	Neuron n1;
	EXPECT_EQ(0, n1.getPot());
}

TEST (NeuronTest, spike) {
	Network network;
	int t(0);
	/* we want to check what happens 
	 * when the first neuron is spiking 
	 * for the first time
	*/
	while(!network.getNeurons()[0].getSpike()) {
		network.update();
		t+=h;
	}
	EXPECT_EQ(0, network.getNeurons()[0].getPot());    // Did the neuron well enter in the refractory time
	
	/* For all the neuron which receives a potentiel from the spiking neurons_[0],
	 * if the spike/potential(J) of neurons_[0] is the only spike/potential(J)
	 * that it (the neuron which receives a potentiel from neurons_[0])
	 * receives among all the received connections he has,
	 * the expected value of the buffers after the delay of the neurons
	 * that receive a spike only from neurons_[0]
	 * is J_e
	 * since neurons_[0] is an excitatory neuron
	 */
	  
	for(int i(0);i<D; ++i) {
		network.update();
		t+=h;
	} 
	for(auto sCon : network.getNeurons()[0].getSentConnections()) {
		int i(0);
		for(auto rSpike : network.getNeurons()[sCon].getReceivedSpikes()){
			if(rSpike == t) {
				i++;
			}
		}
		if(i == 1) {
			EXPECT_EQ(J_e, network.getNeurons()[sCon].bufferAfterDelay());
		}
	}
}
	
			

