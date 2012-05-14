#ifndef _GE_ENTITY_
#define _GE_ENTITY_

#include<irrlicht.h>

using namespace std;
#include "tinyxml.h"
#include "propertyvalues.h"
#include "core.h"
#include "printer.h"
#include "sprite.h"
#include "window.h"

class Entity{
 protected : 
	 irr::core::vector2d<irr::f32> position;
	 irr::core::string<irr::c8> name;
	 bool visible;
     irr::core::string<irr::c8> editorType;
	 irr::core::string<irr::c8> layerName;
	 irr::core::vector2d<irr::f32> scrollSpeed;
	 static int count;
    

  public:
	  
	  ~Entity();
	  Entity();

	  Entity(Entity * entity);

	  virtual void loadFromXml(TiXmlNode *item,irr::core::string<irr::c8> layerName,irr::core::vector2d<irr::f32> & scrollSpeed);
      virtual void render();

	  void setPosition(irr::core::vector2d<irr::f32> & position){
		  this->position = position;
	  }
	  void setName(irr::core::string<irr::c8> name){
	    this->name = name;
	  }
	  void setVisible(bool visible){
		  this->visible = visible;
	  }
	  void setLayerName(irr::core::string<irr::c8> layerName){
		  this->layerName = layerName;
	  }

	  void setScrollSpeed(irr::core::vector2d<irr::f32> & scrollSpeed){
	     this->scrollSpeed = scrollSpeed;
	  }
	  irr::core::vector2d<irr::f32> & getPosition(){
	     return this->position;	  
	  }
	  irr::core::string<irr::c8> getName(){
		  return this->name;
	  }
	  bool isVisible(){
		  return this->visible;
	  }
	  irr::core::string<irr::c8> getLayerName(){
	     return this->layerName;
	  }

	  irr::core::vector2d<irr::f32> &  getScrollSpeed(){
	     return this->scrollSpeed;
	  }
      
	  //virtual void ProcessEvent(sf::Event &e,float frameTime){
	  //}
	  virtual void update(float frameTime){
	  }

};



class TextureItem: public Entity{
   protected:
      float rotation;
      float scale;
	  irr::video::SColor tintColor;
	  bool flipHorizontally;
	  bool flipVertically;
	  irr::core::string<irr::c8> textureFileName;
	  irr::core::vector2d<irr::f32> origin;
     
	  Sprite textureSprite;
	  //sf::Image * TextureImage;

   public:
	   ~TextureItem(){
	     //TODO eliminar el entity     
	   }
	   TextureItem();

	  virtual  void loadFromXml(TiXmlNode *item,irr::core::string<irr::c8> layerName,irr::core::vector2d<irr::f32> & scrollSpeed);
	  virtual void render();

	  void setRotation(float rotation){
		  this->rotation = rotation;
	  }
	  void setScale(float Scale){
	      this->scale = Scale;
	  }
	  void setTintColor(irr::video::SColor & tintColor){
	      this->tintColor = tintColor;
	  }
	  void setFlipHorizontally(bool flipHorizontally){
	      this->flipHorizontally= flipHorizontally;
	  }
	  void setFlipVertically(bool flipVertically){
	      this->flipVertically = flipVertically;
	  }
	  void setTextureFileName(irr::core::string<irr::c8> textureFileName){
		  this->textureFileName = textureFileName;
	  }
	  void setOrigin(irr::core::vector2d<irr::f32> & origin){
	      this->origin = origin;
	  }

      
	  float getRotation(){
		 return this->rotation; 
	  }
	  float getScale(){
	     return this->scale;
	  }
	  irr::video::SColor & getTintColor(){
	     return this->tintColor;
	  }
	  bool isFlipHorizontally(){
	     return this->flipHorizontally;
	  }
	  bool isFlipVertically(){
	     return this->flipVertically;
	  }
	  irr::core::string<irr::c8> getTextureFileName(){
	     return this->textureFileName;
	  }
	  irr::core::vector2d<irr::f32> & getOrigin(){
	     return this->origin;
	  }

};



class RectangleItem: public Entity{
 protected:
    int width;
	int height;
	irr::video::SColor fillColor;
   
 public:
	 ~RectangleItem(){
	     //TODO eliminar el entity
	 }

	 RectangleItem();
	 virtual  void loadFromXml(TiXmlNode *item,irr::core::string<irr::c8> layerName,irr::core::vector2d<irr::f32> & scrollSpeed);
	 virtual void render();
	 void setWidth(int width){
	   this->width = width;
	 }
	 void setHeight(int height){
	   this->height = height;
	 }
	 void setFillColor(irr::video::SColor & fillColor){
	   this->fillColor = fillColor;
	 }
	 int getWidth(){
	   return this->width;
	 }
	 int getHeight(){
	   return this->height;
	 }
	 irr::video::SColor & getFillColor(){
	   return this->fillColor;
	 }
     
};

#endif
