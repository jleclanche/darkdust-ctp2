










 


#pragma once
#ifndef __FACEDSPRITEWSHADOW_H__
#define __FACEDSPRITEWSHADOW_H__

#define k_MAX_FACINGS		8
#define k_NUM_FACINGS		5

#define k_MAX_NAMES			100
#define k_MAX_NAME_LENGTH	_MAX_PATH

#include "Sprite.h"

class Token;
class aui_DirectSurface;

class FacedSpriteWshadow : public Sprite {
public:
	FacedSpriteWshadow();
	~FacedSpriteWshadow();

	void			Import(uint16 nframes, char *files[k_NUM_FACINGS][k_MAX_NAMES], char *shadowFiles[k_NUM_FACINGS][k_MAX_NAMES]);
	void			Import(uint16 nframes, char *files[k_NUM_FACINGS][k_MAX_NAMES]);
	
	void			Load(char *filename);

	void			Draw(sint32 drawX, sint32 drawY, sint32 facing, double m_scale, sint16 transparency, 
							Pixel16 outlineColor, uint16 flags);

	void			DrawDirect(aui_Surface *surf, sint32 drawX, sint32 drawY, sint32 facing, double m_scale, sint16 transparency, 
						Pixel16 outlineColor, uint16 flags);

	void			DirectionalDraw(sint32 drawX, sint32 drawY, sint32 facing,
					   double scale, sint16 transparency, Pixel16 outlineColor, uint16 flags);

	void			DrawShadow(sint32 SdrawX, sint32 SdrawY, sint32 facing, double m_scale, sint16 transparency, 
						Pixel16 outlineColor, uint16 flags);

	void			DirectionalDrawShadow(sint32 drawX, sint32 drawY, sint32 facing,
					   double scale, sint16 transparency, Pixel16 outlineColor, uint16 flags);

	void			DrawFlashEffect(sint32 drawX, sint32 drawY, sint32 facing, double m_scale, sint16 transparency, 
						Pixel16 outlineColor, uint16 flags);

	Pixel16			*GetFrameData(uint16 facing, uint16 frame) { return m_frames[facing][frame]; }
	Pixel16			*GetMiniFrameData(uint16 facing, uint16 frame) { return m_miniframes[facing][frame]; }

	void			SetFrameData(uint16 facing, uint16 frame, Pixel16 *data) { m_frames[facing][frame] = data; }
	void			SetMiniFrameData(uint16 facing, uint16 frame, Pixel16 *data) { m_miniframes[facing][frame] = data; }
	
	Pixel16			*GetShadowFrameData(uint16 facing, uint16 frame) { return m_shadowFrames[facing][frame]; }
	Pixel16			*GetMiniShadowFrameData(uint16 facing, uint16 frame) { return m_miniShadowFrames[facing][frame]; }
	
	void			SetShadowFrameData(uint16 facing, uint16 frame, Pixel16 *data) { m_shadowFrames[facing][frame] = data; }
	void			SetMiniShadowFrameData(uint16 facing, uint16 frame, Pixel16 *data) { m_miniShadowFrames[facing][frame] = data; }

	POINT			GetHotPoint(uint16 facing) { return m_hotPoints[facing]; }
	POINT			*GetHotPoints(void) { return m_hotPoints; }

	void			SetHotPoint(uint16 facing, sint32 x, sint32 y) { m_hotPoints[facing].x = x; m_hotPoints[facing].y = y; }
	void			SetHotPoints(POINT *points) { memcpy(m_hotPoints, points, sizeof(m_hotPoints)); }

	sint32			ParseFromTokens(Token *theToken);
	void			AllocateFrameArrays(void);

	void			SetHasShadow(BOOL val) { m_hasShadow = val; }
	BOOL			GetHasShadow() { return m_hasShadow; }

protected:
	Pixel16			**m_frames[k_NUM_FACINGS];
	Pixel16			**m_miniframes[k_NUM_FACINGS];
	
	Pixel16			**m_shadowFrames[k_NUM_FACINGS];
	Pixel16			**m_miniShadowFrames[k_NUM_FACINGS];

	uint16			m_hasShadow;

	POINT			m_hotPoints[k_NUM_FACINGS];
};

#endif