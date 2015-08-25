package sun.bob.newndktest;

/**
 * Created by bob.sun on 15/8/24.
 */
public class JNI {
    static{
        System.loadLibrary("JNITest");
    }

    public static native String sayMyName();
}
