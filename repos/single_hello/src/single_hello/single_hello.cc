#include <base/log.h>
#include <base/component.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// #include "tensorflow/lite/core/interpreter_builder.h"
// #include "tensorflow/lite/interpreter.h"
// #include "tensorflow/lite/kernels/register.h"
// #include "tensorflow/lite/model_builder.h"


static __uint128_t div(__uint128_t x, __uint128_t y, __uint128_t *rp) {
	int n = 0;
	while((y>>(128-1)) != 1 && y < x) {
		y<<=1;
		n++;
	}
	__uint128_t q = 0;
	for(;; n--, y>>=1, q<<=1) {
		if(x>=y) {
			x -= y;
			q |= 1;
		}
		if(n == 0)
			break;
	}
	if(rp)
		*rp = x;
	return q;
}

extern "C" __uint128_t __udivti3(__uint128_t x, __uint128_t y) {
	return div(x, y, 0);
}


void Component::construct(Genode::Env &env)
{
	Genode::log("Hello");

	// tflite::FlatBufferModel::test();

	// const char* filename = "/tmp/multi_add.tflite";

	// std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(filename);

	// if (!model) {
	// 	Genode::error("Failed to load TensorFlow Lite model!");
	// 	return;
	// }

	env.exec_static_constructors();
}

int main() {
  return 0;
}