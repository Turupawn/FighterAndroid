#ifndef _GE_CORE_
#define _GE_CORE_


#include <irrlicht.h>
using namespace std;



class Convert{
  public:
	 static int toInt(const char *str){
	     return atoi(str);
	 }
	 static bool toBool(const char *str){
	   return strcmp(str,"true")==0;
     }
	 static double toDouble(const char *str){
		 return atof(str);
	 }
	 static float toFloat(const char *str){
		 //TODO: possibly loss converstion
		 return (float)Convert::toDouble(str);
	 }
	 static irr::core::string<irr::c8> toString(float f){
	     char buffer[100];
		 sprintf(buffer,"%f",f);
		 return buffer;
	 }

};

class Prefix{
 public:
	static irr::core::string<irr::c8> Value;
};







#endif
