#ifndef CSCTFUnpacker_h
#define CSCTFUnpacker_h

#include <FWCore/Framework/interface/EDProducer.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>

//CSC Track Finder Raw Data Format
#include "EventFilter/CSCTFRawToDigi/src/CSCTFEvent.h"

class CSCTriggerMapping;
class CSCTFMonitorInterface;

class CSCTFUnpacker: public edm::EDProducer {
private:
	CSCTriggerMapping     *mapping; // redundant, but needed
	CSCTFMonitorInterface *monitor; // not in use so far

	CSCTFEvent tfEvent; // TF data container 

	// geometry may not be properly set in CSC TF data
	// make an artificial assignment of each of 12 SPs (slots 6-11 and 16-21) to 12 sectors (1-12, 0-not assigned)
	unsigned short slot2sector[22]; 

	//virtual void beginJob(const edm::EventSetup& setup); // set up mapping 

public:
	void produce(edm::Event& e, const edm::EventSetup& c);

	CSCTFUnpacker(const edm::ParameterSet& pset);
	~CSCTFUnpacker(void);
};

#endif
