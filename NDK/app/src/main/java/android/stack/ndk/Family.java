package android.stack.ndk;

public class Family {
    static {
        System.loadLibrary("family");
    }



    public static native void init(Object context);
}
