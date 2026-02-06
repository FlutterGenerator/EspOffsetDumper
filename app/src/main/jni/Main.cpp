#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
// armeabi-v7a
#include "KittyMemory/MemoryPatch.h"
// arm64-v8a
#include "And64InlineHook/And64InlineHook.hpp"
#include "Menu.h"
#include "NepAU/AutoUpdate.cpp"

using namespace NepSymbol;
#include "Offset.h"
#include <sstream>

//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

using namespace std;

std::string int2Hex(unsigned int intVal)
{
    std::string hexStr;

    /// integer value to hex
    std::stringstream sstream;
    sstream << std::hex << intVal;

    hexStr= sstream.str();
    sstream.clear();    //clears out the stream-string

    std::transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);

    return std::string("0x") + hexStr;
}
const char *AddCopyButton(unsigned int Offset) {
       char const* word = "COPYBUTTON_";
       char const* worb = int2Hex(Offset).c_str();
    
       char *s = new char[strlen(word)+strlen(worb)+1];
       strcpy(s,word);
       strcat(s,worb);
    
        return s;
    }
const char *join(const char *a, const char *b) {
        char buffer[128] = {0};
        sprintf(buffer, "%s %s", a, b);
        return (buffer);
}

void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));
LOGD("TheAddresa: %p", 0x98);

    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));
        getAddress();
    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);
    
#if defined(__aarch64__)
#else
#endif

    return NULL;
}
extern "C" {
    
    
JNIEXPORT jobjectArray
JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    
    jobjectArray ret;

    MakeToast(env, context, OBFUSCATE("Esp Offset Dummping..."), Toast::LENGTH_LONG);
    const char *features[] = {
      
        OBFUSCATE("Category_OFFSETS"), //Not counted
        
        
        OBFUSCATE("RichTextView_<b>Transform</b> - >>"),
        AddCopyButton(_Transform.getOffset()),
        
        
        OBFUSCATE("Category_GetPositionInjected index 0"), //Not counted
        // Unity old and New GetPositionInjected
        OBFUSCATE("RichTextView_<b>GetPositionInjected</b> - >>"),
        AddCopyButton(_GetPositionInjected0.getOffset()),
        
        
        OBFUSCATE("Category_GetPositionInjected index 1"), //Not counted
        // Unity old and New GetPositionInjected
        OBFUSCATE("RichTextView_<b>GetPositionInjected</b> - >>"),
        AddCopyButton(_GetPositionInjected1.getOffset()),
        
        
        OBFUSCATE("Category_GetPositionInjected index 2"), //Not counted
        // Unity old and New GetPositionInjected
        OBFUSCATE("RichTextView_<b>GetPositionInjected</b> - >>"),
        AddCopyButton(_GetPositionInjected2.getOffset()),
        
        
        OBFUSCATE("Category_GetPositionInjected index 3"), //Not counted
        // Unity old and New GetPositionInjected
        OBFUSCATE("RichTextView_<b>GetPositionInjected</b> - >>"),
        AddCopyButton(_GetPositionInjected3.getOffset()),
        
        
        OBFUSCATE("Category_WorldToScreenPointIntInjected index"), //Not counted
        // Unity old and New WorldToScreenPointIntInjected
        OBFUSCATE("RichTextView_<b>WorldToScreenPointIntInjected</b> - >>"),
        AddCopyButton(_WorldToScreenPointIntInjected.getOffset()),
        
        
        OBFUSCATE("Category_WorldToScreenPointIntInjected index 0"), //Not counted
        // Unity old and New WorldToScreenPointIntInjected
        OBFUSCATE("RichTextView_<b>WorldToScreenPointIntInjected</b> - >>"),
        AddCopyButton(_WorldToScreenPointIntInjected0.getOffset()),
        
        
        OBFUSCATE("Category_WorldToScreenPointIntInjected index 1"), //Not counted
        // Unity old and New WorldToScreenPointIntInjected
        OBFUSCATE("RichTextView_<b>WorldToScreenPointIntInjected</b> - >>"),
        AddCopyButton(_WorldToScreenPointIntInjected1.getOffset()),
        
        
        OBFUSCATE("Category_WorldToScreenPointIntInjected index 2"), //Not counted
        // Unity old and New WorldToScreenPointIntInjected
        OBFUSCATE("RichTextView_<b>WorldToScreenPointIntInjected</b> - >>"),
        AddCopyButton(_WorldToScreenPointIntInjected2.getOffset()),
        
        
        OBFUSCATE("Category_WorldToScreenPointIntInjected index 3"), //Not counted
        // Unity old and New WorldToScreenPointIntInjected
        OBFUSCATE("RichTextView_<b>WorldToScreenPointIntInjected</b> - >>"),
        AddCopyButton(_WorldToScreenPointIntInjected3.getOffset()),
        
        
        OBFUSCATE("Category_WorldToScreenPointIntInjected index 4"), //Not counted
        // Unity old and New WorldToScreenPointIntInjected
        OBFUSCATE("RichTextView_<b>WorldToScreenPointIntInjected</b> - >>"),
        AddCopyButton(_WorldToScreenPointIntInjected4.getOffset()),
        
        
        //Camera
        OBFUSCATE("RichTextView_<b>Camera</b> - >>"),
        AddCopyButton(_Camera.getOffset()),
        
        
        //ButtonLink
        OBFUSCATE("ButtonLink_<b>TELEGRAM</b>_https://t.me/CheaterNeverDies"),
        
        
         };
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_com_NepEsp_Offsetdummper_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");
    }
}
__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

