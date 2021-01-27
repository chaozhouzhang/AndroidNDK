package android.stack.ndk;

public class Family {
    static {
        System.loadLibrary("family");
    }



    public static native String init(Object context, String str);
}
