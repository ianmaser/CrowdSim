#include "human_factory.hpp"

namespace {
	int counter = 0;
};

Person generate_human() {
	Person p(5, 3, ::counter++);
	return p;
}