#include "MyMath.h"

#include <cmath>

bool doesIntersect(const AABB& b1, const AABB& b2)
{
    if ((b2.max.x >= b1.min.x) && (b1.max.x >= b2.min.x)
        && (b2.max.y >= b1.min.y) && (b1.max.y >= b2.min.y))
        return true;

    return false;
}

Vec2::Vec2(float x_, float y_) : x(x_), y(y_)
{
}

Vec2 operator+(const Vec2& op1, const Vec2& op2)
{
    return { op1.x + op2.x, op1.y + op2.y };
}

Vec2 operator-(const Vec2& op1, const Vec2& op2)
{
    return { op1.x - op2.x, op1.y - op2.y };
}

Vec2 operator/(const Vec2& op1, const float& op2)
{
    return { op1.x / op2, op1.y / op2 };
}

Vec2 operator*(const Vec2& op1, const float& op2)
{
    return { op1.x * op2, op1.y * op2 };
}

Vec2 operator*(const float& op1, const Vec2& op2)
{
    return { op2.x * op1, op2.y * op1 };
}


float dotProduct(const Vec2& op1, const Vec2& op2)
{
    return op1.x * op2.x + op1.y * op2.y;
}


Vec2& Vec2::operator+=(const Vec2& op2)
{
    x += op2.x;
    y += op2.y;
    return *this;
}

float Vec2::getLength() const
{
    return std::sqrt(dotProduct(*this, *this));
}
