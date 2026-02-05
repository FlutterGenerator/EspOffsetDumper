bool titleValid, headingValid, iconValid, settingsValid, isLeeched;

void *antiLeech(void *) {
    sleep(20);

    if (!titleValid || !headingValid || !iconValid || !settingsValid) {
        int *p = 0;
        *p = 0;
    }
    return NULL;
}
const char *copyText;
const char *copy() {
    return copyText;
}
bool copy(const char *t) {
    copyText = t;
    return true;
}

void setText(JNIEnv *env, jobject obj, const char* text){
    //https://stackoverflow}.com/a/33627640/3763113
    //A little JNI calls here. You really really need a great knowledge if you want to play with JNI stuff
    //Html.fromHtml("");
    jclass html = (*env).FindClass(OBFUSCATE("android/text/Html"));
    jmethodID fromHtml = (*env).GetStaticMethodID(html, OBFUSCATE("fromHtml"), OBFUSCATE("(Ljava/lang/String;)Landroid/text/Spanned;"));

    //setText("");
    jclass textView = (*env).FindClass(OBFUSCATE("android/widget/TextView"));
    jmethodID setText = (*env).GetMethodID(textView, OBFUSCATE("setText"), OBFUSCATE("(Ljava/lang/CharSequence;)V"));

    //Java string
    jstring jstr = (*env).NewStringUTF(text);
    (*env).CallVoidMethod(obj, setText,  (*env).CallStaticObjectMethod(html, fromHtml, jstr));
}

