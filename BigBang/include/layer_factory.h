#ifndef LAYER_FACTORY_H
#define LAYER_FACTORY_H

#include <cassert>
#include <map>
#include <memory>
#include <string>

#include "base.h"
#include "layer.h"
#include "../proto/bigbang.pb.h"

namespace BigBang {

template<typename dtype>
class LayerRegistry {
public:
	typedef std::shared_ptr<Layer<dtype>>(*Creator) (const LayerParameter& params);
	typedef std::map<std::string, Creator> CreatorRegistry;

	LayerRegistry() = delete;

	static CreatorRegistry& Registry() {
		static CreatorRegistry registry;
		return registry;
	}

	static void AddCreator(const std::string& type, Creator creator) {
		CreatorRegistry& registry = Registry();
		if (!registry.count(type)) {
			registry[type] = creator;
		}
	}

	static std::shared_ptr<Layer<dtype>> CreateLayer(const LayerParameter& params) {
		CreatorRegistry& registry = Registry();
		std::string type = params.type();
		if (registry.count(type)) {
			return registry[type](params);
		}
		
		THROW_EXCEPTION;
		return nullptr;
	}

};

template<typename dtype>
class LayerRegisterer {
public:
	LayerRegisterer(const std::string& type, std::shared_ptr<Layer<dtype>>(*creator) (const LayerParameter& params)) {
		LayerRegistry<dtype>::AddCreator(type, creator);
	}
};


#define REGISTRY_LAYER(type) \
	template<typename dtype> \
	std::shared_ptr<Layer<dtype>> Creator##type##Layer(const LayerParameter& params) { \
		return std::shared_ptr<Layer<dtype>>(new type##Layer<dtype>(params)); \
	} \
	static LayerRegisterer<float> g_layer_##type##_float_(#type, Creator##type##Layer); \
	static LayerRegisterer<double> g_layer_##type##_double_(#type, Creator##type##Layer); 
}


#endif
