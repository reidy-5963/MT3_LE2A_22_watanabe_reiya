#pragma once
#include <cmath>
#include <assert.h>


struct Vector3 {
	float x;
	float y;
	float z;
};

struct Matrix4x4 {
	float m[4][4];
};


class MyMath {
public:
	static float Dot(const Vector3& v1, const Vector3& v2) {
		float result;
		result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

		return result;
	}
	static Vector3 Add(const Vector3& v1, const Vector3& v2) {
		Vector3 result{};
		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;
		result.z = v1.z + v2.z;
		return result;
	}
	
	static Vector3 Cross(const Vector3& v1, const Vector3& v2) {
		Vector3 result{};
		result.x = v1.y * v2.z - v1.z * v2.y;
		result.y = v1.z * v2.x - v1.x * v2.z;
		result.z = v1.x * v2.y - v1.y * v2.x;

		return result;
	}
	static Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
		Vector3 result{};
		result.x = v1.x - v2.x;
		result.y = v1.y - v2.y;
		result.z = v1.z - v2.z;
		return result;
	}


	static Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
		Matrix4x4 result{};

		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				result.m[row][column] = m1.m[row][0] * m2.m[0][column] + m1.m[row][1] * m2.m[1][column] + m1.m[row][2] * m2.m[2][column] + m1.m[row][3] * m2.m[3][column];

			}
		}

		/*result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
		result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
		result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
		result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

		result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
		result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
		result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
		result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

		result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
		result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
		result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
		result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

		result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
		result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
		result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
		result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];*/
		return result;
	}

	static Matrix4x4 MakeTranslateMatrix(const Vector3 translate) {
		Matrix4x4 result{};

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.m[i][j] = 0;
			}
		}

		/*for (int i = 0; i < 4; i++) {
			result.m[i][i] = 1;
		}*/

		result.m[0][0] = 1;
		result.m[1][1] = 1;
		result.m[2][2] = 1;
		result.m[3][3] = 1;


		result.m[3][0] = translate.x;
		result.m[3][1] = translate.y;
		result.m[3][2] = translate.z;

		return result;
	}

	static Matrix4x4 MakeScaleMatrix(const Vector3 scale) {
		Matrix4x4 result{};

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.m[i][j] = 0;
			}
		}
		result.m[0][0] = scale.x;
		result.m[1][1] = scale.y;
		result.m[2][2] = scale.z;
		result.m[3][3] = 1;

		return result;
	}

	static Matrix4x4 MakeRotateXMatrix(float radian) {
		Matrix4x4 result{ };

		result.m[0][0] = 1;
		result.m[1][1] = std::cos(radian);
		result.m[1][2] = std::sin(radian);
		result.m[2][1] = -(std::sin(radian));
		result.m[2][2] = std::cos(radian);
		result.m[3][3] = 1;


		return result;
	}

	static Matrix4x4 MakeRotateYMatrix(float radian) {
		Matrix4x4 result{ };

		result.m[0][0] = std::cos(radian);
		result.m[0][2] = -(std::sin(radian));
		result.m[1][1] = 1;
		result.m[2][0] = std::sin(radian);
		result.m[2][2] = std::cos(radian);
		result.m[3][3] = 1;


		return result;
	}

	static Matrix4x4 MakeRotateZMatrix(float radian) {
		Matrix4x4 result{ };

		result.m[0][0] = std::cos(radian);
		result.m[1][0] = -(std::sin(radian));
		result.m[0][1] = std::sin(radian);
		result.m[1][1] = std::cos(radian);
		result.m[2][2] = 1;
		result.m[3][3] = 1;


		return result;
	}

	static Matrix4x4 MakeAffineMatrix(const Vector3 scale, const Vector3 rotate, const Vector3 translate) {
		Matrix4x4 result{};

		/*Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);

		Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);*/
		Matrix4x4 rotateXYZMatrix = Multiply(
			MakeRotateXMatrix(rotate.x),
			Multiply(MakeRotateYMatrix(rotate.y), MakeRotateZMatrix(rotate.z)));

		/*result2 = Multiply(rotateXYZMatrix, translateMatrix);
		result = Multiply(rotateXYZMatrix, scaleMatrix);*/
		result.m[0][0] = rotateXYZMatrix.m[0][0] * scale.x;
		result.m[0][1] = rotateXYZMatrix.m[0][1] * scale.x;
		result.m[0][2] = rotateXYZMatrix.m[0][2] * scale.x;
		result.m[0][3] = 0;

		result.m[1][0] = rotateXYZMatrix.m[1][0] * scale.y;
		result.m[1][1] = rotateXYZMatrix.m[1][1] * scale.y;
		result.m[1][2] = rotateXYZMatrix.m[1][2] * scale.y;
		result.m[1][3] = 0;

		result.m[2][0] = rotateXYZMatrix.m[2][0] * scale.z;
		result.m[2][1] = rotateXYZMatrix.m[2][1] * scale.z;
		result.m[2][2] = rotateXYZMatrix.m[2][2] * scale.z;
		result.m[2][3] = 0;

		result.m[3][0] = translate.x;
		result.m[3][1] = translate.y;
		result.m[3][2] = translate.z;
		result.m[3][3] = 1;

		return result;
	}

	static Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRetio, float nearClip, float farClip) {
		Matrix4x4 result{};

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.m[i][j] = 0;
			}
		}

		result.m[0][0] = (1 / aspectRetio) * (1 / tan(fovY / 2));
		result.m[1][1] = (1 / tan(fovY / 2));
		result.m[2][2] = farClip / (farClip - nearClip);
		result.m[2][3] = 1;
		result.m[3][2] = (-nearClip * farClip) / (farClip - nearClip);

		return result;
	}

	static Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
		Matrix4x4 result{};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.m[i][j] = 0;
			}
		}

		result.m[0][0] = 2 / (right - left);
		result.m[1][1] = 2 / (top - bottom);
		result.m[2][2] = 1 / (farClip - nearClip);
		result.m[3][3] = 1;

		result.m[3][0] = (left + right) / (left - right);
		result.m[3][1] = (top + bottom) / (bottom - top);
		result.m[3][2] = (nearClip) / (nearClip - farClip);



		return result;
	}

	static Matrix4x4 MakeViewPortMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
		Matrix4x4 result{};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.m[i][j] = 0;
			}
		}
		result.m[0][0] = width / 2;
		result.m[1][1] = -(height / 2);
		result.m[2][2] = maxDepth - minDepth;
		result.m[3][0] = left + (width / 2);
		result.m[3][1] = top + (height / 2);
		result.m[3][2] = minDepth;
		result.m[3][3] = 1;

		return result;
	}
	
	static Matrix4x4 Inverse(const Matrix4x4& m) {
		float a =
			m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3]
			+ m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1]
			+ m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]

			- m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1]
			- m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3]
			- m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]

			- m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3]
			- m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1]
			- m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]

			+ m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1]
			+ m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3]
			+ m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]

			+ m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3]
			+ m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]
			+ m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]

			- m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1]
			- m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3]
			- m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]


			- m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0]
			- m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0]
			- m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]

			+ m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0]
			+ m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0]
			+ m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];


		Matrix4x4 result{};
		result.m[0][0] =
			(m.m[1][1] * m.m[2][2] * m.m[3][3]
				+ m.m[1][2] * m.m[2][3] * m.m[3][1]
				+ m.m[1][3] * m.m[2][1] * m.m[3][2]

				- m.m[1][3] * m.m[2][2] * m.m[3][1]
				- m.m[1][2] * m.m[2][1] * m.m[3][3]
				- m.m[1][1] * m.m[2][3] * m.m[3][2]
				) / a;

		result.m[0][1] =
			(-m.m[0][1] * m.m[2][2] * m.m[3][3]
				- m.m[0][2] * m.m[2][3] * m.m[3][1]
				- m.m[0][3] * m.m[2][1] * m.m[3][2]

				+ m.m[0][3] * m.m[2][2] * m.m[3][1]
				+ m.m[0][2] * m.m[2][1] * m.m[3][3]
				+ m.m[0][1] * m.m[2][3] * m.m[3][2]
				) / a;

		result.m[0][2] =
			(m.m[0][1] * m.m[1][2] * m.m[3][3]
				+ m.m[0][2] * m.m[1][3] * m.m[3][1]
				+ m.m[0][3] * m.m[1][1] * m.m[3][2]

				- m.m[0][3] * m.m[1][2] * m.m[3][1]
				- m.m[0][2] * m.m[1][1] * m.m[3][3]
				- m.m[0][1] * m.m[1][3] * m.m[3][2]
				) / a;

		result.m[0][3] =
			(-m.m[0][1] * m.m[1][2] * m.m[2][3]
				- m.m[0][2] * m.m[1][3] * m.m[2][1]
				- m.m[0][3] * m.m[1][1] * m.m[2][2]

				+ m.m[0][3] * m.m[1][2] * m.m[2][1]
				+ m.m[0][2] * m.m[1][1] * m.m[2][3]
				+ m.m[0][1] * m.m[1][3] * m.m[2][2]
				) / a;



		result.m[1][0] =
			(-m.m[1][0] * m.m[2][2] * m.m[3][3]
				- m.m[1][2] * m.m[2][3] * m.m[3][0]
				- m.m[1][3] * m.m[2][0] * m.m[3][2]

				+ m.m[1][3] * m.m[2][2] * m.m[3][0]
				+ m.m[1][2] * m.m[2][0] * m.m[3][3]
				+ m.m[1][0] * m.m[2][3] * m.m[3][2]
				) / a;

		result.m[1][1] =
			(m.m[0][0] * m.m[2][2] * m.m[3][3]
				+ m.m[0][2] * m.m[2][3] * m.m[3][0]
				+ m.m[0][3] * m.m[2][0] * m.m[3][2]

				- m.m[0][3] * m.m[2][2] * m.m[3][0]
				- m.m[0][2] * m.m[2][0] * m.m[3][3]
				- m.m[0][0] * m.m[2][3] * m.m[3][2]
				) / a;

		result.m[1][2] =
			(-m.m[0][0] * m.m[1][2] * m.m[3][3]
				- m.m[0][2] * m.m[1][3] * m.m[3][0]
				- m.m[0][3] * m.m[1][0] * m.m[3][2]

				+ m.m[0][3] * m.m[1][2] * m.m[3][0]
				+ m.m[0][2] * m.m[1][0] * m.m[3][3]
				+ m.m[0][0] * m.m[1][3] * m.m[3][2]
				) / a;

		result.m[1][3] =
			(m.m[0][0] * m.m[1][2] * m.m[2][3]
				+ m.m[0][2] * m.m[1][3] * m.m[2][0]
				+ m.m[0][3] * m.m[1][0] * m.m[2][2]

				- m.m[0][3] * m.m[1][2] * m.m[2][0]
				- m.m[0][2] * m.m[1][0] * m.m[2][3]
				- m.m[0][0] * m.m[1][3] * m.m[2][2]
				) / a;



		result.m[2][0] =
			(m.m[1][0] * m.m[2][1] * m.m[3][3]
				+ m.m[1][1] * m.m[2][3] * m.m[3][0]
				+ m.m[1][3] * m.m[2][0] * m.m[3][1]

				- m.m[1][3] * m.m[2][1] * m.m[3][0]
				- m.m[1][1] * m.m[2][0] * m.m[3][3]
				- m.m[1][0] * m.m[2][3] * m.m[3][1]
				) / a;

		result.m[2][1] =
			(-m.m[0][0] * m.m[2][1] * m.m[3][3]
				- m.m[0][1] * m.m[2][3] * m.m[3][0]
				- m.m[0][3] * m.m[2][0] * m.m[3][1]

				+ m.m[0][3] * m.m[2][1] * m.m[3][0]
				+ m.m[0][1] * m.m[2][0] * m.m[3][3]
				+ m.m[0][0] * m.m[2][3] * m.m[3][1]
				) / a;

		result.m[2][2] =
			(m.m[0][0] * m.m[1][1] * m.m[3][3]
				+ m.m[0][1] * m.m[1][3] * m.m[3][0]
				+ m.m[0][3] * m.m[1][0] * m.m[3][1]

				- m.m[0][3] * m.m[1][1] * m.m[3][0]
				- m.m[0][1] * m.m[1][0] * m.m[3][3]
				- m.m[0][0] * m.m[1][3] * m.m[3][1]
				) / a;

		result.m[2][3] =
			(-m.m[0][0] * m.m[1][1] * m.m[2][3]
				- m.m[0][1] * m.m[1][3] * m.m[2][0]
				- m.m[0][3] * m.m[1][0] * m.m[2][1]

				+ m.m[0][3] * m.m[1][1] * m.m[2][0]
				+ m.m[0][1] * m.m[1][0] * m.m[2][3]
				+ m.m[0][0] * m.m[1][3] * m.m[2][1]
				) / a;



		result.m[3][0] =
			(-m.m[1][0] * m.m[2][1] * m.m[3][2]
				- m.m[1][1] * m.m[2][2] * m.m[3][0]
				- m.m[1][2] * m.m[2][0] * m.m[3][1]

				+ m.m[1][2] * m.m[2][1] * m.m[3][0]
				+ m.m[1][1] * m.m[2][0] * m.m[3][2]
				+ m.m[1][0] * m.m[2][2] * m.m[3][1]
				) / a;

		result.m[3][1] =
			(m.m[0][0] * m.m[2][1] * m.m[3][2]
				+ m.m[0][1] * m.m[2][2] * m.m[3][0]
				+ m.m[0][2] * m.m[2][0] * m.m[3][1]

				- m.m[0][2] * m.m[2][1] * m.m[3][0]
				- m.m[0][1] * m.m[2][0] * m.m[3][2]
				- m.m[0][0] * m.m[2][2] * m.m[3][1]
				) / a;


		result.m[3][2] =
			(-m.m[0][0] * m.m[1][1] * m.m[3][2]
				- m.m[0][1] * m.m[1][2] * m.m[3][0]
				- m.m[0][2] * m.m[1][0] * m.m[3][1]

				+ m.m[0][2] * m.m[1][1] * m.m[3][0]
				+ m.m[0][1] * m.m[1][0] * m.m[3][2]
				+ m.m[0][0] * m.m[1][2] * m.m[3][1]
				) / a;

		result.m[3][3] =
			(m.m[0][0] * m.m[1][1] * m.m[2][2]
				+ m.m[0][1] * m.m[1][2] * m.m[2][0]
				+ m.m[0][2] * m.m[1][0] * m.m[2][1]

				- m.m[0][2] * m.m[1][1] * m.m[2][0]
				- m.m[0][1] * m.m[1][0] * m.m[2][2]
				- m.m[0][0] * m.m[1][2] * m.m[2][1]
				) / a;

		return result;
	}
	
	static Matrix4x4 Transpose(const Matrix4x4& m) {
		Matrix4x4 result{};

		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				result.m[row][column] = m.m[column][row];
			}
		}

		//result.m[0][0] = m.m[0][0];
		//result.m[0][1] = m.m[1][0];
		//result.m[0][2] = m.m[2][0];
		//result.m[0][3] = m.m[3][0];

		//result.m[1][0] = m.m[0][1];
		//result.m[1][1] = m.m[1][1];
		//result.m[1][2] = m.m[2][1];
		//result.m[1][3] = m.m[3][1];


		return result;
	}
	
	static Matrix4x4 MakeIdentity4x4() {
		Matrix4x4 result{};

		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				result.m[row][column] = 0;
			}
		}
		result.m[0][0] = 1;
		result.m[1][1] = 1;
		result.m[2][2] = 1;
		result.m[3][3] = 1;

		return result;
	}

	static Vector3 TransformCoord(Vector3 vector, Matrix4x4 matrix) {
		Vector3 result{};
		result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
		result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
		result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];

		float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
		assert(w != 0.0f);
		result.x /= w;
		result.y /= w;
		result.z /= w;
		return result;
	};
};