#ifndef _GE_MAP_
#define _GE_MAP_

#include <irrlicht.h>
#include "utilities/tinyxml/tinyxml.h"
#include "propertyvalues.h"
#include "printer.h"
#include "core.h"
#include "window.h"
#include "entity.h"
#include "camera.h"


class Map{
   
   protected :
	   irr::core::string<irr::c8> name;
	   //vector<Entity *> entities;
	   irr::core::array<Entity *> entities;
	   Camera camera;
	   irr::core::map<irr::core::string<irr::c8>,Entity *> entitiesIndex;
	   

	   
	   virtual Entity * OnSelectEntity(irr::core::string<irr::c8> entityType,irr::core::string<irr::c8> tagName);

	   virtual void OnMapLoaded()
	   {
	   }

	   virtual void OnClearMap()
	   {
	   }

	   virtual void OnUpdate(float frameTime){
	   }

       
   public :
	   ~Map()
	   {
		   debugmsg("Destruyendo mapa ");
		   debugmsgln(name.c_str());
		   clearMap();
	   }

	   Map():camera
	   (
		     (irr::f32)RenderWindow::getInstance().getWindowSize().Width,
			 (irr::f32)RenderWindow::getInstance().getWindowSize().Height
	   )
	   {
	   }

       void loadMap(const char * path);

	   void render();
	   void clearMap();
       void update();

	   void addEntity(Entity * entity)
	   {
		   entitiesIndex[entity->getName()] = entity;
		   entities.push_back(entity);
	   }

	   Camera & getActiveCamera()
	   {
		   return camera;
	   }

	   Entity * findEntityByName(irr::core::string<irr::c8> name)
	   {
		   return entitiesIndex[name];
	   }
};

  
#endif