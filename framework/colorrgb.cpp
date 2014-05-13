#include "colorrgb.hpp"

ColorRGB::ColorRGB(){
	r_ = 0;
	g_ = 0;
	b_ = 0;
}

ColorRGB::ColorRGB(unsigned char const color){
	r_ = color;
	g_ = color;
	b_ = color;
}

ColorRGB::ColorRGB(unsigned char const r,unsigned char const g,unsigned char const b){
	r_ = r;
	g_ = g;
	b_ = b;
}
