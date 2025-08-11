package com.ascendancy.rts;

import android.app.Activity;
import android.os.Bundle;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class MainActivity extends Activity {
    static { System.loadLibrary("ascendancy"); }

    private SurfaceView surface;

    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        surface = new SurfaceView(this);
        setContentView(surface);
        surface.getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override public void surfaceCreated(SurfaceHolder holder) { nativeOnCreate(holder.getSurface()); }
            @Override public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) { nativeOnResize(width, height); }
            @Override public void surfaceDestroyed(SurfaceHolder holder) { nativeOnDestroy(); }
        });
    }

    @Override protected void onResume() { super.onResume(); nativeOnResume(); }
    @Override protected void onPause() { nativeOnPause(); super.onPause(); }

    private static native void nativeOnCreate(Object surface);
    private static native void nativeOnResize(int w, int h);
    private static native void nativeOnDestroy();
    private static native void nativeOnResume();
    private static native void nativeOnPause();
}
