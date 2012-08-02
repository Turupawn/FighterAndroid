#include "Input/Receiver.h"

Receiver::Receiver()
{
up=down=left=right=a=b=false;
//    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
//        KeyIsDown[i] = false;
      for (int i = 0; i <= KEY_KEY_CODES_COUNT; i++)
      {
         keyState[i] = UP;
      }

}

bool Receiver::OnEvent(const SEvent& event)
{
    // Remember whether each key is down or up
//    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
//        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

      bool eventprocessed = false;

      //////////////////////////////
      // Keyboard Input Event
      //////////////////////////////
      if (event.EventType == EET_KEY_INPUT_EVENT)
      {
         if (processState == STARTED)
         {
            // if key is Pressed Down
            if (event.KeyInput.PressedDown == true)
            {
               // If key was not down before
               if (keyState[event.KeyInput.Key] != DOWN)
               {
                  keyState[event.KeyInput.Key] = PRESSED; // Set to Pressed
               }
               else
               {
                  // if key was down before
                  keyState[event.KeyInput.Key] = DOWN; // Set to Down
               }
            }
            else
            {

                  // if the key is down
                  if (keyState[event.KeyInput.Key] != UP)
                  {
                     keyState[event.KeyInput.Key] = RELEASED; // Set to Released
                  }
            }
         }


         eventprocessed = true;
      }
    //Joystick
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
            && event.JoystickEvent.Joystick == 0)
    {
            JoystickState0 = event.JoystickEvent;
            eventprocessed = true;
    }
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
            && event.JoystickEvent.Joystick == 1)
    {
            JoystickState1 = event.JoystickEvent;
            eventprocessed = true;
    }
    return eventprocessed;
}

const SEvent::SJoystickEvent & Receiver::GetJoystickState(void) const
{
    if(joystick==0)
        return JoystickState0;
    if(joystick==1)
        return JoystickState1;
    return JoystickState0;;
}

//bool Receiver::IsKeyDown(EKEY_CODE keyCode) const
//{
//    return KeyIsDown[keyCode];
//}

bool Receiver::IsKeyPressed(char keycode)
{
  if (keyState[(int)keycode] == PRESSED)
  {
     return true;
  }
  else
  {
     return false;
  }
}

bool Receiver::IsKeyDownn(char keycode)
{
  if((keycode==irr::KEY_DOWN || keycode==irr::KEY_KEY_S) && down)
  {
    return true;
  }
  if((keycode==irr::KEY_UP || keycode==irr::KEY_KEY_W) && up)
  {
    return true;
  }
  if((keycode==irr::KEY_LEFT || keycode==irr::KEY_KEY_A) && left)
  {
    return true;
  }
  if((keycode==irr::KEY_RIGHT || keycode==irr::KEY_KEY_D) && right)
  {
    return true;
  }
  if((keycode==irr::KEY_RETURN || keycode==irr::KEY_KEY_U || keycode==irr::KEY_KEY_M) && a)
  {
    return true;
  }
  if((keycode==irr::KEY_KEY_I) && b)
  {
    return true;
  }

  if (keyState[(int)keycode] == DOWN || keyState[(int)keycode] == PRESSED)
  {
     return true;
  }
  else
  {
     return false;
  }
}

bool Receiver::IsJoyDown(int joyCode,int joystick)
{
    this->joystick=joystick;
    const SEvent::SJoystickEvent & joystickData = GetJoystickState();
    moveHorizontal=(f32)GetJoystickState().Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
    moveVertical=(f32)GetJoystickState().Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
    if(moveVertical<0 && joyCode==-2)
        return true;
    if(moveHorizontal<0 && joyCode==-4)
        return true;
    if(moveHorizontal>0 && joyCode==-6)
        return true;
    if(moveVertical>0 && joyCode==-8)
        return true;
    if(joystickData.IsButtonPressed(joyCode))
        return true;
    return false;
}
       // This is used so that the Key States will not be changed during execution of your Main game loop.
       // Place this at the very START of your Main Loop
       void Receiver::endEventProcess()
       {
          processState = ENDED;
       }

       // This is used so that the Key States will not be changed during execution of your Main game loop.
       // Place this function at the END of your Main Loop.
       void Receiver::startEventProcess()
       {

          processState = STARTED;
          //Keyboard Key States
          for (int i = 0; i < KEY_KEY_CODES_COUNT; i++)
          {
             if (keyState[i] == RELEASED)
             {
                keyState[i] = UP;
             }

             if (keyState[i] == PRESSED)
             {
                keyState[i] = DOWN;
             }
          }

       }
