#ifndef _GE_WiNDOW_
#define _GE_WiNDOW_

#include <irrlicht.h>
#include "event.h"

class Sprite;
#include "sprite.h"

class Camera;
#include "camera.h"


class RenderWindow{
private:
	irr::IrrlichtDevice  *win;
	irr::video::IVideoDriver * driver;
    static RenderWindow * instance;
	EventReceiver eventReceiver;
	irr::u32 then;
	irr::f32 frameTime;
	

	RenderWindow()
	{
		then= 0;
	}

public:
	static RenderWindow & getInstance();
	void close();
	void startWindow();
	void draw(Sprite & sprite);
	void applyCamera(Camera &camera);
	bool isOpened();
	bool isActive();
	void clear();
	void display();
	irr::f32 getFrameTime();
	irr::u32 getFPS();
	bool isKeyDown(int key);
	irr::video::ITexture * loadTexture(const char * texturePath);
	void clearTextures();
	irr::core::dimension2du getWindowSize();

private:

	void draw2DImage
	(
	           
	             irr::video::ITexture* texture, 
				 irr::core::dimension2d<irr::f32> size,
				 irr::core::rect<irr::f32> sourceRect, 
				 irr::core::position2d<irr::f32> position, 
				 irr::core::position2d<irr::f32> rotationPoint = irr::core::position2d<irr::f32>(0,0), 
				 irr::f32 rotation = 0.0f, irr::core::vector2df scale = irr::core::vector2df(1,1), 
				 bool useAlphaChannel = true, 
				 irr::video::SColor color = irr::video::SColor(255,255,255,255),
				 bool flipHorizontally = false,
				 bool flipVertically = false
	);
	


};



#endif