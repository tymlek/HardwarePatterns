#include "TestBuilder.h"

int main() {
	int status = 0;

	TestBuilder* p_TestBuilder = new TestBuilder();

	p_TestBuilder->getItsECG_Module()->acquireValue();
	p_TestBuilder->getItsECG_Module()->acquireValue();
	p_TestBuilder->getItsECG_Module()->acquireValue();
	p_TestBuilder->getItsECG_Module()->acquireValue();
	p_TestBuilder->getItsECG_Module()->acquireValue();
	
	p_TestBuilder->getItsHistogram()->getValue();
	p_TestBuilder->getItsHistogram()->getValue();
	p_TestBuilder->getItsHistogram()->getValue();
	p_TestBuilder->getItsHistogram()->getValue();
	p_TestBuilder->getItsHistogram()->getValue();

	printf("Done\n");

	delete p_TestBuilder;

	return 0;
}