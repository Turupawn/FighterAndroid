#ifndef _GE_SPRITE_
#define _GE_SPRITE_

#include <irrlicht.h>

#include "window.h"

class Sprite
{

 public:
     Sprite();
	 void loadTexture(const char * texturePath);

	 void setTexture(irr::video::ITexture * texture)
	 {
		 this->texture = texture;
	 }

	 irr::video::ITexture * getTexture()
	 {
		 return texture;
	 }

	 void setSourceRect(irr::core::rect<irr::f32> & sourceRect)
	 {
		 this->sourceRect = sourceRect;
	 }

	 irr::core::rect<irr::f32> & getSourceRect()
	 {
		 return sourceRect;
	 }

	 void setPosition(irr::core::position2d<irr::f32> & position)
	 {
		 this->position = position;
	 }

	 irr::core::position2d<irr::f32> & getPosition()
	 {
		 return position;
	 }

     void setRotationPoint(irr::core::position2d<irr::f32> & rotationPoint)
	 {
		 this->rotationPoint = rotationPoint;
	 }

	 irr::core::position2d<irr::f32> & getRotationPoint()
	 {
		 return rotationPoint;
	 }

	 void setRotation(irr::f32 rotation)
	 {
		 this->rotation = rotation;
	 }

	 irr::f32 getRotation()
	 {
		 return rotation;
	 }

	 void setScale(irr::core::vector2df & scale)
	 {
		 this->scale = scale;
	 }

	 irr::core::vector2df & getScale()
	 {
		 return scale;
	 }

	 void setUseAlphaChannel(bool alphaChannel)
	 {
		 this->useAlphaChannel= useAlphaChannel;
	 }

	 bool isUseAlphaChannel()
	 {
		 return useAlphaChannel;
	 }

	 void setColor(irr::video::SColor & color)
	 {
		 this->color = color;
	 }

	 irr::video::SColor & getColor()
	 {
		 return color;
	 }

	 void setFlipHorizontally(bool flipHorizontally)
	 {
		 this->flipHorizontally= flipHorizontally;
	 }

	 bool isFlipHorizontally()
	 {
		 return flipHorizontally;
	 }

	 void setFlipVertically(bool flipVertically)
	 {
		 this->flipVertically= flipVertically;
	 }

	 bool isFlipVertically()
	 {
		 return flipVertically;
	 }

	 void setSize(irr::core::dimension2d<irr::f32> & size)
	 {
		this->size = size;
	 }

	 irr::core::dimension2d<irr::f32> & getSize()
	 {
		 return size;
	 }


 private:

	 irr::video::ITexture *texture;
	 irr::core::rect<irr::f32> sourceRect; 
	 irr::core::position2d<irr::f32> position; 
	 irr::core::position2d<irr::f32> rotationPoint; 
	 irr::core::dimension2d<irr::f32> size;
	 irr::f32 rotation; 
	 irr::core::vector2df scale; 
	 bool useAlphaChannel; 
	 bool flipHorizontally;
	 bool flipVertically;
	 irr::video::SColor color;

};


#endif