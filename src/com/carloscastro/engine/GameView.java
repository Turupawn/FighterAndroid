package com.carloscastro.engine;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.MotionEvent;


public class GameView extends GLSurfaceView {
	  private Game mActivity;
	    private GameEvent lastEvent;

	    public GameView(Game activity) {
	        super(activity);
	        mActivity = activity;
	        mRenderer = new GameRenderer(activity);
	        setRenderer(mRenderer);
	        lastEvent = new GameEvent();
	    }

	    public boolean onTouchEvent(final MotionEvent event) {
	    	
	        lastEvent.mAction = event.getAction();
	        lastEvent.mX = event.getX();
	        lastEvent.mY = event.getY();
	        if (mRenderer!=null) {
		        	//mRenderer.mStatus.down=!mRenderer.mStatus.up;
	            mActivity.nativeSendEvent(lastEvent);
	        }
	        return true;
	    }
	   GameRenderer mRenderer;
}


class GameRenderer implements GLSurfaceView.Renderer {
    private Game mActivity;
    private int mWindowWidth;
    private int mWindowHeight;
    public GameStatus mStatus;

    public GameRenderer(Game activity) {
        mActivity = activity;
        mStatus = new GameStatus();
        mStatus.mQuit = false;
       
    }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        mActivity.nativeInitGL();
        mActivity.nativeInitScene();
    }

    public void onSurfaceChanged(GL10 gl, int width, int height) {
        mWindowWidth = width;
        mWindowHeight = height;
        mActivity.nativeResize(width, height);
    }

    public void onDrawFrame(GL10 gl) {
    	
        Game.nativeDrawIteration(mStatus);
        
        if (mStatus.mQuit) {
            Log.e("Irrlicht", "QUIT");
            mActivity.finish();
        }
    }

}

class GameEvent {
    public int mAction;
    public float mX;
    public float mY;
    
    /*
	public boolean down;
	public boolean up;
	public boolean left;
	public boolean right;
	
	public boolean a;
	public boolean b;
     */
}

class GameStatus {
	public boolean mQuit;
}

