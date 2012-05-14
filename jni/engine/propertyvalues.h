#ifndef _GE_PROPERTYVALUES_
#define _GE_PROPERTYVALUES_


#include <irrlicht.h>
using namespace std;

class PropertyValueType{
public: 
	static int FreeText,Boolean,Vector2d,Color,ItemLink;
};


class PropertyValue{
  public:
	  virtual int getPropertyValueType()=0;
};

class FreeTextValue:public PropertyValue{
  private:
	  irr::core::string<irr::c8> value;
  public:
	  virtual int getPropertyValueType(){
		  return PropertyValueType::FreeText;
	  }
	  FreeTextValue(irr::core::string<irr::c8> value){
	    setValue(value);	  
	  }
	  irr::core::string<irr::c8> getValue() const{
	    return value;
	  }
	  void setValue(irr::core::string<irr::c8> value){
	     this->value = value;
	  }
};

class BooleanValue: public PropertyValue{
  private:
      bool value;
  public:
	  virtual int getPropertyValueType(){
		  return PropertyValueType::Boolean;
	  }
	  BooleanValue(bool value){
	    setValue(value);	  
	  }
	  bool getValue(){
	    return value;
	  }
	  void setValue(bool value){
	    this->value=value;
	  }
};

class Vector2dValue:public PropertyValue{
  private:
	  irr::core::vector2d<irr::f32> value;
  public:
	  virtual int getPropertyValueType(){
		  return PropertyValueType::Vector2d;
	  }
	  Vector2dValue(irr::core::vector2d<irr::f32> & value){
	    setValue(value);	  
	  }
	  irr::core::vector2d<irr::f32> & getValue(){
	    return value;
	  }
	  void setValue(irr::core::vector2d<irr::f32> & value){
	    this->value=value;
	  }
};

class ColorValue:public PropertyValue{
  private:
	  irr::video::SColor value;
  public:
	  virtual int getPropertyValueType(){
		  return PropertyValueType::Color;
	  }
	  ColorValue(irr::video::SColor & value){
	    setValue(value);	  
	  }
	  irr::video::SColor & getValue(){
	    return value;
	  }
	  void setValue(irr::video::SColor & value){
	    this->value=value;
	  }
};

class ItemLinkValue:public PropertyValue{
  private:
      irr::core::string<irr::c8> value;
  public:
	  virtual int getPropertyValueType(){
		  return PropertyValueType::FreeText;
	  }
	  ItemLinkValue(irr::core::string<irr::c8> value){
	    setValue(value);	  
	  }
	  irr::core::string<irr::c8> getValue(){
	    return value;
	  }
	  void setValue(irr::core::string<irr::c8> value){
	    this->value=value;
	  }
};



#endif