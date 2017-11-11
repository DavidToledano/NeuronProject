#include "gtest/gtest.h"
#include "network.h"
#include "neuron.h"

using namespace std;

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

/** ... TEST 1 .../
 */
TEST (SingleNeuron, Potential) {
	Neuron n1;
	EXPECT_EQ(0, n1.getPot());
	/** The most basic test, to start,
	 * testing the constructor and the getter of the potential */
}

/** ... TEST 2 .../
 */
TEST (SingleNeuron, Update) {
	Neuron n1; 
	n1.update(1.0, 0);
	EXPECT_EQ(1.0*R*((1-exp(-h/tau))), n1.getPot());
}

/** ... TEST 3 .../
 */
TEST (SingleNeuron, SeveralUpdates) {
	Neuron n1;
	for (int i(0); i<10000; ++i) {
		n1.update(1.0, 0);				 /** When the the external current is 1.0 the membrane potential 			   		  */
	}									/** should tend to the treshold without reaching it.					      		 */
	int pot(n1.getPot());              /** We can't expect the exact value of the potential which tend toward 20.    		*/
	EXPECT_EQ(pot, 19);			  	  /** That's why we use an int to show that it will stay under 20 after several updates*/
}	                                 /** The real value is 19,999... a number we cannot enter in the gtest 		   		  */

/** ... TEST 4 .../
 */
TEST (SingleNeuron, SpikeRefractory) {
	Neuron n1;
	do {} 
	while(!n1.update(1.01, 0));    /** While the neuron is not spiking, he is still updating */
	EXPECT_EQ(0, n1.getPot());    /** At the end of the while, the neuron is to be spiking (Iext > 1.0) */
}								 /** so we check that he well enters in the refractory time */

/** ... TEST 5 .../
 */
TEST (TwoNeurons, SpikeDelayBuffer) {
	Network net(2);
	while (net.getNeurons()[0].getSpike() == false) {
		net.update(4.0);
	}														/** The end of the while is when the first neuron spikes */
	int spikeTimeNeuron1(net.getNeurons()[0].getClock());  /** Then we want to see what happen to the neuron that is*/
	while (net.getNeurons()[1].getPot() == 0) {			  /** supposed to receive the spike after the delay. 	   */
		net.update(4.0);								 /** His potential is to be 0 until the reception		  */
	}													/**  of the spike thru his buffer						 */
	EXPECT_EQ(net.getNeurons()[0].getClock(), spikeTimeNeuron1 + D); /** This moment should 					*/
	EXPECT_EQ(net.getNeurons()[1].getClock(), spikeTimeNeuron1 + D);/** occur after the delay. 				   */
	EXPECT_EQ(net.getNeurons()[1].getPot(), J_e);				   /** At this momoment, the potential 		  */
}																  /** of the second neuron should be the J_e */
	


/** ... TEST 6 .../
	* This test is a bit long (more than five minutes) and doesn't work perfectly
	* So I have decided to skip it 
	* but I prefer to leave it hear because I took a lot of time to design it 
	* so that you can see the idea.
	* It was maybe a to ambitious. I wanted to test the spreading 
	* of a specific spike into the network, and see if the network reacts
	* correctly to it. It was very difficult to focus only on one spike among all of them.
	* I think I haven't fully succed it, but I tried.
	*/	
/*TEST (Network, spikeSpreading) {
	Network network;
	int t(0);
	*/
	/** Same as the previous test at the begining
	 * we want to check what happens 
	 * when the first neuron is spiking 
	 * for the first time
	 */
	 
	/*while(!network.getNeurons()[0].getSpike()) {
		network.update();
		t+=h;
	}
	*/

	/** Then, for all the neuron which receives a potentiel from the spiking neurons_[0],
	 * if the spike/potential(J) of neurons_[0] is the only spike/potential(J)
	 * that it (the neuron which receives a potentiel from neurons_[0])
	 * receives among all the received connections he has,
	 * (we want it to be the only one to check the precise behavior 
	 * of one spike)
	 * the expected value of the buffers after the delay of the neurons
	 * that receive a spike only from neurons_[0]
	 * is J_e
	 * since neurons_[0] is an excitatory neuron
	 * */
	  
	/*for(int i(0);i<D; ++i) {
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
*/
	
			

