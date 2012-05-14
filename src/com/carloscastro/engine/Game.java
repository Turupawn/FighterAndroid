package com.carloscastro.engine;


import java.io.IOException;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;

public class Game extends Activity {
	 private GameView gameView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		/*try {
	        Utils.unpackOnSdCard(getAssets());
	    } catch (IOException e) {
	        Log.i("Irrlicht", "Error in unpack");
	    }*/
		
	    nativeEnvJ2C(Environment.getExternalStorageDirectory().getAbsolutePath());
        gameView = new GameView(this);
        setContentView(gameView);
        nativeOnCreate();
		
	}
	
	 @Override
	    protected void onPause() {
	        super.onPause();
	        gameView.onPause();
	        nativeOnPause();
	    }

	    @Override
	    protected void onResume() {
	        super.onResume();
	        gameView.onResume();
	        nativeOnResume();
	    }

	    @Override    
	    public void onDestroy() {
	        nativeOnDestroy();
	        super.onDestroy();
	    }

	    /** load irrlicht.so */
	    static {
	        System.loadLibrary("irrlicht");
	    }
	
	
	    public native void nativeOnCreate();
	    public native void nativeOnPause();
	    public native void nativeOnResume();
	    public native void nativeOnDestroy();

	    public native void nativeInitGL();
	    public native void nativeResize(int w, int h);

	    public native void nativeGetStatus(GameStatus status);
	    public native void nativeSendEvent(GameEvent event);
	    public native void nativeEnvJ2C(String sdcardPath);

	    public static native void nativeDrawIteration(GameStatus status);
	    public native void nativeInitScene();
}
