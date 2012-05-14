
#include "map.h"

void Map::loadMap(const char * path){
	clearMap();
	TiXmlDocument * doc = new TiXmlDocument(path);
	bool isOK = doc->LoadFile();
	if(isOK){
		debugmsgln("Se cargo el archivo xml")
		TiXmlNode * lvl 	=  doc->FirstChild("Level");
		debugmsg("Cargando mapa ");
		debugmsgln(lvl->ToElement()->Attribute("Name"));
		name = lvl->ToElement()->Attribute("Name");
        //TODO: ver como reciclar este codigo
		//------------------------------------------------------------------------

		/*for(TiXmlNode * customProperty= lvl->FirstChild("CustomProperties")->FirstChild("Property");
			customProperty!=0;customProperty=customProperty->NextSibling("Property")){
					  
			irr::core::string<irr::c8> type = customProperty->ToElement()->Attribute("Type");
			irr::core::string<irr::c8> name = customProperty->ToElement()->Attribute("Name");
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
					new Vector2dValue(irr::core::vector2d<irr::f32> (pX,pY));
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
        //------------------------------------------------------------------------
		TiXmlNode * layers = lvl->FirstChild("Layers");
		for(TiXmlNode *layer = layers->FirstChild("Layer");layer!=0;layer=layer->NextSibling("Layer")){
			TiXmlNode *items = layer->FirstChild("Items");
			irr::core::string<irr::c8> layerName=layer->ToElement()->Attribute("Name");
			bool visible=Convert::toBool(layer->ToElement()->Attribute("Visible"));
			irr::core::vector2d<irr::f32> scrollSpeed;
			scrollSpeed.X = Convert::toFloat(layer->FirstChild("ScrollSpeed")->FirstChild("X")->Value());
            scrollSpeed.Y = Convert::toFloat(layer->FirstChild("ScrollSpeed")->FirstChild("Y")->Value());
			for(TiXmlNode *item = items->FirstChild("Item");item!=0;item=item->NextSibling("Item")){
				debugmsg("Cargando item ");
				debugmsgln(item->ToElement()->Attribute("xsi:type"));
				Entity * entity=0;
				irr::core::string<irr::c8> type = item->ToElement()->Attribute("xsi:type");
				irr::core::string<irr::c8> entityType="";
				//Averiguar que tipo es
				for(TiXmlNode * customProperty= item->FirstChild("CustomProperties")->FirstChild("Property");
			       customProperty!=0;customProperty=customProperty->NextSibling("Property")){
				      
					   irr::core::string<irr::c8> ptype = customProperty->ToElement()->Attribute("Type");
			           irr::core::string<irr::c8> pname = customProperty->ToElement()->Attribute("Name");
					   if(pname=="EntityType")
					   {
						 if(ptype=="string")
						 {
							 entityType = customProperty->FirstChild("string")->FirstChild()->Value();
							 break;
						 }
					   }

				}
				entity = OnSelectEntity(entityType,type);

				entity->loadFromXml(item,layerName,scrollSpeed);
				addEntity(entity);
				
			}
		}

			  
		float pX = Convert::toFloat(lvl->FirstChild("EditorRelated")->FirstChild("CameraPosition")->FirstChild("X")->FirstChild()->Value());
		float pY = Convert::toFloat(lvl->FirstChild("EditorRelated")->FirstChild("CameraPosition")->FirstChild("Y")->FirstChild()->Value());
		camera.setPosition(
			               (irr::f32)RenderWindow::getInstance().getWindowSize().Width,
						   (irr::f32)RenderWindow::getInstance().getWindowSize().Height
						  );
		doc->Clear();
	}
	delete doc;
	debugmsgln("Se termino de cargar el archivo xml");
	OnMapLoaded();
}

void Map::render(){

	RenderWindow::getInstance().applyCamera(camera);

	unsigned int entitiesSize=entities.size();
	for(unsigned int i=0;i<entitiesSize;i++){
		entities[i]->render();
	}
		   
}

 Entity * Map::OnSelectEntity(irr::core::string<irr::c8> entityType,irr::core::string<irr::c8> tagName)
{
	//cout<<entityType.c_str()<<endl;
	if(tagName=="TextureItem")
		return new TextureItem();
	else
        if(tagName=="RectangleItem")
			return new RectangleItem();
		else
			return new Entity();
}

void Map::clearMap(){
	OnClearMap();
	name="";
    for(unsigned int i=0;i<entities.size();i++){
		if(entities[i])
		delete entities[i];
		entities[i]=0;
	}
	entities.clear();
	
}


void Map::update(){
	
	float frameTime = RenderWindow::getInstance().getFrameTime();	   
	for(unsigned int i=0;i<entities.size();i++){
			entities[i]->update(frameTime);
	}
	OnUpdate(frameTime);

}
