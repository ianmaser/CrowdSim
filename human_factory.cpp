#include "human_factory.hpp"

namespace {
	int counter = 0;
	const float START_X = 200.f, START_Y = 420.f, START_ANGLE = 45.f;
};

Person generate_human() {
	Person p(5, 3, ::counter++);
	p.setPosition(START_X, START_Y);
	p.setOrientation(START_ANGLE);
	return p;
}