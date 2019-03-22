#include "EasingFuncs.h"

#include <cmath>


//

float Linear::easeNull(float t, float b, float c, float d)
{
	return c * t / d + b;
}


//

float Quad::easeIn(float t, float b, float c, float d)
{
	t /= d;
	return c * t*t + b;
}

float Quad::easeOut(float t, float b, float c, float d)
{
	t /= d;
	return -c * t*(t - 2) + b;
}

float Quad::easeInOut(float t, float b, float c, float d)
{
	t /= d / 2;
	if (t < 1) {
		return c / 2 * t*t + b;
	}
	t--;
	return -c / 2 * (t*(t - 2) - 1) + b;
}


//

float Cubic::easeIn(float t, float b, float c, float d)
{
	t /= d;
	return c * t*t*t + b;
}

float Cubic::easeOut(float t, float b, float c, float d)
{
	t /= d;
	t--;
	return c * (t*t*t + 1) + b;
}

float Cubic::easeInOut(float t, float b, float c, float d)
{
	t /= d / 2;
	if (t < 1) {
		return c / 2 * t*t*t + b;
	}
	t -= 2;
	return c / 2 * (t*t*t + 2) + b;
}


//

float Quart::easeIn(float t, float b, float c, float d)
{
	t /= d;
	return c * t*t*t*t + b;
}

float Quart::easeOut(float t, float b, float c, float d)
{
	t /= d;
	t--;
	return -c * (t*t*t*t - 1) + b;
}

float Quart::easeInOut(float t, float b, float c, float d)
{
	t /= d / 2;
	if (t < 1) return c / 2 * t*t*t*t + b;
	t -= 2;
	return -c / 2 * (t*t*t*t - 2) + b;
}


//

float Quint::easeIn(float t, float b, float c, float d)
{
	t /= d;
	return c * t*t*t*t*t + b;
}

float Quint::easeOut(float t, float b, float c, float d)
{
	t /= d;
	t--;
	return c * (t*t*t*t*t + 1) + b;
}

float Quint::easeInOut(float t, float b, float c, float d)
{
	t /= d / 2;
	if (t < 1) return c / 2 * t*t*t*t*t + b;
	t -= 2;
	return c / 2 * (t*t*t*t*t + 2) + b;
}


//

float Sine::easeIn(float t, float b, float c, float d) {
	return -c * cos(t / d * (PI / 2)) + c + b;
}

float Sine::easeOut(float t, float b, float c, float d) {
	return c * sin(t / d * (PI / 2)) + b;
}

float Sine::easeInOut(float t, float b, float c, float d) {
	return -c / 2 * (cos(PI*t / d) - 1) + b;
}


//

float Expo::easeIn(float t, float b, float c, float d) {
	return c * pow(2, 10 * (t / d - 1)) + b;
}

float Expo::easeOut(float t, float b, float c, float d) {
	return c * (-pow(2, -10 * t / d) + 1) + b;
}

float Expo::easeInOut(float t, float b, float c, float d) {
	t /= d / 2;
	if (t < 1) return c / 2 * pow(2, 10 * (t - 1)) + b;
	t--;
	return c / 2 * (-pow(2, -10 * t) + 2) + b;
}


//

float Circ::easeIn(float t, float b, float c, float d) {
	t /= d;
	return -c * (sqrt(1 - t * t) - 1) + b;
}

float Circ::easeOut(float t, float b, float c, float d) {
	t /= d;
	t--;
	return c * sqrt(1 - t * t) + b;
}

float Circ::easeInOut(float t, float b, float c, float d) {
	t /= d / 2;
	if (t < 1) return -c / 2 * (sqrt(1 - t * t) - 1) + b;
	t -= 2;
	return c / 2 * (sqrt(1 - t * t) + 1) + b;
}


//

float Back::easeIn(float t, float b, float c, float d) {
	float s = 1.70158;
	return c * (t /= d)*t*((s + 1)*t - s) + b;
}

float Back::easeOut(float t, float b, float c, float d) {
	float s = 1.70158;
	return c * ((t = t / d - 1)*t*((s + 1)*t + s) + 1) + b;
}

float Back::easeInOut(float t, float b, float c, float d) {
	float s = 1.70158f;
	if ((t /= d / 2) < 1) return c / 2 * (t*t*(((s *= (1.525)) + 1)*t - s)) + b;
	return c / 2 * ((t -= 2)*t*(((s *= (1.525)) + 1)*t + s) + 2) + b;
}


//

float Elastic::easeIn(float t, float b, float c, float d) {
	if (t == 0)
		return b;
	if ((t /= d) == 1)
		return b + c;
	float p = d * .3f;
	float a = c;
	float s = p / 4;
	return -(a * pow(2, 10 * (t -= 1)) * sin((t * d - s) * (2 * PI) / p)) + b;
}

float Elastic::easeOut(float t, float b, float c, float d) {
	if (t == 0) return b;
	if ((t /= d) == 1) return b + c;
	float p = d * .3f;
	float a = c;
	float s = p / 4;
	return (a*pow(2, -10 * t) * sin((t*d - s)*(2 * PI) / p) + c + b);
}

float Elastic::easeInOut(float t, float b, float c, float d) {
	if (t == 0)
		return b;
	if ((t /= d / 2) == 2)
		return b + c;
	float p = d * (.3f * 1.5f);
	float a = c;
	float s = p / 4;
	if (t < 1)
		return -.5f * (a * pow(2, 10 * (t -= 1)) * sin((t * d - s) * (2 * PI) / p)) + b;
	return a * pow(2, -10 * (t -= 1)) * sin((t * d - s) * (2 * PI) / p) * .5f + c + b;
}


//

float Bounce::easeIn(float t, float b, float c, float d) {
	return c - Bounce::easeOut(d - t, 0, c, d) + b;
}

float Bounce::easeOut(float t, float b, float c, float d) {
	if ((t /= d) < (1 / 2.75)) {
		return c * (7.5625*t*t) + b;
	}
	else if (t < (2 / 2.75)) {
		return c * (7.5625*(t -= (1.5 / 2.75))*t + .75) + b;
	}
	else if (t < (2.5 / 2.75)) {
		return c * (7.5625*(t -= (2.25 / 2.75))*t + .9375) + b;
	}
	else {
		return c * (7.5625*(t -= (2.625 / 2.75))*t + .984375) + b;
	}
}

float Bounce::easeInOut(float t, float b, float c, float d) {
	if (t < d / 2) return Bounce::easeIn(t * 2, 0, c, d) * .5 + b;
	return Bounce::easeOut(t * 2 - d, 0, c, d) * .5 + c * .5 + b;
}

