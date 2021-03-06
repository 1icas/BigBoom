#ifndef IMAGE_FUNC_LAYER_H
#define IMAGE_FUNC_LAYER_H

#include "layer_type_macro.h"
#include "../layer.h"

namespace BigBang {
template<typename dtype>
class ImageFuncLayer : public Layer<dtype> {
public:
	ImageFuncLayer(const LayerParameter& params) :
		Layer(params) {}
	virtual ~ImageFuncLayer(){}

	virtual inline const char* FunctionType() const override {
		return IMAGE_FUNC_TYPE;
	}

protected:
	virtual void Forward_CPU(const Tensor<dtype>* bottom, Tensor<dtype>* top) override = 0;
	virtual void Backward_CPU(const Tensor<dtype>* top, Tensor<dtype>* bottom) override {};
	virtual void Forward_GPU(const Tensor<dtype>* bottom, Tensor<dtype>* top) override = 0;
	virtual void Backward_GPU(const Tensor<dtype>* top, Tensor<dtype>* bottom) override {};
};
}







#endif
