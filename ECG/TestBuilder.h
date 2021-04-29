#ifndef TestBuilder_H
#define TestBuilder_H

#include <stdio.h>
#include "ECGPkg.h"
#include "ECG_Module.h"
#include "HistogramDisplay.h"
#include "TMDQueue.h"

typedef struct TestBuilder TestBuilder;
struct TestBuilder {
	struct ECG_Module itsECG_Module;
	struct HistogramDisplay itsHistogramDisplay;
	struct TMDQueue itsTMEQueue;
};

void TestBuilder_Init(TestBuilder* const me);
void TestBuilder_Cleanup(TestBuilder* const me);

struct ECG_Module* TestBuilder_getItsECG_Module(const TestBuilder* const me);
struct HistogramDisplay* TestBuilder_getItsHistogram(const TestBuilder* const me);
struct TMDQueue* TestBuilder_getItsTMDQueue(const TestBuilder* const me);

TestBuilder* TestBuilder_Create();
void TestBuilder_Destroy(TestBuilder* const me);

#endif // !TestBuilder_H

