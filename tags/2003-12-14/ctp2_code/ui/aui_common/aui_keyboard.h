










#ifndef __AUI_KEYBOARD_H__
#define __AUI_KEYBOARD_H__


#include "aui_base.h"
#include "aui_input.h"




#ifdef __AUI_USE_DIRECTX__
enum AUI_KEYBOARD_KEY
{
	AUI_KEYBOARD_KEY_FIRST = 0,
	AUI_KEYBOARD_KEY_INVALID = 0,
	AUI_KEYBOARD_KEY_ESCAPE = DIK_ESCAPE,
	AUI_KEYBOARD_KEY_RETURN = DIK_RETURN,
	AUI_KEYBOARD_KEY_SPACE = DIK_SPACE,
	AUI_KEYBOARD_KEY_TAB = DIK_TAB,
	AUI_KEYBOARD_KEY_LAST
};
#else
enum AUI_KEYBOARD_KEY
{
	AUI_KEYBOARD_KEY_FIRST = 0,
	AUI_KEYBOARD_KEY_INVALID = 0,
	AUI_KEYBOARD_KEY_ESCAPE,
	AUI_KEYBOARD_KEY_RETURN,
	AUI_KEYBOARD_KEY_SPACE,
	AUI_KEYBOARD_KEY_TAB,
	AUI_KEYBOARD_KEY_LAST
};
#endif 




struct aui_KeyboardEvent
{
	uint32	key;	
	BOOL	down;	
	uint32	time;	
};



#define k_KEYBOARD_MAXINPUT		24

#define k_KEYBOARD_MAXSTATE		256



class aui_Keyboard : public aui_Base, public virtual aui_Input
{
public:
	
	aui_Keyboard(
		AUI_ERRCODE *retval );
	virtual ~aui_Keyboard();

protected:
	aui_Keyboard() {}
	AUI_ERRCODE	InitCommon( void );

public:
	
	AUI_ERRCODE			GetKeyboardState( uint8 *keyboardState );
	aui_KeyboardEvent	*GetLatestKeyboardEvent( void ) { return &m_data; }

protected:
	aui_KeyboardEvent m_data;	
	uint8 m_keyboardState[ k_KEYBOARD_MAXSTATE ];
		
};


#endif 