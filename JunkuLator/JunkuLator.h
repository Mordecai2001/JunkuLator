#pragma once
#include <iostream>
#include "MathCalculator.h"
#include "StringTokenizer.h"
#include "MetricConvertor.h"
#include "GradeCalculator.h"
#include "Machine.h"

class JunkuLator : public Machine
{
private:
	//member variables
	MathCalculator mathCalculator{};
	MetricConvertor metricConvertor{};
	StringTokenizer stringTokenizer{};
	GradeCalculator gradeCalculator{};

};