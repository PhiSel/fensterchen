#ifndef BUW_COLORRGB_HPP 
#define BUW_COLORRGB_HPP

struct ColorRGB
{
	ColorRGB();
	ColorRGB(unsigned char const&);
	ColorRGB(unsigned char const&, unsigned char const&, unsigned char const&);
	unsigned char r() const;
	unsigned char g() const;
	unsigned char b() const;
	unsigned char r_,g_,b_;
};

#endif