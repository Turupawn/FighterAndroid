#include <vector>
#include <jni.h>
#include <android/log.h>
#include <irrlicht.h>
#include <Box2D/Box2D.h>

#include "Fighter.h"
#include "Menu/Menu.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int importGLInit();
void importGLDeinit();
void nativeDrawIteration();
void nativeOnInitScene();

// global variables
int  gAppAlive   = 1;
stringc gSdCardPath = "/sdcard/";
/*
int  gWindowWidth  = 320;
int  gWindowHeight = 480;


IrrlichtDevice *device = NULL;
IVideoDriver* driver = NULL;


RenderWindow &window = RenderWindow::getInstance();
Map *mapa;
*/

//Fighter
Receiver* receiver_fighter;
Input*inputa;
Input*inputb;
Grafico*grafico;
Sonido*sonido;

Menu* menu;
Fighter*fighter;

bool fighter_activo;

/* For JNI: C++ compiler need this */
extern "C" {

/** Activity onCreate */
void Java_com_carloscastro_engine_Game_nativeOnCreate( JNIEnv*  env )
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "OnCreate");
}

/** Activity onPause */
void Java_com_carloscastro_engine_Game_nativeOnPause( JNIEnv*  env )
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "OnPause");
}

/** Activity onResume */
void Java_com_carloscastro_engine_Game_nativeOnResume( JNIEnv*  env )
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "OnResume");
}

/** Activity onDestroy */
void Java_com_carloscastro_engine_Game_nativeOnDestroy( JNIEnv*  env )
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "OnDestroy");
    importGLDeinit();
}

void Java_com_carloscastro_engine_Game_nativeInitGL( JNIEnv*  env )
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "InitGL");

   /* importGLInit();
    device = createDevice( video::EDT_OGLES1, dimension2d<u32>(gWindowWidth,gWindowHeight), 16, false, false, false, 0);
    driver = device->getVideoDriver();
    
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "createDevice r=%d w=%d h=%d", device, gWindowWidth, gWindowHeight);
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "getVideoDriver r=%d", driver);

    if (!device)
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "No device");
    if (!driver)
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "No driver");
        */
}

void Java_com_carloscastro_engine_Game_nativeResize( JNIEnv*  env, jobject  thiz, jint w, jint h )
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "OnResize");
    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "resize w=%d h=%d", w, h);
    /*gWindowWidth  = w;
    gWindowHeight = h;
    irr::core::dimension2d<unsigned int> size;
    size.Width = w;
    size.Height = h; 
    device->getVideoDriver()->OnResize(size);*/
}

void Java_com_carloscastro_engine_Game_nativeSendEvent( JNIEnv*  env, jobject defaultObj, jobject event)
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "SendEvent");

    jclass classEvent = env->GetObjectClass(event);
    jfieldID fieldAction = env->GetFieldID(classEvent, "mAction", "I");
    jfieldID fieldX = env->GetFieldID(classEvent, "mX", "F");
    jfieldID fieldY = env->GetFieldID(classEvent, "mY", "F");
    int action = env->GetIntField(event, fieldAction);
    // convert Android coord to OpenGL coords
    float x = env->GetFloatField(event, fieldX);
    float y = env->GetFloatField(event, fieldY);

///*
/**/
if(action==0)
{

  if(x>60 && y>215
       && x<100 && y<245)
    receiver_fighter->up=true;

  if(x>60 && y>280
       && x<100 && y<310)
    receiver_fighter->down=true;

  if(x>30 && y>245
       && x<65 && y<280)
    receiver_fighter->left=true;

  if(x>100 && y>245
       && x<130 && y<280)
    receiver_fighter->right=true;

  if(x>360 && y>240
       && x<405 && y<285)
    receiver_fighter->a=true;

  if(x>405 && y>240
       && x<450 && y<285)
    receiver_fighter->b=true;
}


if(action==1)
{
  receiver_fighter->up=false;
  receiver_fighter->down=false;
  receiver_fighter->left=false;
  receiver_fighter->right=false;

  receiver_fighter->a=false;
  receiver_fighter->b=false;
}
//menu->logicaCharSelect();
//menu->logicaAcciones();

/*
if(bool_down==true)
{
  menu->receiver->down=true;
}else
{
  menu->receiver->down=false;
}

if(bool_up==true)
{
  menu->receiver->up=true;
}else
{
  menu->receiver->up=false;
}

    /*jclass classEvent = env->GetObjectClass(event);
    jfieldID fieldAction = env->GetFieldID(classEvent, "mAction", "I");
    jfieldID fieldX = env->GetFieldID(classEvent, "mX", "F");
    jfieldID fieldY = env->GetFieldID(classEvent, "mY", "F");
    int action = env->GetIntField(event, fieldAction);
    // convert Android coord to OpenGL coords
    float x = env->GetFloatField(event, fieldX);
    float y = env->GetFloatField(event, fieldY);
    SEvent irrevent;
    irrevent.MouseInput.ButtonStates = 0xffffffff;
    irrevent.EventType = irr::EET_MOUSE_INPUT_EVENT;
    irrevent.MouseInput.Event = irr::EMIE_COUNT;
	irrevent.MouseInput.X = x;
	irrevent.MouseInput.Y = y;
    if (action==0) {
        irrevent.MouseInput.ButtonStates = 0;
	    irrevent.MouseInput.ButtonStates = irr::EMBSM_LEFT;
        irrevent.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN; 
		irrevent.MouseInput.ButtonStates ^= irr::EMBSM_LEFT;   
	    device->postEventFromUser(irrevent);
	    __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "left click received %d %f %f", action, x, y);
    } else if (action==1){
        irrevent.MouseInput.ButtonStates = 0;
        irrevent.MouseInput.ButtonStates = irr::EMBSM_LEFT;
        irrevent.MouseInput.Event = irr::EMIE_LMOUSE_LEFT_UP;
		irrevent.MouseInput.ButtonStates ^= irr::EMBSM_LEFT;  
        device->postEventFromUser(irrevent);
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "left click release %d %f %f", action, x, y);
    } else {
        __android_log_print(ANDROID_LOG_INFO, "Irrlicht", "not handled %d", action);   
    }    */
}

