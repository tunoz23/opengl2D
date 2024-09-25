#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

class Drawable
{
public:
	virtual void draw() = 0;

	virtual ~Drawable() = default;
};