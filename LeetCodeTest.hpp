#pragma once
#include <assert.h>

template<typename SOLUTION, typename INPUT, typename RESULT>
class LeetCodeTest {
public:
	bool AssertEqual(void* f, INPUT input, RESULT result) {
		SOLUTION solution;

		return solution.*f(input) == result;
	}
};