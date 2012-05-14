#include "window.h"

    RenderWindow & RenderWindow::getInstance()
	{
		if(instance == 0){
           
		   instance = new RenderWindow();
		}
		return *instance;
	}

	void RenderWindow::close()
	{
		win->closeDevice();
	}

	void RenderWindow::startWindow()
	{
		win = createDevice(irr::video::EDT_OGLES1,irr::core::dimension2d<irr::u32>(800,480),16,false,false,false,&eventReceiver);
		driver = win->getVideoDriver();
	
	}

	irr::core::dimension2du RenderWindow::getWindowSize()
	{
		return driver->getScreenSize();
	}

	void RenderWindow::draw(Sprite & sprite){
		this->draw2DImage(
			              sprite.getTexture(),
						  sprite.getSize(),
			              sprite.getSourceRect(),
						  sprite.getPosition(),
						  sprite.getPosition()+sprite.getRotationPoint(),
			              sprite.getRotation(),
						  sprite.getScale(),
						  sprite.isUseAlphaChannel(),
						  sprite.getColor(),
						  sprite.isFlipHorizontally(),
						  sprite.isFlipVertically()
						);
	}
    
	
	

	

	bool RenderWindow::isOpened()
	{
		return win->run();
	}

	bool RenderWindow::isActive()
	{
		return win->isWindowActive();
	}

	void RenderWindow::clear()
	{
		const irr::u32 now = win->getTimer()->getTime();
		frameTime = (irr::f32)(now - then) / 1000.f; 
		then = now;

		driver->beginScene(true,true ,irr::video::SColor(0,0,0,0));
		//driver->setTransform(irr::video::ETS_VIEW,activeCamera.getTransformation());
	}
	void RenderWindow::display()
	{
		driver->endScene();
	}

	void RenderWindow::applyCamera(Camera & camera)
	{
		driver->setTransform(irr::video::ETS_VIEW,camera.getTransformation());
	}

	irr::f32 RenderWindow::getFrameTime()
	{
		return frameTime;
	}

	irr::u32 RenderWindow::getFPS()
	{
		return driver->getFPS();
	}

	bool RenderWindow::isKeyDown(int key)
	{
		return eventReceiver.IsKeyDown(key);              
	}

	irr::video::ITexture * RenderWindow::loadTexture(const char * texturePath)
	{
		return driver->getTexture(texturePath);
	}

	void RenderWindow::clearTextures()
	{
		driver->removeAllTextures();
	}


	//TODO: optimizar esta funcion, es clave porque es la que dibuja los sprites
	void RenderWindow::draw2DImage
	(
	             irr::video::ITexture* texture, 
				 irr::core::dimension2d<irr::f32> size,
				 irr::core::rect<irr::f32> sourceRect, 
				 irr::core::position2d<irr::f32> position, 
				 irr::core::position2d<irr::f32> rotationPoint, 
				 irr::f32 rotation , irr::core::vector2df scale, 
				 bool useAlphaChannel, 
				 irr::video::SColor color ,
				 bool flipHorizontally,
				 bool flipVertically 	)
	{ 
    
   if(!texture)
	   return;

   irr::video::SMaterial material; 
   
   irr::core::vector2df corner[4]; 

   corner[0] = irr::core::vector2df(position.X,position.Y); 
   corner[1] = irr::core::vector2df(position.X+size.Width*scale.X,position.Y); 
   corner[2] = irr::core::vector2df(position.X,position.Y+size.Height*scale.Y); 
   corner[3] = irr::core::vector2df(position.X+size.Width*scale.X,position.Y+size.Height*scale.Y); 


   if (rotation != 0.0f) 
      for (int x = 0; x < 4; x++) 
         corner[x].rotateBy(rotation,irr::core::vector2df(rotationPoint.X, rotationPoint.Y)); 


   //TODO: ver como mejorar esto
   irr::core::vector2df uvCorner[4]; 
   
   if(!flipVertically && !flipHorizontally)
   {
	   uvCorner[0] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[1] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[2] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y); 
	   uvCorner[3] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y); 
   }
   else if(!flipVertically && flipHorizontally)
   {
	   uvCorner[1] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[0] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[3] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y); 
	   uvCorner[2] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y); 
   }
   else if(flipVertically && !flipHorizontally)
   {
	   uvCorner[2] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[3] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[0] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y); 
	   uvCorner[1] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y); 
   }
   else
   {
	   uvCorner[3] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[2] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y); 
	   uvCorner[1] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y); 
	   uvCorner[0] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y);
   }
 

   for (int x = 0; x < 4; x++) { 
      float uvX = uvCorner[x].X/(float)texture->getSize().Width; 
      float uvY = uvCorner[x].Y/(float)texture->getSize().Height; 
      uvCorner[x] = irr::core::vector2df(uvX,uvY); 
   } 


   irr::video::S3DVertex vertices[4]; 
   irr::u16 indices[6] = { 0, 1, 2, 3 ,2 ,1 }; 

  
   float screenWidth = (float)driver->getScreenSize().Width; 
   float screenHeight = (float)driver->getScreenSize().Height; 
   for (int x = 0; x < 4; x++) { 
      float screenPosX = ((corner[x].X/screenWidth)-0.5f)*2.0f; 
      float screenPosY = ((corner[x].Y/screenHeight)-0.5f)*-2.0f; 
      vertices[x].Pos = irr::core::vector3df(screenPosX,screenPosY,1); 
      vertices[x].TCoords = uvCorner[x]; 
      vertices[x].Color = color; 
   } 
   material.Lighting = false; 
   material.ZWriteEnable = false; 
   material.TextureLayer[0].Texture = texture; 
  
   if (useAlphaChannel) 
      material.MaterialType = irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL; 
   else 
      material.MaterialType = irr::video::EMT_SOLID; 


   driver->setMaterial(material); 
   driver->drawIndexedTriangleList(&vertices[0],4,&indices[0],2); 
}


RenderWindow * RenderWindow::instance = 0;
