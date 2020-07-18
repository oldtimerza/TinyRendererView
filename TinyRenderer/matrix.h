#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "geometry.h"

struct Matrix3f 
{
private:
	float n[3][3];

public:
	Matrix3f() = default;
	Matrix3f(float n00, float n01, float n02,
		float n10, float n11, float n12,
		float n20, float n21, float n22)
	{
		n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
		n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
		n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
	};

	float& operator()(int i, int j)
	{
		return (n[i][j]);
	};

};

Vec3f operator *(Matrix3f& M, Vec3f& v)
{
	return (Vec3f(M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
				  M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
				  M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) *v.z
		));
}
#endif // !__MATRIX_H__