extern "C" {
JNIEXPORT void JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_setTitleText(JNIEnv *env, jobject thiz, jobject obj) {
    setText(env, obj, OBFUSCATE("<b>NEPMODS</b>"));

    titleValid = true;
}

JNIEXPORT void JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_setHeadingText(JNIEnv *env, jobject thiz, jobject obj) {
    setText(env, obj, OBFUSCATE("Esp - Offset Dumper"));

    headingValid = true;
}

JNIEXPORT jstring JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_Icon(JNIEnv *env, jobject thiz) {
    iconValid = true;

    //Use https://www.base64encode.org/ to encode your image to base64
    return env->NewStringUTF(
            OBFUSCATE("iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAMAAACdt4HsAAACKFBMVEUAAADr64n3+Ez8/Rbh4T3f6X/7/BXm6e/Z3OHm6u7d4OXa2v/m6e/c3uTU6en//wD7+wTr6xHW1iPV1STZ2SL+/wby84Xp7N3p7Nfy9H/y9H7u8Kzn6u/t77fy84bp7Nzp697q7Nbp7Nrp7Nvy84Py9IHy9IL+/gfy84Tp7Nn//wXt77jY2+Dn6e75Ozz/AAD5PD3strrst7v0aGr0aWv8HB38GxvsuLvo4ufn5uvupqr7Kyz6LS7uqq3m4+jo3uLrxMn+DQ3+CQn6NTb1ZmjwlpnsuLz4Rkf3SUvwlZjjREbWHx/NGBjOGRnmqK34QUPxBwfLGRnXIiPuoqbbERHjen3o5On7IyT4AwPMGBjSGhvo3+PyfoD1SUvit7vb2Nzb3eHnyM3xhIf7KCnjDg7gUFHp2+D9Dg7iur/Y2+Hh5Onn5+zxh4r+Bgb8AQHOGBjm0NXp1Nn+Bwfe0NXj5uvtrbD9AQHQFxfmw8fuo6f/AwPiur7xhoncERHjcnTxi471SUrb3eL7JyfiDg7gVlf0a27iuLzygYTnCwveP0D9Fxfb193l5+3rwcX6AgLQGRnm6u/o3eLo3OHNGRn9FhbrwMTn6O3g5OnygILePkD7JibhVVfiub3yg4bjcXPdz9Tj5+vtq67/BQXmwsf9DAzyf4H1RUfjtbjb1tzZ2+Dc2+Hmyc3hUVLaEhL4QkP1ZWf4SEno4+fuqKz0amzm6O7f4+jl6O7Y3OE5R38yAAAAD3RSTlMADcj88xj95vyJxgflxwzTp5BnAAAClUlEQVRYw2NgGASAkYmZn2QgICgkLMLCCjaAiZ8sICgsLMwCNoCNPAMEgAaIgA3gJxMADRCGGyAqJi4hKYpKS4nClErLYAGyKAaIgYQk+fnlQLQUgoYAGawAxQB5kIgEP78CiFbk5xeH0qQZIA/VqATlK5NggApIRAXqFVUorUaCAeoamuJiWkBaTElcA4mGAG1s+rVRDKA4Goe4ATJkAh0gGPYG6Orpg4GBLpkGGOpDgRGZBhjDDDAhzwBdU5gBZrpkGQD3gb6+OUkGWFiCKStrhAE2tmAhO3tiDHBwdHJ2cXVz10cBHm6eXt4+vn5EGOCvjwMEBAYGBhE2IFgfJwgBmhBKyICwcNwGREQGBkZFEzAgBllHbFy8TkJiUjKMnwJ0Qip+A9IcEdrTM3R0MrOAgtk5uRCRvPzAQN8CvAYUFiH0FwMVlECESyEmlJUHBvpU4PdCZRXMgGqgfBZMuAYsVAv0Qh2hWKiH6m8ASjfCRbObgELNQP0thNNBK8SANmQHyMi06+t3APV3EpGQdLvABnQDpXsQor36fUD9/dnE5AUnsAEg6QkIwYn6ZUADfGTINmAS2IDJxBigOwVsQDyqF6ZCvDBNhuhAjANKT0eIzoAE4kzCBmCPRstZ0GicTciAYHhCmoPshLnwhDRPhuikPB+YFRZAhBcuQiTlxXgNmISUmZYA01ImyA3ZSYuIzkwyS5Gz87LlK1auWt3eBOODAmENrQsUmUrcBqwlpkiTkVlHYaEKLtbXe7p5oOre4OZKbLEusxFSsSy0QWi33gSpWKLpU7VRrXKVMYEZsJnM9oERXh8Q08QxoLCJM3Saeezk6d8C1M8BNoCTPAO2Ag3gAhvAzclDuvZtW7frcPDyDYauOwB+O/BAojvtDwAAAABJRU5ErkJggg=="));
             }
JNIEXPORT jstring JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_copy(JNIEnv *env, jobject thiz) {
    iconValid = true;
    const char *cText = copy();
    copy(NULL);
    //Use https://www.base64encode.org/ to encode your image to base64
    return env->NewStringUTF(cText);
}
JNIEXPORT jboolean JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_isCopy(JNIEnv *env, jobject thiz) {

    //Use https://www.base64encode.org/ to encode your image to base64
    return copy() != NULL;
}
JNIEXPORT jstring JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_IconWebViewData(JNIEnv *env, jobject thiz) {
    iconValid = true;
    //WebView support GIF animation. Upload your image or GIF on imgur.com or other sites

    // From internet (Requires android.permission.INTERNET)
    // return env->NewStringUTF(OBFUSCATE("https://i.imgur.com/SujJ85j.gif"));

    // Base64 html:
    // return env->NewStringUTF("data:image/png;base64, <encoded base64 here>");

    // To disable it, return NULL. It will use normal image above:
    // return NULL

    //return env->NewStringUTF(OBFUSCATE_KEY("https://i.imgur.com/SujJ85j.gif", 'u'));
    return NULL;
}

JNIEXPORT jobjectArray JNICALL
Java_com_NepEsp_Offsetdummper_FloatingModMenuService_settingsList(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_Settings"),
            OBFUSCATE("-1_Toggle_Save feature"), //-1 is checked on Preferences.java
            OBFUSCATE("-3_Toggle_Auto size vertically"),
            OBFUSCATE("Category_Credit"),
            OBFUSCATE("RichTextView_<b>Dev by</b> : <font color='#FF0000'><b>@nepmods</b></font>"),
            OBFUSCATE("RichTextView_<b>Telegram</b> : <font color='#FF0000'><b>@CheaterNeverDies</b></font>"),
            OBFUSCATE("-7_ButtonLink_CONTANT_https://t.me/YourAnnonOne"),
            OBFUSCATE("Category_Menu"),
            OBFUSCATE("-6_Button_<font color='red'>Close settings</font>"),
    };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    settingsValid = true;

    return (ret);
}
}
