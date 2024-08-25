#pragma once
#include "jniforchrome.h"

/**
* Convert a wide string to a narrow one
* Caller must free the null terminated string returned.
*/
char *toNarrow(const _TCHAR* src)
{
#ifdef UNICODE
	int byteCount = WideCharToMultiByte(CP_ACP, 0, (wchar_t *)src, -1, NULL, 0, NULL, NULL);
	char *dest = (char*)malloc(byteCount + 1);
	dest[byteCount] = 0;
	WideCharToMultiByte(CP_ACP, 0, (wchar_t *)src, -1, dest, byteCount, NULL, NULL);
	return dest;
#else
	return (char*)_tcsdup(src);
#endif
}

/* Get a _TCHAR* from a jstring, string should be released later with JNI_ReleaseStringChars */
static const _TCHAR * JNI_GetStringChars(JNIEnv *env, jstring str) {
	const _TCHAR * result = NULL;
#ifdef UNICODE
	/* GetStringChars is not null terminated, make a copy */
	const _TCHAR * stringChars = (_TCHAR *)env->GetStringChars(str, 0);
	int length = env->GetStringLength(str);
	_TCHAR * copy = (_TCHAR *)malloc((length + 1) * sizeof(_TCHAR));
	_tcsncpy_s(copy, (length + 1) * sizeof(_TCHAR),stringChars, length);
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
static void JNI_ReleaseStringChars(JNIEnv *env, jstring s, const _TCHAR* data) {
#ifdef UNICODE
	free((_TCHAR*)data);
#elif MACOSX
	env->ReleaseStringUTFChars(env, s, data);
#else
	free((_TCHAR*)data);
#endif
}

jstring newJavaString(JNIEnv *env, _TCHAR * str)
{
	jstring newString = NULL;
#ifdef UNICODE
	size_t length = _tcslen(str);
	newString = env->NewString((const jchar*)str, length);
#elif MACOSX
	newString = env->NewStringUTF(env, str);
#else
	size_t length = _tcslen(str);
	jbyteArray bytes = env->NewByteArray(env, length);
	if (bytes != NULL) {
		env->SetByteArrayRegion(env, bytes, 0, length, (jbyte *)str);
		if (!env->ExceptionOccurred()) {
			if (string_class == NULL)
				string_class = env->FindClass(env, "java/lang/String");
			if (string_class != NULL) {
				if (string_ctor == NULL)
					string_ctor = env->GetMethodID(env, string_class, "<init>", "([B)V");
				if (string_ctor != NULL) {
					newString = env->NewObject(env, string_class, string_ctor, bytes);
				}
			}
		}
		env->DeleteLocalRef(env, bytes);
	}
#endif
	if (newString == NULL) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	return newString;
}

