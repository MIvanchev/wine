/*
 * Wine X11DRV XComposite interface
 *
 * Copyright 2007 Chris Robinson
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */
#ifndef __WINE_XCOMPOSITE_H
#define __WINE_XCOMPOSITE_H

#ifndef __WINE_CONFIG_H
# error You must include config.h to use this header
#endif

#ifdef HAVE_LIBXCOMPOSITE

#include <X11/extensions/Xcomposite.h>
#define pXCompositeQueryExtension             XCompositeQueryExtension
#define pXCompositeQueryVersion               XCompositeQueryVersion
#define pXCompositeVersion                    XCompositeVersion
#define pXCompositeRedirectWindow             XCompositeRedirectWindow
#define pXCompositeRedirectSubwindows         XCompositeRedirectSubwindows
#define pXCompositeUnredirectWindow           XCompositeUnredirectWindow
#define pXCompositeUnredirectSubwindows       XCompositeUnredirectSubwindows
#define pXCompositeCreateRegionFromBorderClip XCompositeCreateRegionFromBorderClip
#define pXCompositeNameWindowPixmap           XCompositeNameWindowPixmap

#endif /* defined(HAVE_LIBXCOMPOSITE) */
#endif /* __WINE_XCOMPOSITE_H */
