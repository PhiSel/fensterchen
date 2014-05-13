#ifndef BUW_COLORRGB_HPP 
#define BUW_COLORRGB_HPP

struct ColorRGB
{
	ColorRGB();
	ColorRGB(unsigned char const color);
	ColorRGB(unsigned char const r, unsigned char const g, unsigned char const b);
	unsigned char r_,g_,b_;
};

#endif