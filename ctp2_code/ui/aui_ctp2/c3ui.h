












#pragma once
#ifndef __C3UI_H__
#define __C3UI_H__


#include "aui_directui.h"
#include "pattern.h"		
#include "icon.h"			
#include "picture.h"		
#include "aui_resource.h"	
#include "aui_window.h"



class C3UI : public aui_DirectUI
{
public:
	
	C3UI(
		AUI_ERRCODE *retval,
		HINSTANCE hinst,
		HWND hwnd,
		sint32 width,
		sint32 height,
		sint32 bpp,
		MBCHAR *ldlFilename = NULL,
		BOOL useExclusiveMode = FALSE );
	virtual ~C3UI();

	
	aui_Resource<Pattern>	*GetPatternResource( void ) const { return m_patternResource; }

	Pattern	*LoadPattern( MBCHAR *name )
		{ return m_patternResource->Load( name ); }

	AUI_ERRCODE	UnloadPattern( Pattern *resource )
		{ return m_patternResource->Unload( resource ); }
	AUI_ERRCODE	UnloadPattern( MBCHAR *name )
		{ return m_patternResource->Unload( name ); }

	AUI_ERRCODE	AddPatternSearchPath( MBCHAR *path )
		{ return m_patternResource->AddSearchPath( path ); }
	AUI_ERRCODE	RemovePatternSearchPath( MBCHAR *path )
		{ return m_patternResource->RemoveSearchPath( path ); }

	
	aui_Resource<Icon>	*GetIconResource( void ) const { return m_iconResource; }

	Icon	*LoadIcon( MBCHAR *name )
		{ return m_iconResource->Load( name ); }

	AUI_ERRCODE	UnloadIcon( Icon *resource )
		{ return m_iconResource->Unload( resource ); }
	AUI_ERRCODE	UnloadIcon( MBCHAR *name )
		{ return m_iconResource->Unload( name ); }

	AUI_ERRCODE	AddIconSearchPath( MBCHAR *path )
		{ return m_iconResource->AddSearchPath( path ); }
	AUI_ERRCODE	RemoveIconSearchPath( MBCHAR *path )
		{ return m_iconResource->RemoveSearchPath( path ); }

	
	aui_Resource<Picture>	*GetPictureResource( void ) const { return m_pictureResource; }

	Picture	*LoadPicture( MBCHAR *name )
		{ return m_pictureResource->Load( name ); }

	AUI_ERRCODE	UnloadPicture( Picture *resource )
		{ return m_pictureResource->Unload( resource ); }
	AUI_ERRCODE	UnloadPicture( MBCHAR *name )
		{ return m_pictureResource->Unload( name ); }

	AUI_ERRCODE	AddPictureSearchPath( MBCHAR *path )
		{ return m_pictureResource->AddSearchPath( path ); }
	AUI_ERRCODE	RemovePictureSearchPath( MBCHAR *path )
		{ return m_pictureResource->RemoveSearchPath( path ); }

	BOOL TopWindowIsNonBackground(void);

protected:
	aui_Resource<Pattern>	*m_patternResource;
	aui_Resource<Icon>		*m_iconResource;
	aui_Resource<Picture>	*m_pictureResource;
};


#endif 