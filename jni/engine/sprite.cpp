#include "window.h"
#include "sprite.h"

void Sprite::loadTexture(const char * texturePath)
{
	texture = RenderWindow::getInstance().loadTexture(texturePath);
	if(texture)
	{
        size = texture->getSize();
		sourceRect = irr::core::rect<irr::f32>(0,0,size.Width,size.Height);
		rotationPoint = irr::core::vector2df(size.Width/2,size.Height/2);
	}
}

Sprite::Sprite()
{
	texture = 0;
	size = irr::core::dimension2d<irr::f32>(0,0);
	sourceRect = irr::core::rect<irr::f32>(0,0,0,0);
	position = irr::core::position2d<irr::f32>(0,0);
	rotationPoint = irr::core::position2d<irr::f32>(0,0);
	rotation = 0.0f;
	scale = irr::core::vector2df(1,1);
	useAlphaChannel = true;
	flipHorizontally = false;
	flipVertically = false;
	color = irr::video::SColor(255,255,255,255);
}