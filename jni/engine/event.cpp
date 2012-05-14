
#include "event.h"



bool EventReceiver::OnEvent(const irr::SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

	return false;
}

bool EventReceiver::IsKeyDown(int keyCode) const
{
	return KeyIsDown[keyCode];
}
	
EventReceiver::EventReceiver()
{
	for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}