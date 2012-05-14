
#ifndef _GE_EVENT_
#define _GE_EVENT_

#include <irrlicht.h>

class EventReceiver : public irr::IEventReceiver
{
public:
	virtual bool OnEvent(const irr::SEvent& event);

	virtual bool IsKeyDown(int keyCode) const;
	
	EventReceiver();

private:
	bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};


#endif