void Java_com_carloscastro_engine_Game_nativeGetStatus(JNIEnv*  env, jobject defaultObj, jobject status)
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "GetStatus");
    if (gAppAlive==0) {
        jclass classStatus = env->GetObjectClass(status);
        jfieldID fieldStatus = env->GetFieldID(classStatus, "mQuit", "Z");
        env->SetBooleanField(status, fieldStatus, true);
    }    
}


void Java_com_carloscastro_engine_Game_nativeEnvJ2C(JNIEnv*  env, jobject defaultObj, jstring jsdcardPath)
{
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "EnvJ2C");
    char ligne[1024+1];
    const char *msg = env->GetStringUTFChars(jsdcardPath,0);
    gSdCardPath = msg;
    //__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "not handled %s", gSdCardPath.c_str());
    env->ReleaseStringUTFChars(jsdcardPath,msg);
}

void Java_com_carloscastro_engine_Game_nativeDrawIteration( JNIEnv*  env, jobject defaultObj, jobject status )
{

        //jclass classStatus = env->GetObjectClass(status);
        //jfieldID fieldStatus = env->GetFieldID(classStatus, "mQuit", "Z");
        //bool env->SetBooleanField(status, fieldStatus, true);
/*
jfieldID fid = env->GetFieldID(env->GetObjectClass(status), "down", "Z");
jboolean bool_down = env->GetBooleanField(status, fid);

jfieldID fid_up = env->GetFieldID(env->GetObjectClass(status), "up", "Z");
jboolean bool_up = env->GetBooleanField(status, fid_up);
*/
if(menu==NULL)
  menu=new Menu(grafico,receiver_fighter,sonido,(char*)"/sdcard/Fighter/menu/main_menu.xml",NULL);
gAppAlive=1;


//    __android_log_print(ANDROID_LOG_INFO, "UNO", "fps=%d", 22);
//	    menu->logicaMenu();
//    __android_log_print(ANDROID_LOG_INFO, "DOS", "fps=%d", 22);

///*
	if(!fighter_activo)
	{
	    menu->logicaMenu();
	    if(menu->bool_break)
	    {
		menu->bool_break=false;
		if(menu->padre==NULL)
		{
		    gAppAlive=0;
		    //break;!!!!
		}
		else
		{
		    menu=menu->padre;
		    menu->tecla_arriba=false;
		}
	    }
	    if(menu->bool_menu_hijo)
	    {
		menu->bool_menu_hijo=false;
		menu=menu->hijo;
		menu->tecla_arriba=false;
	    }
	    if(menu->bool_fighter)
	    {
		fighter=menu->fighter;
		fighter_activo=true;
	    }
	}
	else
	{
	    fighter->logicaFighter();
	    if(fighter->bool_beak)
	    {
		menu=fighter->padre;
		fighter_activo=false;
	    }
	}

/*
    gAppAlive = window.isOpened();

    window.clear();
    mapa->update();
	mapa->render();
	window.display();
/**/
    if (gAppAlive==0) {
            jclass classStatus = env->GetObjectClass(status);
            jfieldID fieldStatus = env->GetFieldID(classStatus, "mQuit", "Z");
            env->SetBooleanField(status, fieldStatus, true);
    }
    //__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "fps=%d", 22);
    //__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "fps=%d", window.getFPS());
}

void Java_com_carloscastro_engine_Game_nativeInitScene( JNIEnv*  env )
{
    //Fighter
    receiver_fighter=new Receiver();
    inputa=new Input();
    inputb=new Input();
    inputa->cargarDesdeXML(1,receiver_fighter);
    inputb->cargarDesdeXML(2,receiver_fighter);
    grafico=new Grafico(receiver_fighter);
    sonido = new Sonido();
    //menu=new Menu(grafico,receiver_fighter,sonido,(char*)"/sdcard/Fighter/menu/main_menu.xml",NULL);
    menu=NULL;
    fighter=NULL;
    sonido->reproducirSonido(stringw("Menu.music"));

    fighter_activo=false;

    gAppAlive=1;
/*
	//mapa->loadMap("/sdcard/Irrlicht/resources/test.xml");
	for(int i=0;i<30;i++)
	{
	  TextureItem * item = new TextureItem();
	  item->setTextureFileName("/sdcard/Fighter/chars/Nelson/portrait.png");
	  irr::core::vector2df newpos((i%7)*128.0f,(i/7)*128);
	  item->setPosition(newpos);
	  mapa->addEntity(item);
	}
*/
	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "OnInitScene");
}

}
