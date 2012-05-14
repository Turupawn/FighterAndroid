#ifndef _GE_CAMERA_
#define _GE_CAMERA_

#include <irrlicht.h>
#include "printer.h"
#include "window.h"

//TODO: revisar bug al acumular zoom

class Camera {

public:
	irr::core::matrix4 & getTransformation();

	Camera(irr::f32 screenWidth,irr::f32 screenHeight)
	{
		this->screenHeight = screenHeight;
		this->screenWidth = screenWidth;
		matrix.setTranslation(irr::core::vector3df(0,0,0));
		matrix.setScale(irr::core::vector3df(1.0f,1.0f,0));
		zoom=1.0f;
	}

	void setPosition(float X,float Y)
	{
		position.X = X;
		position.Y = Y;
		matrix.setTranslation(irr::core::vector3df(((position.X/screenWidth)-0.5f)*2.0f,((position.Y/screenHeight)-0.5f)*-2.0f,0));
	}

	void setPosition(irr::core::vector2df & position)
	{
		
		setPosition(position.X,position.Y);
		
	}

	irr::core::vector2df & getPosition()
	{
		return  position;
	}

	void setZoom(irr::f32 zoom)
	{
		this->zoom=zoom;
		matrix.setScale(irr::core::vector3df(zoom,zoom,0));
		//TODO: no se como reposicionar la camara :( para que el zoom siempre quede en el centro
		//setPosition(position+position*irr::core::vector2df(zoom/2.0f,zoom/2.0f)/2.0f);
	}

	irr::f32 getZoom()
	{
		return zoom;
	}

private:

	irr::f32 zoom;
	irr::core::vector2df position;
	irr::core::matrix4 matrix;
	irr::f32 screenWidth,screenHeight;
};




#endif