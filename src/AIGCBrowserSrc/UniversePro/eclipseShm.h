/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

/*******************************************************************************
 * Copyright (c) 2000, 2009 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *     Silenio Quarti
 *******************************************************************************/

#ifndef ECLIPSE_SHM_H
#define ECLIPSE_SHM_H

/* Shared memory utilities */

/**
 * Creates and initializes a shared memory segment
 * with the specified size in bytes. The id for the
 * shared memory segment is stored in the id argument
 * and can be used from any process. It must be freed
 * with free().
 *
 * Returns 0 if success.
 */
extern int createSharedData(_TCHAR** id, int size);

/**
 * Destroy the shared memory segment specified by the
 * id argument. The id is the same as the one return
 * by createSharedData(). This function must be called
 * by the same process that created the segment.
 *
 * Returns 0 if success.
 */
extern int destroySharedData(_TCHAR* id);

/**
 * Gets a copy of the shared memory segment specified
 * by the id argument. The copy is stored in the data
 * argument as a null terminated string and must be
 * freed by free().
 *
 * Returns 0 if success.
 */
extern int getSharedData(_TCHAR* id, _TCHAR** data);

/**
 * Sets the shared memory segment specified by the id
 * argument with a null terminated string specified by
 * data.
 *
 * Returns 0 if sucess.
 */
extern int setSharedData(const _TCHAR* id, const _TCHAR* data);

#endif /* ECLIPSE_SHM_H */


