package android.stack.ndk;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

/**
 * @author zhangchaozhou
 */
public class MainActivity extends AppCompatActivity {

    private final String str = "123abcABC*%!~#+_/中文测试";
    private final String encode = "SkiDk/JC5F/BXKf/np7rWNub7ibxzYMjKwkQ7A6AqPw=";

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        tv.append(String.valueOf(plus(1, 99)));
        tv.append("\n");

        String secret = AESEncrypt.encode(this, str);
        Log.i("secret", secret + "");
        tv.append("加密结果："+secret+"\n");
        String src = AESEncrypt.decode(this, encode);
        tv.append("解密结果："+src+"\n");
        Log.i("src", src + "");

        System.out.println(SignatureTool.getSignature(this));

        Family.init(this);


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    public static native int plus(int a, int b);
}
