#ifndef BASE_H
#define BASE_H

#include <cassert>

#define CHECK_OP(op, val1, val2) \
	if(!(val1 op val2)) assert(false);

#define CHECK_EQ(a, b) \
	CHECK_OP(==, a, b)

#define CHECK_GT(a, b) \
	CHECK_OP(>, a, b)

#define CHECK_LT(a, b) \
	CHECK_OP(<, a, b)

#define CHECK_GTE(a, b) \
	CHECK_OP(>=, a, b)

#define CHECK_LTE(a, b) \
	CHECK_OP(<=, a, b)

#define THROW_EXCEPTION assert(false)

#define VALIDATE_POINTER(p) \
	assert(p != nullptr);


#define DISABLE_COPY_AND_ASSIGNMENT(classname) \
	classname(const classname& c) = delete; \
	classname& operator=(const classname& c) = delete;

#define INSTANTIATE_CLASS(classname) \
	template class classname<float>; \
	template class classname<double>;

#endif