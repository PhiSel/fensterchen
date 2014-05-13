#include <UnitTest++.h>
#include "point2d.hpp"
#include "colorrgb.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

SUITE(describe_Point2d){

	//Standardkonstruktor - Erzeugt einen Punkt im Ursprung
	Point2d point_1{};
	TEST(position_of_point_1_should_be_0_and_0){
		CHECK_EQUAL(0.0, point_1.x());
		CHECK_EQUAL(0.0, point_1.y());
	}

	//Selbstgeschriebener Konstruktor
	Point2d point_2{2.0,7.3};
	TEST(position_of_point_2_should_be_2_and_7_3){
		CHECK_CLOSE(2.0, point_2.x(), 0.01);
		CHECK_CLOSE(7.3, point_2.y(), 0.01);
	}
	TEST(position_of_point_2_after_translate_should_be_6_8_and_17_5){
		point_2.translate(4.8,10.2);
		CHECK_CLOSE(6.8, point_2.x(), 0.01);
		CHECK_CLOSE(17.5, point_2.y(), 0.01);
	}
	TEST(position_of_point_2_after_rotate_should_be_14_6390_and_11_7554){ //30°
		point_2.rotate(0.5236);
		CHECK_CLOSE(14.6390, point_2.x(), 0.01);
		CHECK_CLOSE(11.7554, point_2.y(), 0.01);
	} 

	//Farbtest 1. Konstruktor
	ColorRGB black{0};
	TEST(color_of_black_should_be){
		CHECK_EQUAL(0, black.r_);
		CHECK_EQUAL(0, black.g_);
		CHECK_EQUAL(0, black.b_);
	}

	//Farbtest 2. Konstruktor
	ColorRGB red{255,0,0};
	TEST(color_of_red_should_be){
		CHECK_EQUAL(255, red.r_);
		CHECK_EQUAL(0, red.g_);
		CHECK_EQUAL(0, red.b_);
	}
	/*
	ColorRGB fale_test(395,256,98);
	TEST(color_of_fale_test_should_be){
		CHECK_EQUAL(395, red.r_;
		CHECK_EQUAL(256, red.g_;
		CHECK_EQUAL(98, red.b_;
	}
	*/
	//Kreistest 1. Konstruktor
	Circle circle_1 = Circle();
	TEST(circle_1_should_be){
		CHECK_CLOSE(1,circle_1.radius(), 0.01);
		CHECK_CLOSE(0, circle_1.center().x(), 0.01);
		CHECK_CLOSE(0, circle_1.center().y(), 0.01);
		CHECK_EQUAL(0, circle_1.color().r_);
		CHECK_EQUAL(0, circle_1.color().g_);
		CHECK_EQUAL(0, circle_1.color().b_);
		CHECK_CLOSE(6.283, circle_1.circumference(), 0.01);
		CHECK_EQUAL(true, circle_1.is_inside({0.52,0.36}));
		CHECK_EQUAL(false, circle_1.is_inside({0.99,0.4}));
	}
	//Kreistest 2. Konstruktor
	Circle circle_2{{3.2,-5.0},-6.4,{123,4,78}};
	TEST(circle_2_should_be){
		CHECK_CLOSE(6.4, circle_2.radius(), 0.01);
		CHECK_CLOSE(3.2, circle_2.center().x(), 0.01);
		CHECK_CLOSE(-5.0, circle_2.center().y(), 0.01);
		CHECK_EQUAL(123, circle_2.color().r_);
		CHECK_EQUAL(4, circle_2.color().g_);
		CHECK_EQUAL(78, circle_2.color().b_);
		CHECK_CLOSE(40.212, circle_2.circumference(), 0.01);
		CHECK_EQUAL(true, circle_2.is_inside({2.83, 0.53}));
		CHECK_EQUAL(false, circle_2.is_inside({12.22, -2.31}));
	}
	//Rechtecktest 1. Konstruktor
	Rectangle rectangle_1{};
	TEST(rectangle_1_should_be){
		CHECK_CLOSE(0, rectangle_1.lowerleft().x(), 0.01);
		CHECK_CLOSE(0, rectangle_1.lowerleft().y(), 0.01);
		CHECK_CLOSE(2, rectangle_1.width(), 0.01);
		CHECK_CLOSE(3, rectangle_1.height(), 0.01);
		CHECK_EQUAL(0, rectangle_1.color().r_);
		CHECK_EQUAL(0, rectangle_1.color().g_);
		CHECK_EQUAL(0, rectangle_1.color().b_);
		CHECK_CLOSE(10, rectangle_1.circumference(), 0.01);
		CHECK_EQUAL(true, rectangle_1.is_inside({1,1}));
		CHECK_EQUAL(false, rectangle_1.is_inside({4,4}));
	}
	//Rechtecktest 2. Konstruktor
	Rectangle rectangle_2{{5.2,3},23.43,10.45,{153,45,2}};
	TEST(rectangle_2_should_be){
		CHECK_CLOSE(5.2, rectangle_2.lowerleft().x(), 0.01);
		CHECK_CLOSE(3, rectangle_2.lowerleft().y(), 0.01);
		CHECK_CLOSE(23.43, rectangle_2.width(), 0.01);
		CHECK_CLOSE(10.45, rectangle_2.height(), 0.01);
		CHECK_EQUAL(153, rectangle_2.color().r_);
		CHECK_EQUAL(45, rectangle_2.color().g_);
		CHECK_EQUAL(2, rectangle_2.color().b_);
		CHECK_CLOSE(67.76, rectangle_2.circumference(), 0.01);
		CHECK_EQUAL(true, rectangle_2.is_inside({10.43,8.12}));
		CHECK_EQUAL(false, rectangle_2.is_inside({30.5,6.3}));

		rectangle_2.translate(0.8,1.0);
		CHECK_CLOSE(6.0, rectangle_2.lowerleft().x(), 0.01);
		CHECK_CLOSE(4.0, rectangle_2.lowerleft().y(), 0.01);
	}
}

int main()
{
	return UnitTest::RunAllTests();
}
