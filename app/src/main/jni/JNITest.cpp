//
// Created by bob.sun on 15/8/24.
//

#include "JNITest.h"

#include <jni.h>
#include "sun_bob_newndktest_JNI.h"

jstring Java_sun_bob_newndktest_JNI_sayMyName(JNIEnv *env, jclass cls){
    return env->NewStringUTF("22333");
}
