#pragma once
#include "State.h"
#include "StateNode.h"
#include "Map.h"
#include <list>
class Solver {
public:
	Solver(State* state);
	~Solver();
	int run();
	bool ifContain(State * state);
	StateNode * addState(State * state);
	void drawStep();
	int width;
	int height;
	StateNode *** statenodes;
	std::list <StateNode*> unexploidlist;
	std::list <StateNode*> steplist;
	Map map;
	// �ܵĵ�������
	int iterNum;
};