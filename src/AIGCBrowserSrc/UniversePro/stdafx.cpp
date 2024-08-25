/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
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
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

// stdafx.cpp : source file that includes just the standard includes
// stdafx.pch will be the pre-compiled header 
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "CosmosEvents.cpp"
#include "TangramXmlParse.cpp"

void DefaultExceptionProcess(JNIEnv *env)
{
	if (env->ExceptionOccurred() != 0) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
}

void DefaultExceptionProcessEx(JNIEnv *env, _TCHAR* errorInfo)
{
	if (env->ExceptionOccurred() != 0) 
	{
		env->ExceptionDescribe();
		env->ExceptionClear();
		if (errorInfo != nullptr)
		{
			OutputDebugString(errorInfo);
		}
	}
}

void ThrowComFail(JNIEnv *env, const char* desc, jint hr)
{
	jclass failClass = env->FindClass("Tangram/COM/ComFailException");
	// call the constructor that takes hr and message
	jmethodID failCons =
		env->GetMethodID(failClass, "<init>", "(ILjava/lang/String;)V");
	if (!desc) {
		desc = "Java/COM Error";
	}
	jstring js = env->NewStringUTF(desc);
	jthrowable fail = (jthrowable)env->NewObject(failClass, failCons, hr, js);
	env->Throw(fail);
}

// if env's are different throw on the 1st env
int CheckEnv(JNIEnv *env1, JNIEnv *env2)
{
	if (env1 != env2) {
		jclass failClass = env1->FindClass("Tangram/COM/WrongThreadException");
		// call the constructor that takes hr and message
		jmethodID failCons =
			env1->GetMethodID(failClass, "<init>", "()V");
		env1->ThrowNew(failClass, "Wrong Thread");
		return 0;
	}
	return 1;
}


/* Get a _TCHAR* from a jstring, string should be released later with JNI_ReleaseStringChars */
const _TCHAR * JNI_GetStringChars(JNIEnv *env, jstring str) {
	const _TCHAR * result = NULL;
#ifdef UNICODE
	/* GetStringChars is not null terminated, make a copy */
	const _TCHAR * stringChars = (_TCHAR *)env->GetStringChars(str, 0);
	int length = env->GetStringLength(str);
	_TCHAR * copy = (_TCHAR *)malloc((length + 1) * sizeof(_TCHAR));
	_tcsncpy(copy, stringChars, length);
	copy[length] = _T('\0');
	env->ReleaseStringChars(str, (const jchar *)stringChars);
	result = copy;
#elif MACOSX
	/* Use UTF on the Mac */
	result = env->GetStringUTFChars(env, str, 0);
#else
	/* Other platforms, use java's default encoding */
	_TCHAR* buffer = NULL;
	if (string_class == NULL)
		string_class = env->FindClass(env, "java/lang/String");
	if (string_class != NULL) {
		if (string_getBytesMethod == NULL)
			string_getBytesMethod = env->GetMethodID(env, string_class, "getBytes", "()[B");
		if (string_getBytesMethod != NULL) {
			jbyteArray bytes = env->CallObjectMethod(env, str, string_getBytesMethod);
			if (!env->ExceptionOccurred()) {
				jsize length = env->GetArrayLength(env, bytes);
				buffer = malloc((length + 1) * sizeof(_TCHAR*));
				env->GetByteArrayRegion(env, bytes, 0, length, (jbyte*)buffer);
				buffer[length] = 0;
			}
			env->DeleteLocalRef(env, bytes);
		}
	}
	if (buffer == NULL) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	result = buffer;
#endif
	return result;
}

/* Release the string that was obtained using JNI_GetStringChars */
void JNI_ReleaseStringChars(JNIEnv *env, jstring s, const _TCHAR* data) {
#ifdef UNICODE
	free((_TCHAR*)data);
#elif MACOSX
	env->ReleaseStringUTFChars(env, s, data);
#else
	free((_TCHAR*)data);
#endif
}
