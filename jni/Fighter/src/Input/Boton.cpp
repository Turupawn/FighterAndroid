#include "Input/Boton.h"

Boton::Boton(Receiver* receiver,irr::EKEY_CODE teclado,stringw mapeo)
{
    this->teclado=teclado;
    this->mapeo=mapeo;
    usando_joystick=false;
    this->receiver=receiver;
    //this->joystick=999;
}

Boton::Boton(Receiver* receiver,int joystick,int num_joystick,stringw mapeo)
{
    this->num_joystick=num_joystick;
    this->joystick=joystick;
    this->mapeo=mapeo;
    usando_joystick=true;
    this->receiver=receiver;
}

bool Boton::estaPresionado()
{
    if(usando_joystick)
    {
        if(receiver->IsJoyDown(joystick,num_joystick))
            return true;
    }else
    {
        if (receiver->IsKeyDownn(teclado))
            return true;
    }
    return false;
}

stringw Boton::getMapeo()
{
    return mapeo;
}

stringw Boton::getInput()
{
    if(usando_joystick)
    {
        if(joystick>=0)
            return stringw(joystick);
        if(joystick==-8)
            return stringw("up");
        if(joystick==-2)
            return stringw("down");
        if(joystick==-4)
            return stringw("left");
        if(joystick==-6)
            return stringw("right");
        return stringw("d");
    }else
    {
        return stringw(keyToString());
    }
}

stringw Boton::keyToString()
{
    if(teclado==irr::KEY_KEY_Q)
        return "Q";
    if(teclado==irr::KEY_KEY_W)
        return "W";
    if(teclado==irr::KEY_KEY_E)
        return "E";
    if(teclado==irr::KEY_KEY_R)
        return "R";
    if(teclado==irr::KEY_KEY_T)
        return "T";
    if(teclado==irr::KEY_KEY_Y)
        return "Y";
    if(teclado==irr::KEY_KEY_U)
        return "U";
    if(teclado==irr::KEY_KEY_I)
        return "I";
    if(teclado==irr::KEY_KEY_O)
        return "O";
    if(teclado==irr::KEY_KEY_P)
        return "P";
    if(teclado==irr::KEY_KEY_A)
        return "A";
    if(teclado==irr::KEY_KEY_S)
        return "S";
    if(teclado==irr::KEY_KEY_D)
        return "D";
    if(teclado==irr::KEY_KEY_F)
        return "F";
    if(teclado==irr::KEY_KEY_G)
        return "G";
    if(teclado==irr::KEY_KEY_H)
        return "H";
    if(teclado==irr::KEY_KEY_J)
        return "J";
    if(teclado==irr::KEY_KEY_K)
        return "K";
    if(teclado==irr::KEY_KEY_L)
        return "L";
    if(teclado==irr::KEY_KEY_Z)
        return "Z";
    if(teclado==irr::KEY_KEY_X)
        return "X";
    if(teclado==irr::KEY_KEY_C)
        return "C";
    if(teclado==irr::KEY_KEY_V)
        return "V";
    if(teclado==irr::KEY_KEY_B)
        return "B";
    if(teclado==irr::KEY_KEY_N)
        return "N";
    if(teclado==irr::KEY_KEY_M)
        return "M";
    return "error!";
}

bool Boton::usaJoystick()
{
    return usando_joystick;
}

int Boton::getNumJoystick()
{
    return num_joystick;
}
