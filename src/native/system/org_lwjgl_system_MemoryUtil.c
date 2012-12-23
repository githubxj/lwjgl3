/*
 * Copyright LWJGL. All rights reserved.
 * License terms: http://lwjgl.org/license.php
 */
#include <jni.h>

// memPointerSize()I
JNIEXPORT jint JNICALL Java_org_lwjgl_system_MemoryUtil_memPointerSize(JNIEnv *env, jclass clazz)
{
	return (jint)sizeof(void *);
}

// memSet(JIJ)V
JNIEXPORT void JNICALL Java_org_lwjgl_system_MemoryUtil_nMemSet(JNIEnv *env, jclass clazz,
	jlong address, jint value, jlong bytes
) {
	memset((void *)(intptr_t)address, value, (size_t)bytes);
}

// memSet(JJJ)V
JNIEXPORT void JNICALL Java_org_lwjgl_system_MemoryUtil_nMemCopy(JNIEnv *env, jclass clazz,
	jlong dst, jlong src, jlong bytes
) {
	memcpy((void *)(intptr_t)dst, (const void *)(intptr_t)src, (size_t)bytes);
}

// nGetAddress(Ljava/nio/Buffer;)J
JNIEXPORT jlong JNICALL Java_org_lwjgl_system_MemoryUtil_nGetAddress(JNIEnv *env, jclass clazz,
	jobject buffer
) {
	return (jlong)(intptr_t)(*env)->GetDirectBufferAddress(env, buffer);
}

// nNewBuffer(JJ)Ljava/nio/ByteBuffer;
JNIEXPORT jobject JNICALL Java_org_lwjgl_system_MemoryUtil_nNewBuffer(JNIEnv *env, jclass clazz,
	jlong address, jint capacity
) {
	return (*env)->NewDirectByteBuffer(env, (void *)(intptr_t)address, capacity);
}