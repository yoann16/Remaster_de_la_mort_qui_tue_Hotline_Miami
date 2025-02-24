#pragma once

struct Vec2
{
    Vec2(float x_, float y_);

    float x;
    float y;

    Vec2& operator+=(const Vec2& op2);

    float getLength() const;
};

Vec2 operator+(const Vec2& op1, const Vec2& op2);
Vec2 operator-(const Vec2& op1, const Vec2& op2);
Vec2 operator/(const Vec2& op1, const float& op2);
Vec2 operator*(const Vec2& op1, const float& op2);
Vec2 operator*(const float& op1, const Vec2& op2);

float dotProduct(const Vec2& op1, const Vec2& op2);

struct AABB
{
    Vec2 min;
    Vec2 max;
};

bool doesIntersect(const AABB& b1, const AABB& b2);
