/**
 * @file FishStrategy.h
 * Strategy for ><> commands.
 * @author Conlan Wesson
 */

#pragma once

#include "FungeStrategy.h"
#include <stack>

namespace Funge {

class FishStrategy : public FungeStrategy {
	public:
		explicit FishStrategy(FungeRunner& r);
		virtual ~FishStrategy() = default;
		
		virtual FungeStrategy* clone(FungeRunner& r) const override;
	
	private:
		FungeError instructionSkip();
		FungeError instructionPush(stack_t n);
		// Directions
		FungeError instructionRight();
		FungeError instructionLeft();
		FungeError instructionDown();
		FungeError instructionUp();
		// Mirrors
		FungeError instructionMirror1();
		FungeError instructionMirror2();
		FungeError instructionMirrorVert();
		FungeError instructionMirrorHori();
		FungeError instructionMirrorAll();
		// Movement
		FungeError instructionRandom();
		FungeError instructionTrampoline();
		FungeError instructionConditional();
		FungeError instructionJump();
		// Arithmetic
		FungeError instructionAdd();
		FungeError instructionSub();
		FungeError instructionMult();
		FungeError instructionDiv();
		FungeError instructionModu();
		// Comparisons
		FungeError instructionEqual();
		FungeError instructionGreater();
		FungeError instructionLess();
		// Strings
		FungeError instructionString(inst_t i);
		// Stack Manipulation
		FungeError instructionDuplicate();
		FungeError instructionRemove();
		FungeError instructionSwap2();
		FungeError instructionSwap3();
		FungeError instructionLength();
		FungeError instructionShiftLeft();
		FungeError instructionShiftRight();
		FungeError instructionReverse();
		FungeError instructionCreateStack();
		FungeError instructionRemoveStack();
		// I/O
		FungeError instructionOutChar();
		FungeError instructionOutInt();
		FungeError instructionIn();
		// Miscellaneous
		FungeError instructionRegister();
		FungeError instructionGet();
		FungeError instructionPut();
		FungeError instructionEnd();

		FungeError errorHandler(FungeError e);

		struct reg {
			bool set;
			stack_t value;
		};

		std::stack<reg> regs;
};

}
