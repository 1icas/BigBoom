#ifndef MATH_FUNCTION_PTR_H
#define MATH_FUNCTION_PTR_H

namespace BigBang {
//d = alpha* a*b + c;
template <typename dtype>
void gemm(const dtype* a, const int a_row, const int a_column, bool transpose_a, const dtype* b, const int b_row, const int b_column,
	bool transpose_b, double alpha, const dtype* c, const int c_row, const int c_column, bool transpose_c, dtype* d);

template <typename dtype>
void plus(const dtype* a, const int size, const dtype m, dtype* b);

template <typename dtype>
void minus(const dtype* a, const dtype* b, const int size, const dtype alpha, dtype* c);

template <typename dtype>
void column_sum_plus(const dtype* a, const int row, const int column, dtype* b);

template <typename dtype>
void row_sum_plus(const dtype* a, const int row, const int column, dtype* b);

}




#endif