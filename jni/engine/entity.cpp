#include "entity.h"


 Entity::~Entity(){
		  debugmsg("Eliminando entidad ");
		  debugmsgln(name.c_str());
	     //TODO eliminar el entity
	  }
	  Entity::Entity(){
		  editorType="Custom";
		  this->position = irr::core::vector2d<irr::f32>(0,0); 
		  name= "Id"+count;
		  count++;
		  visible=true;
		  scrollSpeed = irr::core::vector2d<irr::f32>(1.0f,1.0f);
		  layerName="@default";
	  }

	  Entity::Entity(Entity * entity){
          editorType="Custom";
		  position = entity->getPosition();
		  name = entity->getName();
		  visible= entity->isVisible();
		  scrollSpeed = entity->getScrollSpeed();
		  layerName = entity->getLayerName();
	  }

	  void Entity::loadFromXml(TiXmlNode *item,irr::core::string<irr::c8> layerName,irr::core::vector2d<irr::f32> & scrollSpeed){
		  editorType = item->ToElement()->Attribute("xsi:type");
		  position.X = Convert::toFloat(item->FirstChild("Position")->FirstChild("X")->FirstChild()->Value());
		  position.Y = Convert::toFloat(item->FirstChild("Position")->FirstChild("Y")->FirstChild()->Value());
		  visible = Convert::toBool(item->ToElement()->Attribute("Visible"));
          name = item->ToElement()->Attribute("Name");
		  
		  /*for(TiXmlNode * customProperty= item->FirstChild("CustomProperties")->FirstChild("Property");
			  customProperty!=0;customProperty=customProperty->NextSibling("Property")){
				  
		      string type = customProperty->ToElement()->Attribute("Type");
			  string name = customProperty->ToElement()->Attribute("Name");
			  if(type=="string"){
				  customProperties[name]=
					  new FreeTextValue(customProperty->FirstChild("string")->FirstChild()->Value());
			  }
			  else if(type=="bool"){
				  customProperties[name]=
					  new BooleanValue(Convert::toBool(customProperty->FirstChild("boolean")->FirstChild()->Value()));
			  }
			  else if(type=="Vector2"){
				  float pX = Convert::toFloat(customProperty->FirstChild("Vector2")->FirstChild("X")->FirstChild()->Value());
				  float pY = Convert::toFloat(customProperty->FirstChild("Vector2")->FirstChild("Y")->FirstChild()->Value());
			      customProperties[name]=
					  new Vector2dValue(irr::core::vector2d<irr::f32>(pX,pY));
			  }
			  else if(type=="Color"){
			      int r = Convert::toInt(customProperty->FirstChild("Color")->FirstChild("R")->FirstChild()->Value());
				  int g = Convert::toInt(customProperty->FirstChild("Color")->FirstChild("G")->FirstChild()->Value());
				  int b = Convert::toInt(customProperty->FirstChild("Color")->FirstChild("B")->FirstChild()->Value());
				  int a = Convert::toInt(customProperty->FirstChild("Color")->FirstChild("A")->FirstChild()->Value());
			      customProperties[name]=
					  new ColorValue(irr::video::SColor(r,g,b,a));
			  }
			  else if(type=="Item"){
			    customProperties[name]=
					new ItemLinkValue(customProperty->FirstChild()->Value());
			  }
		  }*/
		  
		  
	  }
      void Entity::render(){
	      
	  }

	  

	  int Entity::count=0;



	   TextureItem::TextureItem(){
	      rotation=0;
		  scale = 1;
		  tintColor = irr::video::SColor(255,255,255,255);
		  flipHorizontally=flipVertically=false;
		  textureFileName="";
		  origin = irr::core::vector2d<irr::f32>(0,0);
	   }

	   void TextureItem::loadFromXml(TiXmlNode *item,irr::core::string<irr::c8> layerName,irr::core::vector2d<irr::f32> & scrollSpeed){
		  Entity::loadFromXml(item,layerName,scrollSpeed);
		  origin.X = Convert::toFloat(item->FirstChild("Origin")->FirstChild("X")->FirstChild()->Value());
		  origin.Y = Convert::toFloat(item->FirstChild("Origin")->FirstChild("Y")->FirstChild()->Value());
	      rotation= Convert::toFloat(item->FirstChild("Rotation")->FirstChild()->Value());
		  scale= Convert::toFloat(item->FirstChild("Scale")->FirstChild()->Value());
		  flipHorizontally = Convert::toBool(item->FirstChild("FlipHorizontally")->FirstChild()->Value());
		  flipVertically = Convert::toBool(item->FirstChild("FlipVertically")->FirstChild()->Value());
		  textureFileName = Prefix::Value+item->FirstChild("texture_filename")->FirstChild()->Value();
		  tintColor.setAlpha(Convert::toInt(item->FirstChild("TintColor")->FirstChild("A")->FirstChild()->Value()));
		  tintColor.setBlue(Convert::toInt(item->FirstChild("TintColor")->FirstChild("B")->FirstChild()->Value()));
		  tintColor.setGreen (Convert::toInt(item->FirstChild("TintColor")->FirstChild("G")->FirstChild()->Value()));
		  tintColor.setRed (Convert::toInt(item->FirstChild("TintColor")->FirstChild("R")->FirstChild()->Value()));
		  position-=origin;
	  }
	  void TextureItem::render(){
		  if(visible){ 

			  textureSprite.loadTexture(textureFileName.c_str());
			  textureSprite.setPosition(position);
			  textureSprite.setFlipHorizontally(flipHorizontally);
			  textureSprite.setFlipVertically(flipVertically);
			  textureSprite.setColor(tintColor);
			  textureSprite.setRotation(rotation);

			  RenderWindow::getInstance().draw(textureSprite);
		  }
	  }
	 

	 RectangleItem::RectangleItem(){
		 width=height=0;
         fillColor= irr::video::SColor(255,255,255,255);
	 }
	 void RectangleItem::loadFromXml(TiXmlNode *item,irr::core::string<irr::c8> layerName,irr::core::vector2d<irr::f32> & scrollSpeed){
		  Entity::loadFromXml(item,layerName,scrollSpeed);
		  fillColor.setAlpha(Convert::toInt(item->FirstChild("FillColor")->FirstChild("A")->FirstChild()->Value()));
		  fillColor.setBlue(Convert::toInt(item->FirstChild("FillColor")->FirstChild("B")->FirstChild()->Value()));
		  fillColor.setGreen(Convert::toInt(item->FirstChild("FillColor")->FirstChild("G")->FirstChild()->Value()));
		  fillColor.setRed(Convert::toInt(item->FirstChild("FillColor")->FirstChild("R")->FirstChild()->Value()));
		  width= Convert::toInt(item->FirstChild("Width")->FirstChild()->Value());
		  height= Convert::toInt(item->FirstChild("Height")->FirstChild()->Value());
	 }

	 void RectangleItem::render(){
		// Engine::Window.Draw(sf::Shape::Rectangle(Position,Position+sf::Vector2f((float)Width,(float)Height),FillColor));
		 //if(Visible)
			// RenderWindow::getInstance().Draw(sf::Shape::Rectangle(Position,Position+sf::Vector2f((float)Width,(float)Height),FillColor));
	 }