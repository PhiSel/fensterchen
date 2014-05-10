#include "colorrgb.hpp"

ColorRGB::ColorRGB(){
	r_ = 0;
	g_ = 0;
	b_ = 0;
}

ColorRGB::ColorRGB(unsigned char const& c){
	r_ = c;
	g_ = c;
	b_ = c;
}

ColorRGB::ColorRGB(unsigned char const& r,unsigned char const& g,unsigned char const& b){
	r_ = r;
	g_ = g;
	b_ = b;
}

unsigned char ColorRGB::r() const{
	return static_cast<int>(r_);
}

unsigned char ColorRGB::g() const{
	return static_cast<int>(g_);
}

unsigned char ColorRGB::b() const{
	return static_cast<int>(b_);
}